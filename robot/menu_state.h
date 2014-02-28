#pragma once
#include "headers.h"
using namespace std;

class MenuState : public State 
{
public:
  MenuState(string id);
  ~MenuState(void);
  virtual void OnEnter();
  virtual void OnEnterAddButtons(ButtonBar* menus);
  virtual void OnExit();
  ButtonBar* Menus;
  virtual void MenuClick(void* sender, Buttn* menu);
  
};


