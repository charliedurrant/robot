#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

LevelSquare::LevelSquare( TiXmlElement* xmlElement )
{
  if( Functions::XMLAttributeBool( xmlElement, "light", false ) )
  {
    this->Light = LightStateOn;
  }

  this->Coordinate.X = Functions::XMLAttributeInt( xmlElement, "x", 1 ) - 1;
  this->Coordinate.Y = Functions::XMLAttributeInt( xmlElement, "y", 1 ) - 1;
  this->BrickCount = Functions::XMLAttributeInt( xmlElement, "brick_count", 0 );
}

LevelSquare::~LevelSquare( void )
{
}
