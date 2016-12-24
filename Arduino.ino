#include "Components\Potentiometer.h"
#include "Components\RGB.h"
#include "Components\LDR.h"
#include "Components\Buzzer.h"
#include "Components\Button.h"
#include "Components\PIR.h"
#include "Components\LM35.h"
#include "Components\MQ2.h"
Buzzer bzz(37);
Button btnPower(32);
RGB ledRGB(4, 3, 2);
PIR pir(8);
Potentiometer potVolume(15);
LM35 temp(14, 8);
MQ2 gas(2);
LED led(41);

bool state = false, initalized = false;
long OfflineColor = 0x020000, OnlineColor = 0x000300;
long TemperatureAlertColor = 0x000200, GASAlertColor = 0xE39000;

void setup()
{
	Serial.begin(9600);

	Pin::InitalizeAll();
	
	potVolume.SetMaximum(1023);
	gas.SetMaximum(320);

	btnPower.SetPressCallback(&btnPower_Pressed);
	btnPower.SetReleaseCallback(&btn_Release);
	potVolume.SetChangedCallback(&potVolume_Changed);
	potVolume.SetChangeEndCallback(&potVolume_ChangeEnd);
	temp.SetUpdatedCallback(&temp_Updated);

	initalized = true;
}

void btn_Release(Button* btn)
{
	bzz.Enable();
	bzz.Play();
	delay(state ? 100 : 500);
	bzz.Disable();
}

void btnPower_Pressed(Button* btn)
{
	state = !state;
	buzz();
}

void potVolume_Changed(Potentiometer* pot, int oldValue, int newValue)
{
	bzz.SetFrequency(map(newValue, 0, 1023, 0, 3000));

	bzz.Enable();
	bzz.Play();
}

void potVolume_ChangeEnd(Potentiometer* pot)
{
	if(!btnPower.Holding())
		bzz.Disable();
}

void temp_Updated(LM35* temp, double c, double f, double k)
{
	if (!state)
		ledRGB.SetColorFromHEX(OfflineColor);
	else if (c > 36.5)
		ledRGB.SetColorFromHEX(TemperatureAlertColor);
	else
		ledRGB.SetColorFromHEX(OnlineColor);
}

void loop()
{
	if (initalized)
	{
		Pin::HandleEvents();
	}
	delay(100);
}

void buzz()
{
	bzz.Enable();
	if (state)
	{
		for (int i = 0; i < 2; i++)
		{
			bzz.Play();
			delay(75);
			bzz.Disable();
			delay(25);
		}
	}
	else
	{
		bzz.Play();
		delay(100);
		bzz.Disable();
	}
}