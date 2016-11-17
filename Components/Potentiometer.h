#pragma once
#include "..\Base\Pin.h"

class Potentiometer : public Pin
{
public:
	Potentiometer(int PIN);

	int GetValue();
	unsigned int GetPercentage();

	unsigned int GetMaximum();
	void SetMaximum(unsigned int Maximum);

private:
	int Value;
	unsigned int Maximum;
};