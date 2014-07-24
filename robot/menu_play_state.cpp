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
  

 // themeObject = new ThemeObject(MyGame::Instance->Theme->ButtonRunProgramTest);
  //MyGame::Instance->Theme->ButtonRunProgramTest->FirstImage()->TextSet("Hello");
  
//  themeObject->FirstImage()->TextSet("Hello");
  
  button = new Buttn(MyGame::Instance->Theme->ButtonRunProgramTest, 1);
  menus->AddButton(button);

  //button = new Buttn(MyGame::Instance->Theme->ButtonRunProgram, 1);
  //menus->AddButton(button);
  /*
  button = new Buttn(MyGame::Instance->Theme->ButtonRunProgram, 1);
  menus->AddButton(button);

  button = new Buttn(MyGame::Instance->Theme->ButtonRunProgram, 1);
  menus->AddButton(button);

  menus->BackgorundImage = MyGame::Instance->Theme->ButtonStopProgram;
*/
  menus->Padding.Set(50);
}

void MenuPlayState::MenuClick(void* sender, Buttn* button)
{
  MyGame::Instance->States->Change(new PlayState()); 
}