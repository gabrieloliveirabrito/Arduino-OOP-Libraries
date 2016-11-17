#include "LED.h"

LED::LED(int PIN) : Pin(PIN, OUTPUT)
{
	
}

LED::LED(int PIN, bool analog) : Pin(PIN, OUTPUT, analog)
{
	this->state = LOW;
}

void LED::Toggle()
{
	IComponent::Toggle();
	Write(this->state);
}

void LED::Enable()
{
	IComponent::Enable();
	Write(this->state);
}

void LED::Disable()
{
	IComponent::Disable();
	Write(this->state);
}