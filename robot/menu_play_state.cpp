#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;


MenuPlayState::MenuPlayState() : MenuState("menu_play")
{
  
}

MenuPlayState::~MenuPlayState()
{
}

void MenuPlayState::OnEnterAddButtons(ButtonBar* menus)
{
  Buttn* button;
  
  button = new Buttn(MyGame::Instance->Theme->ButtonRunProgram,1);
  menus->AddButton(button);      
}

void MenuPlayState::MenuClick(void* sender, Buttn* button)
{
  MyGame::Instance->States->Change(new PlayState()); 
}