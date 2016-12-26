#include "LDR.h"

LDR::LDR(int PIN) : Pin(PIN, INPUT, true)
{
	this->lummin = 300;
	this->value = 0;
	this->State = false;
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

void LDR::SetOnCallback(ldrCallback Callback)
{
	this->onCallback = Callback;
}

void LDR::SetOffCallback(ldrCallback Callback)
{
	this->offCallback = Callback;
}

void LDR::HandleComponentEvents()
{
	bool State = this->IsLightsOff();
	
	if (this->State == State) return;
	this->State = State;

	if (State && this->offCallback != nullptr)
		(*this->offCallback)(this);
	else if (!State && this->onCallback != nullptr)
		(*this->onCallback)(this);
}