#ifndef PUSH_PULL_BUTTON_H
#define PUSH_PULL_BUTTON_H

#include "DigitalOutput.h"

// The aims of this class is to simulate a push pull button using a simple IO
class PushPullButton: public DigitalOutput {

public:
  PushPullButton(int pin, unsigned long upTime);

  virtual void Enable() override;

  void Handle();

protected:
  unsigned long mStartTime;

  // The time to maintains the output signal to up
  unsigned long mUpTime;
};

#endif
