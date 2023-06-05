#include "AnalogInputFiltered.h"
#include "arduino.h"

AnalogInputFiltered::AnalogInputFiltered(int pin) :
  mPin(pin),
  mNumberOfDataBuffered(0),
  mIndex(0)
{
  for (int i = 0; i < mNumberOfDataBuffered; i++) {
    mValue[i] = 0;
  }
}

int AnalogInputFiltered::Get() {
  int total(0);

  for (int i = 0; i < mNumberOfDataBuffered; i++) {
    total += mValue[i];
  }

  return static_cast<int>(total / mNumberOfDataBuffered);
}

void AnalogInputFiltered::Run() {

  mValue[mIndex] = analogRead(mPin);
  Serial.print("Read Lux value [");
  Serial.print(mValue[mIndex]);
  Serial.print("] at Index [");
  Serial.println(mIndex);

  mIndex++;
  if (NUMBER_VALUE_AVERAGE <= mIndex) {
    mIndex = 0;
  }

  if (NUMBER_VALUE_AVERAGE > mNumberOfDataBuffered) {
    mNumberOfDataBuffered++;
  }
}
