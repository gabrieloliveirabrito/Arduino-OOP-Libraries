#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define DEBUG				1
#define OSCILATION_LEVEL	3
#define DEFAULT_PRECISION	8
#define VALUE_REPEAT_CHECK	2

//#define USE_EEPROM