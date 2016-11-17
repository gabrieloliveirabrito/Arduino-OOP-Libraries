#pragma once
#include "..\Base\Pin.h"

class Button : public Pin
{
public:
	Button(int PIN);

	bool Pressed();
private:
	int state;
};