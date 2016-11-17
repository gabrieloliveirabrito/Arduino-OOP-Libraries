#pragma once
#include "..\Base\IComponent.h"
#include "..\Base\Pin.h"

class Buzzer : public IComponent, public Pin
{
public:
  Buzzer(int PIN);

  void SetFrequency(int frequency);
  int GetFrequency();
  
  void Enable();
  void Disable();
  void Toggle();

  void Play();
private:
  int frequency;
};