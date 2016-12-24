#pragma once
#include "..\Base\Pin.h"

class LM35 : public Pin
{
public:
	LM35(int PIN);
	LM35(int PIN, double Precision);

	double getTemperatureC();
	double getTemperatureF();
	double getTemperatureK();

	void SetUpdatedCallback(void(*sensorUpdated)(LM35*, double, double, double));
private:
	double precision;
	void(*sensorUpdated)(LM35*, double, double, double);
protected:
	virtual void HandleComponentEvents();
};