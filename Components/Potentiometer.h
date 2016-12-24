#pragma once
#include "..\Base\Pin.h"

class Potentiometer : public Pin
{
public:
	typedef void(*changedCallback)(Potentiometer*, int oldValue, int newValue); 
	typedef void(*changeEndCallback)(Potentiometer*);

	Potentiometer(int PIN);
	Potentiometer(int PIN, unsigned short Precision);

	int GetValue();
	unsigned int GetPercentage();
	unsigned short GetPrecision();

	unsigned int GetMaximum();
	void SetMaximum(unsigned int Maximum);

	void SetChangedCallback(changedCallback Callback);
	void SetChangeEndCallback(changeEndCallback Callback);

private:
	int Value, Repeated;
	unsigned int Maximum;
	unsigned short Precision;
	bool Changed;

	changedCallback changed;
	changeEndCallback changeEnd;
protected:
	virtual void HandleComponentEvents();
};