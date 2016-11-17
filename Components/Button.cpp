#include "Button.h"

Button::Button(int PIN) : Pin(PIN, INPUT)
{
}

bool Button::Pressed()
{
	if (Read() && !this->state)
	{
		this->state = true;
		return true;
	}
	else if (!Read() && this->state)
	{
		this->state = false;
	}
	return false;
}