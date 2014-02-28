#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;
using namespace std::placeholders; // for `_1` callback arguments

MenuState::MenuState(string id) : State("menu")
{
    
}

MenuState::~MenuState(void)
{ ; }



void MenuState::OnExit()
{
  State::OnExit();
  this->Menus = nullptr;
}

void MenuState::OnEnterAddButtons(ButtonBar* menus)
{ ; }


void MenuState::OnEnter() 
{
  SIZE sz;
  this->Menus = new ButtonBar(1,10,200,100);
  this->Menus->OnButtonClick(std::bind(&MenuState::MenuClick, this, _1, _2));
  this->Objects->Add(this->Menus);
  
  POINT pt;
  pt.X = pt.Y = 0;
  this->OnEnterAddButtons(this->Menus);
  this->Menus->PositionAndAutoSize(pt);  
  /*
  MyGame::Instance->Images->Load("button_play","button_play.png",3,1,3);
  go = new MenuItem(MyGame::Instance, new LoaderParams(100, 100,  200, 50, "button_play"));
  this->Objects->Add(go);
  
  MyGame::Instance->Images->Load("button_exit","button_exit.png",3,1,3);
  go = new MenuItem(MyGame::Instance,new LoaderParams(100, 300,  200, 30, "button_exit"));
  this->Objects->Add(go);
  */  
}


void MenuState::MenuClick(void* sender, Buttn* menu)
{
  
}
