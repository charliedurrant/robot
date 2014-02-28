#pragma once
#include "stdafx.h"
#include "headers.h"

Buttn::Buttn(ThemeObject* themeObject)  : GameObject()
{
  this->CurrentThemeObject = themeObject;
  this->ID = -1;
}

Buttn::Buttn(ThemeObject* themeObject, int id) : GameObject()
{
  this->CurrentThemeObject = themeObject;
  this->ID = id;
}

Buttn::~Buttn(void)
{
}
