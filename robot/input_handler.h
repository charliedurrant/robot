#pragma once
#include "framework.h"

using namespace std;

class InputHandler
{
public:
  InputHandler(void);
  ~InputHandler(void);
  MouseData* Mouse;
  void Update();
  bool KeyDown(SDL_Scancode key);  
  bool KeyDownAltControl(SDL_Scancode key);
  SDL_Scancode LastKeyUp;
  SDL_Scancode LastKeyDown;  
private:
  void OnMouseButtonUpDown(Uint8 mouseButton, MouseButtonState state);
  const Uint8* _keystates;
  void ResetMouseClick();

};

