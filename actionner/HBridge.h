#ifndef ACTIONNER_HEADER
#define ACTIONNER_HEADER


class Actionner{

public:
  Actionner(int pin);

  void Enable();

  void Disable();
  
protected:
  int mPin;

};