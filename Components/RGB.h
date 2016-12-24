#pragma once
#include "..\Base\IComponent.h"
#include "..\Base\Pin.h"
#include "LED.h"

class RGB : public IComponent
{
public:
	RGB(int RPIN, int GPIN, int BPIN);

	void Enable();
	void Disable();
	void Toggle();

	void SetColor(int R, int G, int B);
	void SetColorFromHEX(long Hex);
private:
	LED RLed, GLed, BLed;
};