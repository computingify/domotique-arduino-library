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
  unsigned long total(0);
  int result(0);

  for (int i = 0; i < mNumberOfDataBuffered; i++) {
    total += mValue[i];
  }

  if (0 != total && 0 != mNumberOfDataBuffered) {
    result = static_cast<int>(total / mNumberOfDataBuffered);
  }
  return result;
}

void AnalogInputFiltered::Run() {

  mValue[mIndex] = analogRead(mPin);

  mIndex++;
  if (NUMBER_VALUE_AVERAGE <= mIndex) {
    mIndex = 0;
  }

  // Useful for the startup until all the buffer is filled
  if (NUMBER_VALUE_AVERAGE > mNumberOfDataBuffered) {
    mNumberOfDataBuffered++;
  }
}
