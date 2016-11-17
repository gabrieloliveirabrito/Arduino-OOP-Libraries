#include "Potentiometer.h"

Potentiometer::Potentiometer(int PIN) : Pin(PIN, INPUT, true)
{
	this->Maximum = 0;
}

int Potentiometer::GetValue()
{
	this->Value = Read();
	return this->Value;
}

unsigned int Potentiometer::GetPercentage()
{
	return this->Maximum == 0 ? 0 : (this->GetValue() * 100) / this->Maximum;
}

unsigned int Potentiometer::GetMaximum()
{
	return this->Maximum;
}

void Potentiometer::SetMaximum(unsigned int Maximum)
{
	this->Maximum = Maximum;
}