#pragma once
#include "Defines.h"
#include "..\Collections\List.hpp"

class Pin
{
public:
	Pin(int PIN, int Mode);
	Pin(int PIN, int Mode, bool Analog);

	static void InitalizeAll();

	const int GetNumber();
	const byte GetMode();
	const bool GetIsAnalog();

	void Write(int Value);
	int Read();
private:
	static List<Pin*> *Pins;
protected:
	int Number;
	byte Mode;
	bool Analog;
};