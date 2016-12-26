#include "Components\Potentiometer.h"
#include "Components\RGB.h"
#include "Components\LDR.h"
#include "Components\Buzzer.h"
#include "Components\Button.h"
#include "Components\PIR.h"
#include "Components\LM35.h"
#include "Components\MQ2.h"
#include "Base\StateMachine.h"

Buzzer bzz(37);
Button btnPower(32);
RGB ledRGB(4, 3, 2);
Potentiometer potVolume(15);
LDR ldr(12);
StateMachine machine(&machine_Enabled, &machine_Disabled, &machine_Initalized);

long OfflineColor = 0x020000, OnlineColor = 0x000300;
long TemperatureAlertColor = 0x000200, GASAlertColor = 0xE39000;
long LightAlertColor = 0x666666;

void setup()
{
	Serial.begin(9600);

	Pin::InitalizeAll();
	
	potVolume.SetMaximum(1023);
	ldr.SetMinimum(300);

	btnPower.SetPressCallback(&btnPower_Pressed);
	btnPower.SetReleaseCallback(&btn_Release);
	potVolume.SetChangedCallback(&potVolume_Changed);
	potVolume.SetChangeEndCallback(&potVolume_ChangeEnd);
	ldr.SetOnCallback(&ldr_LightsOn);
	ldr.SetOffCallback(&ldr_LightsOff);

	//temp.SetUpdatedCallback(&temp_Updated);
	StateMachine::InitalizeAll();
}

void loop()
{
	if (StateMachine::IsInitalized())
	{
		Pin::HandleEvents();
	}
	delay(100);
}

void machine_Initalized(StateMachine* Machine)
{
	Serial.println("Global machine has been initalized!");
}

void machine_Enabled(StateMachine* Machine)
{
	ledRGB.SetColorFromHEX(OnlineColor);
	buzz();
}

void machine_Disabled(StateMachine* Machine)
{
	ledRGB.SetColorFromHEX(OfflineColor);
	buzz();
}

void btn_Release(Button* btn)
{
	bzz.Enable();
	bzz.Play();
	delay(machine.IsEnabled() ? 100 : 500);
	bzz.Disable();
}

void btnPower_Pressed(Button* btn)
{
	machine.Toggle();
}

void potVolume_Changed(Potentiometer* pot, int oldValue, int newValue)
{
	bzz.SetFrequency(map(newValue, 0, 1023, 0, 3000));

	if (machine.IsEnabled())
	{
		bzz.Enable();
		bzz.Play();
	}
}

void potVolume_ChangeEnd(Potentiometer* pot)
{
	if(!btnPower.Holding())
		bzz.Disable();
}

void temp_Updated(LM35* temp, double c, double f, double k)
{
	if (machine.IsEnabled() && c > 36.5)
		ledRGB.SetColorFromHEX(TemperatureAlertColor);
}

void ldr_LightsOn(LDR* ldr)
{
	if (machine.IsEnabled())
	{
		ledRGB.SetColorFromHEX(machine.IsEnabled() ? OnlineColor : OfflineColor);
		bzz.Disable();
	}
}

void ldr_LightsOff(LDR* ldr)
{
	if (machine.IsEnabled()) 
	{
		ledRGB.SetColorFromHEX(LightAlertColor);
		bzz.Enable();
		bzz.Play();
	}
}

void buzz()
{
	bzz.Enable();
	if (machine.IsEnabled())
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