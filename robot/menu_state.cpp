#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;


MenuState::MenuState(void) : State("menu")
{
    
}

MenuState::~MenuState(void)
{ ; }


void MenuState::Render()
{
  State::Render();  
}


void MenuState::Update()
{
  State::Update();
}

void MenuState::OnEnter() 
{

  /*
  MyGame::Instance->Images->Load("button_play","button_play.png",3,1,3);
  go = new MenuItem(MyGame::Instance, new LoaderParams(100, 100,  200, 50, "button_play"));
  this->Objects->Add(go);
  
  MyGame::Instance->Images->Load("button_exit","button_exit.png",3,1,3);
  go = new MenuItem(MyGame::Instance,new LoaderParams(100, 300,  200, 30, "button_exit"));
  this->Objects->Add(go);
  */
  

}

