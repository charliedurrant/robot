#pragma once
#include "framework.h"

class EventHndler
{
public:
  EventHndler(void);
  ~EventHndler(void);
  void OnClick(std::function<void(void*)> onClickCallBack); //void * will be the sender
private:
  std::function<void(void*)> _onClickCallBack;
};

