#pragma once
#include "..\Base\Pin.h"

#define BUTTON_PRESSED 1
#define BUTTON_HOLD -1
#define BUTTON_RELEASE -2
#define BUTTON_NORMAL 0

class Button : public Pin
{
public:
	typedef void(*buttonCallback)(Button*);
	Button(int PIN);

	int GetState();
	bool Pressed();
	bool Holding();
	bool Released();

	void SetPressCallback(buttonCallback pressCallback);
	void SetReleaseCallback(buttonCallback releaseCallback);
	void SetHoldCallback(buttonCallback holdCallback);
private:
	int state, last;
	buttonCallback pressCallback, releaseCallback, holdCallback;
protected:
	virtual void HandleComponentEvents();
};