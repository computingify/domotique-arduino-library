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
  pinMode(mSwitchLimitOpen, INPUT_PULLUP);
  pinMode(mSwitchLimitClose, INPUT_PULLUP);

  if (IsAtSwitchLimitOpen()) {
    mDoorState = eOpened;
  }
  else if (IsAtSwitchLimitClose()) {
    mDoorState = eClosed;
  }
}

void HBridge::Open() {
  manageDoor(eOpen);
}

void HBridge::Close() {
  manageDoor(eClose);
}

void HBridge::Stop() {
  manageDoor(eStop);
}

eDoorState HBridge::GetState() {
  return mDoorState;
}

bool HBridge::run() {
  eDoorState previousState(mDoorState);

  switch (mDoorState) {
  case eOpenning:
    if (IsAtSwitchLimitOpen()) {
      manageDoor(eStop);
      mDoorState = eOpened;
    }
    break;
  case eClosing:
    if (IsAtSwitchLimitClose()) {
      manageDoor(eStop);
      mDoorState = eClosed;
    }
    break;
  case eOpened:
  case eClosed:
    break;
  default:
    manageDoor(eStop);
    mDoorState = eUnknown;
    break;
  }

  return mDoorState != previousState;
}

void HBridge::manageDoor(eDoorRequest requestedState) {
  switch (requestedState) {
  case eOpen:
    if (!IsAtSwitchLimitOpen()
      && eOpenning != mDoorState) {
      Serial.println("Door Openning");
      digitalWrite(mIn1, HIGH);
      digitalWrite(mIn2, LOW);
      mDoorState = eOpenning;
    }
    break;
  case eClose:
    if (!IsAtSwitchLimitClose()
      && eClosing != mDoorState) {
      Serial.println("Door Closing");
      digitalWrite(mIn1, LOW);
      digitalWrite(mIn2, HIGH);
      mDoorState = eClosing;
    }
    break;
  case eStop:
    Serial.println("Door Stop");
    digitalWrite(mIn1, LOW);
    digitalWrite(mIn2, LOW);
    break;
  default:
    Serial.println("Door Stop");
    digitalWrite(mIn1, LOW);
    digitalWrite(mIn2, LOW);
    mDoorState = eUnknown;
  }
}

bool HBridge::IsAtSwitchLimitOpen() {
  bool isOnSwitchLimitOpen(false);

  if (LOW == digitalRead(mSwitchLimitOpen)) {
    Serial.println("LIMIT OPEN");
    isOnSwitchLimitOpen = true;
  }

  return isOnSwitchLimitOpen;
}

bool HBridge::IsAtSwitchLimitClose() {
  bool isOnSwitchLimitClose(false);

  if (HIGH == digitalRead(mSwitchLimitClose)) {
    Serial.println("LIMIT CLOSE");
    isOnSwitchLimitClose = true;
  }

  return isOnSwitchLimitClose;
}
