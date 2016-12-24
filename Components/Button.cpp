#include "Button.h"

Button::Button(int PIN) : Pin(PIN, INPUT)
{
	this->state = false;
	this->last = BUTTON_NORMAL;
}

int Button::GetState()
{
	if (Read())
	{
		if (this->state)
			return BUTTON_HOLD;
		else
		{
			this->state = true;
			return BUTTON_PRESSED;
		}
	}
	else if (!Read() && this->state)
	{
		this->state = false;
		return BUTTON_RELEASE;
	}

	return BUTTON_NORMAL;
}

bool Button::Pressed()
{
	return this->GetState() == BUTTON_PRESSED;
}

bool Button::Holding()
{
	return this->GetState() == BUTTON_HOLD;
}

bool Button::Released()
{
	return this->GetState() == BUTTON_RELEASE;
}

void Button::SetPressCallback(buttonCallback pressCallback)
{
	this->pressCallback = pressCallback;
}

void Button::SetReleaseCallback(buttonCallback releaseCallback)
{
	this->releaseCallback = releaseCallback;
}

void Button::SetHoldCallback(buttonCallback holdCallback)
{
	this->holdCallback = holdCallback;
}

void Button::HandleComponentEvents()
{
	int State = this->GetState();
	if (State == this->last)
		return;
	else
		this->last = State;

	/*if (DEBUG)
	{
		Serial.print("Button ");
		Serial.print(GetNumber(), DEC);
		Serial.print(" stat is ");

		switch (State)
		{
			case BUTTON_NORMAL:
				Serial.println("Normal");
			break;
			case BUTTON_HOLD:
				Serial.println("Hold");
				break;
			case BUTTON_RELEASE:
				Serial.println("Release");
				break;
			case BUTTON_PRESSED:
				Serial.println("Pressed");
				break;
		}
	}*/

	if (State == BUTTON_PRESSED && this->pressCallback != nullptr)
		(*this->pressCallback)(this);
	
	if (State == BUTTON_RELEASE && this->releaseCallback != nullptr)
		(*this->releaseCallback)(this);

	if (State == BUTTON_HOLD && this->holdCallback != nullptr)
		(*this->holdCallback)(this);
}