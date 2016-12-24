#pragma once
#include "..\Base\IComponent.h"
#include "..\Base\Pin.h"

class PIR : public Pin
{
public:
	PIR(int PIN);
	PIR(int PIN, bool analog);

	bool HasMotion();
};