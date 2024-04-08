#ifndef ANALOG_INPUT_FILTERED_H
#define ANALOG_INPUT_FILTERED_H

#define NUMBER_VALUE_AVERAGE 2

class AnalogInputFiltered {

public:
  AnalogInputFiltered(int pin);

  int Get();

  void Run();

protected:
  int mPin;

  int mNumberOfDataBuffered;

  int mValue[NUMBER_VALUE_AVERAGE];

  int mIndex;

};

#endif