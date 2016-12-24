#include "..\Collections\List.hpp"
#include "Pin.h"

List<Pin*> *Pin::Pins;
Pin::Pin(int PIN, int Mode) : Pin(PIN, Mode, false)
{
}

Pin::Pin(int PIN, int Mode, bool Analog)
{
	if (Pins == nullptr)
		Pins = new List<Pin*>();
	Pins->AddItem(this);

	this->Number = PIN;
	this->Analog = Analog;
	this->Mode = Mode;
}

const int Pin::GetNumber()
{
	return this->Number;
}

const byte Pin::GetMode()
{
	return this->Mode;
}

const bool Pin::GetIsAnalog()
{
	return this->Analog;
}

void Pin::InitalizeAll()
{
	for (int i = 0; i < Pins->GetCount(); i++)
	{
		Pin *Pin = Pins->GetItem(i);

		if (!Pin->Analog)
		{
			pinMode(Pin->Number, Pin->Mode);
#ifdef DEBUG
			Serial.print("Enabling digital pin ");
			Serial.print(Pin->Number, DEC);
			Serial.print(" as ");
			Serial.println(Pin->Mode == INPUT ? "Input" : "Output");
#endif
		}
#ifdef DEBUG
		else
		{
			Serial.print("Jumping pin ");
			Serial.print(Pin->Number, DEC);
			Serial.println(" because this is analog!");
		}
#endif
	}
}

void Pin::Write(int Value)
{
	if (this->Mode == OUTPUT)
	{
		if (this->Analog)
			analogWrite(this->Number, Value);
		else
			digitalWrite(this->Number, Value);
	}
}

void Pin::Write(int Value, bool Analog)
{
	if (this->Mode == OUTPUT)
	{
		if (Analog)
			analogWrite(this->Number, Value);
		else
			digitalWrite(this->Number, Value);
	}
}

int Pin::Read()
{
	if (this->Mode == INPUT)
	{
		return this->Analog ? analogRead(this->Number) : digitalRead(this->Number);
	}
}

int Pin::Read(bool Analog)
{
	if (this->Mode == INPUT)
	{
		return Analog ? analogRead(this->Number) : digitalRead(this->Number);
	}
}

void Pin::HandleEvents()
{
	for (int i = 0; i < Pins->GetCount(); i++)
	{
		Pins->GetItem(i)->HandleComponentEvents();
	}
}

void Pin::HandleComponentEvents()
{

}