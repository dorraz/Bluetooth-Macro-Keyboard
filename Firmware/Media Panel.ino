#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <map>
#include <iostream>
#include <memory>

#include <FS.h>
#include <SPIFFS.h>

#include <ArduinoJson.h>

#include <WiFi.h>
#include <ESPmDNS.h>
#include <DNSServer.h>

#include <BleKeyboard.h>
#include <PCF8574.h>

#include "Communicator.h"
#include "MacroButton.h"
#include "WiFiSettings.h"

using namespace std;


constexpr int _port = 23232;
/**
* @brief Communication (streaming) object used to send/receive protocol commands.
*/
Communicator _communicator(_port);

/**
 * @brief What we are here in for - macro buttons
*/
std::map<int, std::shared_ptr<MacroButton>> _buttons;

void setup() 
{

    Serial.begin(115200); // Monitoring
    while (!Serial) { ; } // wait for serial port to connect. Needed for native USB port only

    esp_log_level_set("*", ESP_LOG_NONE);

    Serial.println("");
    Serial.println("-------------------");
    Serial.println("Media Panel boot");
    Serial.println("-------------------");

    if (!SPIFFS.begin())
    {
        Serial.println("SPIFFS mount error");
        return;
    }
    Serial.println("SPIFFS mount success.");

    WiFiSettingsSetup();
}

void loop()
{
    // WiFi resources
    WiFiSettingsLoop();

}
