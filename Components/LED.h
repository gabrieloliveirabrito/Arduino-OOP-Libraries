#pragma once
#include "..\Base\IComponent.h"
#include "..\Base\Pin.h"

class LED : public IComponent, public Pin
{
public:
	LED(int PIN);
	LED(int PIN, bool analog);

	void Enable();
	void Disable();
	void Toggle();
};