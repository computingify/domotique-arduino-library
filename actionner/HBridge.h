#ifndef HBRIDGE_H
#define HBRIDGE_H


class HBridge {

public:
  HBridge(int pin);

  void Enable();

  void Disable();

protected:
  int mPin;

};

#endif
