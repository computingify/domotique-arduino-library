#ifndef H_BRIDGE_H
#define H_BRIDGE_H

typedef enum {
  eOpenning = 0,  // 0
  eOpened,        // 1
  eClosing,       // 2
  eClosed,        // 3
  eUnknown,       // 4
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

  void Stop();

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