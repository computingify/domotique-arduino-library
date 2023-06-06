#ifndef DIGITAL_OUTPUT_H
#define DIGITAL_OUTPUT_H


class DigitalOutput {

public:
  DigitalOutput(int pin);

  void Enable();

  void Disable();

protected:
  int mPin;

};

#endif
