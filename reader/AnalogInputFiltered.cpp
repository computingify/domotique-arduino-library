#include "include/AnalogInputFilterd.h"
#include "arduino.h"

AnalogInputFilterd::AnalogInputFilterd(int pin):
  mPin(pin),
  mValue(0),
  mNumberOfDataBuffered(0),
  mIndex(0)
{}
  
int AnalogInputFilterd::Get() {
  int total(0);
  
  for(int i = 0; i < mNumberOfDataBuffered; i++) {
    total += mValue[i];
  }
  
  return std::static_cast<int>(total / mNumberOfDataBuffered);
}
  
void AnalogInputFilterd::Run(){
  
  mValue[mIndex] = analogRead(mPin);
  mIndex++;
  if(NUMBER_VALUE_AVERAGE <= mIndex) {
    mIndex = 0;
  } 
  
  if(NUMBER_VALUE_AVERAGE > mNumberOfDataBuffered) {
    mNumberOfDataBuffered++;
  }
}
