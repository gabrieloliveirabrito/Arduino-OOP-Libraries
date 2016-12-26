#pragma once
#include "..\Collections\List.hpp"

class StateMachine
{
public:
	typedef void(*stateCallback)(StateMachine*);

	~StateMachine();
	StateMachine();
	StateMachine(stateCallback EnabledCallback, stateCallback DisabledCallback);
	StateMachine(stateCallback EnabledCallback, stateCallback DisabledCallback, bool Enabled);
	StateMachine(stateCallback EnabledCallback, stateCallback DisabledCallback, stateCallback InitalizedCallback);
	StateMachine(stateCallback EnabledCallback, stateCallback DisabledCallback, stateCallback InitalizedCallback, bool Enabled);

	static void InitalizeAll();
	static bool IsInitalized();

	void Enable();
	void Disable();
	void Toggle();
	bool IsEnabled();

	void SetEnabledCallback(stateCallback Callback);
	void SetDisabledCallback(stateCallback Callback);
private:
	static bool initalized;
	static List<StateMachine*> *machines;
	stateCallback onEnabled, onDisabled, onInitalized;
	bool state;

	void Initalize();
};