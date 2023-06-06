#include "HBridge.h"
#include "arduino.h"

HBridge::HBridge(int in1,
  int in2,
  int switchLimitOpen,
  int switchLimitClose) :
  mIn1(in1),
  mIn2(in2),
  mSwitchLimitOpen(switchLimitOpen),
  mSwitchLimitClose(switchLimitClose),
  mDoorState(eUnknown)
{
  pinMode(mIn1, OUTPUT);
  pinMode(mIn2, OUTPUT);
  pinMode(mSwitchLimitOpen, INPUT);
  pinMode(mSwitchLimitClose, INPUT);
}

void HBridge::Open() {
  manageDoor(eOpen);
}

void HBridge::Close() {
  manageDoor(eClose);
}

eDoorState HBridge::GetState() {
  return mDoorState;
}

bool HBridge::isProcessFinish() {
  bool isFinish(false);
  switch (mDoorState) {
  case eOpenning:
    if (IsAtSwitchLimitOpen()) {
      manageDoor(eStop);
      isFinish = true;
    }
    break;
  case eClosing:
    if (IsAtSwitchLimitClose()) {
      manageDoor(eStop);
      isFinish = true;
    }
    break;
  default:
    manageDoor(eStop);
    isFinish = true;
    break;
  }
  return isFinish;
}

void HBridge::manageDoor(eDoorRequest requestedState) {
  switch (requestedState) {
  case eOpen:
    if (!IsAtSwitchLimitOpen()) {
      Serial.println("Door Openning");
      digitalWrite(mIn1, HIGH);
      digitalWrite(mIn2, LOW);
      mDoorState = eOpenning;
    }
    break;
  case eClose:
    if (!IsAtSwitchLimitClose()) {
      Serial.println("Door Closing");
      digitalWrite(mIn1, LOW);
      digitalWrite(mIn2, HIGH);
      mDoorState = eClosing;
    }
    break;
  default:
    Serial.println("Door Stop");
    digitalWrite(mIn1, LOW);
    digitalWrite(mIn2, LOW);
  }
}

bool HBridge::IsAtSwitchLimitOpen() {
  bool isOnSwitchLimitOpen(false);

  if (LOW == digitalRead(mSwitchLimitOpen)) {
    isOnSwitchLimitOpen = true;
  }

  return isOnSwitchLimitOpen;
}

bool HBridge::IsAtSwitchLimitClose() {
  bool isOnSwitchLimitClose(false);

  if (HIGH == digitalRead(mSwitchLimitClose)) {
    isOnSwitchLimitClose = true;
  }

  return isOnSwitchLimitClose;
}
