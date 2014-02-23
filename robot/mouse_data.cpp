#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;


MouseData::MouseData(void) : Position(nullptr), _captured(nullptr)
{
  this->Position = new Vector2D(-1,-1);
}


MouseData::~MouseData(void)
{
  if ( this->Position )
  {
    delete this->Position;
    this->Position = nullptr;
  }
}

 GameObject* MouseData::GetCapture()
 {
   return _captured;
 }

 void MouseData::SetCapture(GameObject* gameObject)
 {
  _captured = gameObject;
 }
  
