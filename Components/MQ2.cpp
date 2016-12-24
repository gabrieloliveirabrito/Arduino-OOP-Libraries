#include "MQ2.h"

MQ2::MQ2(int PIN) : Pin(PIN, INPUT, true)
{
	this->Maximum = 500;
}

int MQ2::GetValue()
{
	return this->Read();
}

int MQ2::GetMaximum()
{
	return this->Maximum;
}

void MQ2::SetMaximum(int Value)
{
	this->Maximum = Value;
}

bool MQ2::Detected()
{
	return this->GetValue() >= this->Maximum;
}