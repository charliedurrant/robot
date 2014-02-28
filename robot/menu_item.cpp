#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

MenuItem::MenuItem(MyGame* game) : GameObject() , _game(nullptr)
{
  //_frame = MouseOut;
  _game = game;
}

MenuItem::~MenuItem(void)
{

}


//TODO: delete menu_item
void MenuItem::Update()
{
  /*
  if ( this->ContainsMouse() )
  {
    if ( MyGame::GameInstance->Input->Mouse->LeftButton == MouseButtonDown )
    {
      //_frame = Clicked;
      void (MyGame::*menuClick) (string) = &MyGame::MenuClick;
      (_game->*menuClick)("str");//
    }
    else
    {
      //_frame = MouseHover;
    }
  }
  else
  {
    //_frame = MouseOut;
  }*/ 
}
