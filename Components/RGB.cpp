#include "RGB.h"

RGB::RGB(int RPIN, int GPIN, int BPIN) : RLed(RPIN, false), GLed(GPIN, false), BLed(BPIN, false)
{
}

void RGB::Toggle()
{
	this->RLed.Toggle();
	this->GLed.Toggle();
	this->BLed.Toggle();
}

void RGB::Enable()
{
	this->RLed.Enable();
	this->GLed.Enable();
	this->BLed.Enable();
}

void RGB::Disable()
{
	this->RLed.Disable();
	this->GLed.Disable();
	this->BLed.Disable();
}

void RGB::SetColor(int R, int G, int B)
{
	this->RLed.Write(R, true);
	this->GLed.Write(G, true);
	this->BLed.Write(B, true);
}

void RGB::SetColorFromHEX(long Hex)
{
	int B = Hex & 0xFF;
	int G = (Hex >> 8) & 0xFF;
	int R = (Hex >> 16) & 0xFF;

	this->SetColor(R, G, B);
}