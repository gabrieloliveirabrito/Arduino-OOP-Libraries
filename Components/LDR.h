#pragma once
#include "..\Base\Pin.h"

class LDR : public Pin
{
public:
	typedef void(*ldrCallback)(LDR*);
	LDR(int pin);

	int GetMinimum();
	void SetMinimum(int value);
	int GetValue();

	bool IsLightsOff();

	void SetOnCallback(ldrCallback Callback);
	void SetOffCallback(ldrCallback Callback);
	virtual void HandleComponentEvents();
private:
	int lummin, value;
	bool State;
	ldrCallback onCallback, offCallback;
};