#pragma once
#include "FrameWork.h"
using namespace std;

class State;

class StateInput : InputBase
{
public:
  StateInput(State* state);
  ~StateInput(void);
  SDL_Scancode LastKeyUp() override;
  SDL_Scancode LastKeyDown() override;    
  bool KeyDown(SDL_Scancode key) override;    
  MouseData* Mouse() override;      
private:
  State* _state;
};

