#pragma once
#include "headers.h"
using namespace std;

class MenuState : public State 
{
public:
  MenuState(void);
  ~MenuState(void);
  virtual void OnEnter();
  void Update() override;
  void Render() override;
};


