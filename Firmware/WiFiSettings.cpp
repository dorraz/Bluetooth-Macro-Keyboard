#include "WiFiSettings.h"


#include <WiFi.h>
#include <DNSServer.h>
#include <SPIFFS.h>
#include <FS.h>

#include <map>
#include <iostream>

// Settings access point mode parameters
auto constexpr Ssid = "MediaPanel";
auto constexpr DnsHostName = "MediaPanel"; // Default hostname for mDNS. Should work at least on windows.
auto constexpr DnsPort = 53;
auto constexpr Ip = "10.1.1.1";
auto constexpr Netmask = "255.255.255.0";

// Address resolving
std::shared_ptr<DNSServer> _dnsServer = nullptr;


void WiFiSettingsSetup()
{
	Serial.println("Starting access point/settings mode.");

	IPAddress ipAddress;
	ipAddress.fromString(Ip);
	IPAddress netmask;
	netmask.fromString(Netmask);

	WiFi.mode(WIFI_AP);
	delay(2000);
	WiFi.softAPConfig(ipAddress, ipAddress, netmask);
	if (!WiFi.softAP(Ssid)) // Free access
	{
		Serial.println("Access Point setup failure");
		ESP.restart();
	}

	Serial.println("Settings DNS redirection.");
	_dnsServer = std::make_shared<DNSServer>();
	_dnsServer->setErrorReplyCode(DNSReplyCode::NoError);
	_dnsServer->start(DnsPort, "*", ipAddress);

	Serial.write("Waiting for client to connect...");
}

void WiFiSettingsLoop()
{
	static auto connectedStations = 0;

	if (WiFi.softAPgetStationNum() > 0)
	{
		if (_dnsServer != nullptr)
			_dnsServer->processNextRequest();

		if (connectedStations != WiFi.softAPgetStationNum())
		{
			if (connectedStations > WiFi.softAPgetStationNum())
				Serial.println("Station connected");
			else if (connectedStations < WiFi.softAPgetStationNum())
				Serial.println("Station disconnected");
			connectedStations = WiFi.softAPgetStationNum();

			Serial.println();
			Serial.printf("AP Stations connected: %d\n", WiFi.softAPgetStationNum());
			Serial.print("AP IP: ");
			Serial.println(WiFi.softAPIP());
			Serial.println("AP MAC:" + WiFi.softAPmacAddress());
			Serial.printf("AP SSID: %s\n", Ssid);
		}
	}
}
