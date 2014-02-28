#pragma once
#include "headers.h"

class MenuPlayState : public MenuState
{
public:
  MenuPlayState();
  void OnEnterAddButtons(ButtonBar* menus) override;
  virtual ~MenuPlayState();
  void MenuClick(void* sender, Buttn* button) override;
};

