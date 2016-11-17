#include "Components\Potentiometer.h"
#include "Components\LED.h"
#include "Components\LDR.h"
#include "Components\Buzzer.h"
#include "Components\Button.h"

Potentiometer pot(5);
LDR ldr(4);

Buzzer bzz(5);
Button btnPower(2), btnLumminM(3), btnLumminP(4);
LED ledTick(13), ledOnline(12), ledOffline(11);

bool state = false, initalized = false;

void setup()
{
	Pin::InitalizeAll();
	initalized = true;

	ldr.SetMinimum(700);
	pot.SetMaximum(1023);
}

void loop()
{
	if (initalized)
	{
		bzz.SetFrequency(450 * pot.GetPercentage());

		if (btnPower.Pressed())
		{
			state = !state;
			buzz();
		}

		if (state)
		{
			if (btnLumminP.Pressed() && ldr.GetMinimum() < 2000)
				ldr.SetMinimum(ldr.GetMinimum() + 100);

			if (btnLumminM.Pressed() && ldr.GetMinimum() > 0)
				ldr.SetMinimum(ldr.GetMinimum() - 100);

			if (ldr.IsLightsOff())
			{
				ledOffline.Enable();
				ledOnline.Disable();
				bzz.Enable();
			}
			else
			{
				ledOffline.Disable();
				ledOnline.Enable();
				bzz.Disable();
			}

			bzz.Play();
		}
		else
		{
			ledOffline.Disable();
			ledOnline.Disable();
		}

		//delay(50);
		//ledTick.Disable();
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