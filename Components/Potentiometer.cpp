#include "Potentiometer.h"

Potentiometer::Potentiometer(int PIN) : Pin(PIN, INPUT, true)
{
	this->Maximum = 0;
	this->Repeated = 0;
	this->Precision = DEFAULT_PRECISION;
}

Potentiometer::Potentiometer(int PIN, unsigned short Precision) : Pin(PIN, INPUT, true)
{
	this->Maximum = 0;
	this->Repeated = 0;
	this->Precision = Precision;
}

int Potentiometer::GetValue()
{
	int Value = 0;

	for (int i = 0; i < this->Precision; i++)
		Value += this->Read();

	this->Value = map(Value / this->Precision, 0, 1023, 0, 1023);
	return this->Value;
}

unsigned int Potentiometer::GetPercentage()
{
	return this->Maximum == 0 ? 0 : (this->GetValue() * 100) / this->Maximum;
}

unsigned short Potentiometer::GetPrecision()
{
	return this->Precision;
}

unsigned int Potentiometer::GetMaximum()
{
	return this->Maximum;
}

void Potentiometer::SetMaximum(unsigned int Maximum)
{
	this->Maximum = Maximum;
}

void Potentiometer::SetChangedCallback(changedCallback Callback)
{
	this->changed = Callback;
}

void Potentiometer::SetChangeEndCallback(changeEndCallback Callback)
{
	this->changeEnd = Callback;
}

void Potentiometer::HandleComponentEvents()
{
	if (changed != nullptr)
	{
		int Old = this->Value;
		int New = this->Read();
		int Osc = New > Old ? New - Old : Old - New;

		if (Old != New && Osc > OSCILATION_LEVEL)
		{
			this->Value = New;
			this->Changed = true;

			if(changed != nullptr)
				(*changed)(this, Old, New);
		}
		else if (this->Changed && this->Repeated++ == VALUE_REPEAT_CHECK)
		{
			this->Repeated = 0;
			this->Changed = false;

			if (changeEnd != nullptr)
				(*changeEnd)(this);
		}
	}
}