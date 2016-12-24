#pragma once
#include "..\Base\Pin.h"

class MQ2 : Pin
{
public:
	MQ2(int PIN);

	int GetValue();
	
	int GetMaximum();
	void SetMaximum(int Value);

	bool Detected();
private:
	int Maximum;
};