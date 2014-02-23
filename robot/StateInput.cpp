#pragma once
#include "StdAfx.h"
#include "FrameWork.h"
using namespace std;


StateInput::StateInput(State* state) : InputBase()
{
  _mouse->Position->Y = _mouse->Position->X = -1.0f;
  _state = state;
}


StateInput::~StateInput(void)
{
}


bool StateInput::KeyDown(SDL_Scancode key)
{
  
}

bool StateInput::MyDateIsTheCurrentState()


SDL_Scancode StateInput::LastKeyUp() 
{ 
  return SDL_SCANCODE_UNKNOWN; 
}
SDL_Scancode StateInput::LastKeyDown() 
{ 
  return SDL_SCANCODE_UNKNOWN; 
}

MouseData* StateInput::Mouse()  
{
  if ( Game::GameInstance->States->Current() == _state ) //TODO, way to slow to do this every timem, state shoud be marked as current
  {
    return Game::GameInstance->Input->Mouse();  
  }
  else
  {
    return _mouse;
  }
}