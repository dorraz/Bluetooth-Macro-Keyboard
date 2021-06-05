#ifndef UUID
#define UUID

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <iostream>

void UUIDGen(char* returnUUID);
String UUIDGenString();

#endif