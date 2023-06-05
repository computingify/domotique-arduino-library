#include "include/Actionner.h"
#include "arduino.h"

Actionner::Actionner(int pin):
  mPin(pin)
{
  pinMode(mPin, OUTPUT);
} 
  
void Actionner::Enable() {
  digitalWrite(mPin, HIGH);
}
  
void Actionner::Disable(){
  digitalWrite(mPin, LOW);
}