#pragma once
#include "Defines.h"
#include "..\Collections\List.hpp"

class Pin
{
public:
	Pin(int PIN, int Mode);
	Pin(int PIN, int Mode, bool Analog);
	~Pin();

	static void InitalizeAll();
	static void HandleEvents();

	const int GetNumber();
	const byte GetMode();
	const bool GetIsAnalog();

	void Write(int Value);
	void Write(int Value, bool Analog);

	int Read();
	int Read(bool Analog);
private:
	static List<Pin*> *Pins;
protected:
	int Number;
	byte Mode;
	bool Analog;

	virtual void HandleComponentEvents();
};