#include "Buzzer.h"

Buzzer::Buzzer(int PIN) : Pin(PIN, OUTPUT)
{
  this->frequency = 100;
  this->state = LOW;
}

void Buzzer::SetFrequency(int frequency)
{
  this->frequency = frequency;
}

int Buzzer::GetFrequency()
{
	return this->frequency;
}

void Buzzer::Enable()
{
	IComponent::Enable();
}

void Buzzer::Disable()
{
	IComponent::Disable();
	noTone(this->Number);
}

void Buzzer::Toggle()
{
	IComponent::Toggle();

	if (!this->state)
		noTone(this->Number);
}

void Buzzer::Play()
{
  if(this->state && this->frequency > 0)
    tone(this->Number, this->frequency);
  else
    noTone(this->Number);
}
