#include "arduino.h"
#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(int pin) :
  mPin(pin)
{
  pinMode(mPin, OUTPUT);
}

void DigitalOutput::Enable() {
  digitalWrite(mPin, HIGH);
}

void DigitalOutput::Disable() {
  digitalWrite(mPin, LOW);
}