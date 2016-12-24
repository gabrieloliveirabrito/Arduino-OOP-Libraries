#include "LM35.h"

LM35::LM35(int PIN) : Pin(PIN, INPUT, true)
{
	this->precision = DEFAULT_PRECISION;
}

LM35::LM35(int PIN, double precision) : Pin(PIN, INPUT, true)
{
	this->precision = precision;
}

double LM35::getTemperatureC()
{
	int tempC = 0;
	for (int i = 0; i < this->precision; i++)
	{
		tempC += (5.0 * this->Read() * 100.0) / 1024.0;
		delay(10);
	}

	return tempC / this->precision;
}

double LM35::getTemperatureF()
{
	return (this->getTemperatureC() * 9) / 5 + 32;
}

double LM35::getTemperatureK()
{
	return this->getTemperatureC() + 273;
}

void LM35::SetUpdatedCallback(void(*sensorUpdated)(LM35*, double, double, double))
{
	this->sensorUpdated = sensorUpdated;
}

void LM35::HandleComponentEvents()
{
	if (sensorUpdated != nullptr)
	{
		double c = this->getTemperatureC();
		double f = (c * 9) / 5 + 32;
		double k = c + 273;

		(*sensorUpdated)(this, c, f, k);
	}
}