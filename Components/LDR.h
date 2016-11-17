#pragma once
#include "..\Base\Pin.h"

class LDR : public Pin
{
public:
	LDR(int pin);

	int GetMinimum();
	void SetMinimum(int value);
	int GetValue();

	bool IsLightsOff();
private:
	int lummin, value;
};