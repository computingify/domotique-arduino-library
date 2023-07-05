#include "arduino.h"
#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(int pin) :
  mPin(pin)
{
  pinMode(mPin, OUTPUT);
}

void DigitalOutput::Enable() {
  digitalWrite(mPin, HIGH);
  mState = eActive;
}

void DigitalOutput::Disable() {
  digitalWrite(mPin, LOW);
  mState = eInactive;
}

eDigitalOutputState DigitalOutput::GetState() {
  return mState;
}
