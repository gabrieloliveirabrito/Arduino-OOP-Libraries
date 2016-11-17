#include "LDR.h"

LDR::LDR(int PIN) : Pin(PIN, INPUT, true)
{
	this->lummin = 300;
	this->value = 0;
}

int LDR::GetMinimum()
{
	return this->lummin;
}

void LDR::SetMinimum(int value)
{
	this->lummin = value;
}

int LDR::GetValue()
{
	this->value = Read();
	return this->value;
}

bool LDR::IsLightsOff()
{
	return this->GetValue() > this->lummin;
}