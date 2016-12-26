#include "StateMachine.h"

List<StateMachine*> *StateMachine::machines;
bool StateMachine::initalized;

StateMachine::~StateMachine()
{
	machines->RemoveItem(this);
}

StateMachine::StateMachine() : StateMachine(nullptr, nullptr) { }
StateMachine::StateMachine(stateCallback EnabledCallback, stateCallback DisabledCallback) : StateMachine(EnabledCallback, DisabledCallback, nullptr, false) {}
StateMachine::StateMachine(stateCallback EnabledCallback, stateCallback DisabledCallback, bool enabled) : StateMachine(EnabledCallback, DisabledCallback, nullptr, enabled) {}
StateMachine::StateMachine(stateCallback EnabledCallback, stateCallback DisabledCallback, stateCallback InitalizedCallback) : StateMachine(EnabledCallback, DisabledCallback, InitalizedCallback, false) {}

StateMachine::StateMachine(stateCallback EnabledCallback, stateCallback DisabledCallback, stateCallback InitalizedCallback, bool enabled)
{
	this->onEnabled = EnabledCallback;
	this->onDisabled = DisabledCallback;
	this->onInitalized = InitalizedCallback;
	
	if (StateMachine::machines == nullptr)
		this->machines = new List<StateMachine*>();
	this->machines->AddItem(this);

	this->state = enabled;
}

void StateMachine::InitalizeAll()
{
	for (int i = 0; i < machines->GetCount(); i++)
		machines->GetItem(i)->Initalize();
	initalized = true;
}

bool StateMachine::IsInitalized()
{
	return initalized;
}

void StateMachine::Initalize()
{
	if (this->onInitalized != nullptr)
		(*this->onInitalized)(this);

	if (this->state && onEnabled != nullptr)
		(*onEnabled)(this);
	else if (!this->state && onDisabled != nullptr)
		(*onDisabled)(this);
}

void StateMachine::Enable()
{
	if (!this->state)
	{
		this->state = true;

		if (onEnabled != nullptr)
			(*onEnabled)(this);
	}
}

void StateMachine::Disable()
{
	if (this->state)
	{
		this->state = false;

		if (onDisabled != nullptr)
			(*onDisabled)(this);
	}
}

void StateMachine::Toggle()
{
	if (this->state)
		this->Disable();
	else
		this->Enable();
}

bool StateMachine::IsEnabled()
{
	return this->state;
}

void StateMachine::SetEnabledCallback(stateCallback Callback)
{
	this->onEnabled = Callback;
}

void StateMachine::SetDisabledCallback(stateCallback Callback)
{
	this->onDisabled = Callback;
}