#include <Arduino.h>
#include "PushPullButton.h"


PushPullButton::PushPullButton(int pin, unsigned long upTime) :
  DigitalOutput(pin),
  mUpTime(upTime)
{ }

void PushPullButton::Enable() {
  DigitalOutput::Enable();
  mStartTime = millis();
}

void PushPullButton::Handle() {
  if(eActive == mState
    && ((millis() - mStartTime) > mUpTime)) {
      DigitalOutput::Disable();
      mStartTime = 0;
  }
}
