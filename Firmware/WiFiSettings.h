#ifndef _WIFISETTINGS_h
#define _WIFISETTINGS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <memory>

using namespace std;

void WiFiSettingsSetup();
void WiFiSettingsLoop();

#endif

