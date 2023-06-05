#ifndef ANALOG_INPUT_FILTERED_HEADER
#define ANALOG_INPUT_FILTERED_HEADER

#define NUMBER_VALUE_AVERAGE 5

class AnalogInputFilterd{

public:
  AnalogInputFilterd(int pin);
  
  int Get();
  
  void Run();
  
protected:
  int mPin;
  
  int mNumberOfDataBuffered;
  
  int[NUMBER_VALUE_AVERAGE] mValue;
  
  int mIndex;

};