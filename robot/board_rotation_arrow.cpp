#pragma once
#include "stdafx.h"
#include "headers.h"

using namespace std;

BoardRotationArrow::BoardRotationArrow(bool clockWise) : GameObject() 
{
  if ( clockWise )
  {
    this->CurrentThemeObject = MyGame::Instance->Theme->BoardBoardRotationArrowClockwise;  
  }
  else
  {
    this->CurrentThemeObject = MyGame::Instance->Theme->BoardBoardRotationArrowAntiClockwise;  
  }
  
  this->Clockwise = clockWise;
  
}

BoardRotationArrow::~BoardRotationArrow(void)
{
  
}

void BoardRotationArrow::Update()
{
  GameObject::Update();
  if ( this->ContainsMouse() && (MyGame::Instance->Input->Mouse->LeftButton == MouseButtonClicked) )
  {    
    //this->_board->Rotate(this->_clockWise);    
  }
  
}
