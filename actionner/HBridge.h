#ifndef H_BRIDGE_H
#define H_BRIDGE_H

typedef enum {
  eOpenning = 0,
  eOpened,
  eClosing,
  eClosed,
  eUnknown,
}eDoorState;

class HBridge {

public:
  HBridge(int in1,
    int in2,
    int switchLimitOpen,
    int switchLimitClose);

  virtual ~HBridge() = default;

  void Open();

  void Close();

  eDoorState GetState();

  bool isProcessFinish();

protected:

  typedef enum {
    eOpen = 0,
    eClose,
    eStop,
    eNo,
  }eDoorRequest;

  bool IsAtSwitchLimitOpen();

  bool IsAtSwitchLimitClose();

  void manageDoor(eDoorRequest requestedState);

  int mIn1;

  int mIn2;

  int mSwitchLimitOpen;

  int mSwitchLimitClose;

  eDoorState mDoorState;

};

#endif