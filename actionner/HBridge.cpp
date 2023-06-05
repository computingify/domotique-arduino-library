#include "arduino.h"
#include "HBridge.h"

HBridge::HBridge(int pin) :
  mPin(pin)
{
  pinMode(mPin, OUTPUT);
}

void HBridge::Enable() {
  digitalWrite(mPin, HIGH);
}

void HBridge::Disable() {
  digitalWrite(mPin, LOW);
}