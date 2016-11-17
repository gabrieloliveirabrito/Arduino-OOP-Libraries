#pragma once
#include "Defines.h"

class IComponent
{
public:
	virtual void Toggle() { this->state = !this->state; }
	virtual void Enable() { this->state = HIGH; }
	virtual void Disable() { this->state = LOW; }

	virtual bool IsEnabled() { return this->state; }
protected:
	bool state;
};