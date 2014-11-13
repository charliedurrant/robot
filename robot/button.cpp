#pragma once
#include "stdafx.h"
#include "headers.h"

Buttn::Buttn(ThemeObject* themeObject) : GameObject() , ForceLeftButtonMouseDown(false)
{
  this->CurrentThemeObject = themeObject;
  this->ID = -1;
}

Buttn::Buttn(ThemeObject* themeObject, int id) : GameObject(), ForceLeftButtonMouseDown(false)
{
  this->CurrentThemeObject = themeObject;
  this->ID = id;
}

Buttn::~Buttn(void)
{
  ;
}

void Buttn::Render()
{
  int mouseMouseDownOffset;
  bool leftMouseDown;
  
  leftMouseDown = this->ForceLeftButtonMouseDown || this->LeftMousebuttonDown();
  if ( leftMouseDown )
  {
    mouseMouseDownOffset = 2;
    this->Position.X += mouseMouseDownOffset;
    this->Position.Y += mouseMouseDownOffset;
  }

  GameObject::Render();
  
  if ( leftMouseDown )
  {
    this->Position.X -= mouseMouseDownOffset;
    this->Position.Y -= mouseMouseDownOffset;
  } 
}