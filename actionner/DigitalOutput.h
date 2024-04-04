#ifndef DIGITAL_OUTPUT_H
#define DIGITAL_OUTPUT_H

typedef enum {
  eInactive = 0,
  eActive,
}eDigitalOutputState;

class DigitalOutput {

public:
  DigitalOutput(int pin);

  virtual void Enable();

  void Disable();

  eDigitalOutputState GetState();

protected:
  int mPin;

  eDigitalOutputState mState;
};

#endif
