#include "PIR.h"

PIR::PIR(int PIN) : Pin(PIN, INPUT)
{

}

PIR::PIR(int PIN, bool Analog) : Pin(PIN, INPUT, Analog)
{

}

bool PIR::HasMotion()
{
	return Read() == 1;
}