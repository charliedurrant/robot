#pragma once
#include "headers.h"

class BoardRotationArrow : public GameObject
{
public:
  BoardRotationArrow(bool clockWise);
  virtual ~BoardRotationArrow(void);
  void Update();
  bool Clockwise;
private: 
  
  
};

