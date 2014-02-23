#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;


StandardBackground::StandardBackground() : GameObject()
{
  this->CurrentThemeObject = MyGame::Instance->Theme->Background;
}


StandardBackground::~StandardBackground(void)
{
  ;
}

void StandardBackground::Render()
{
  GameObject::Render();
}