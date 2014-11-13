#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;


Color::Color(void)
{
  _color.r = _color.g = _color.b = 0;
  _color.a = 255;
}

Color::Color(string hexValue)
{
  Uint32 decimalValue;  
  sscanf(hexValue.c_str(), "%x", &decimalValue);  
  _color.r = (decimalValue & 0xff0000) >> 16;
  _color.g = (decimalValue & 0x00ff00) >> 8;;
  _color.b = (decimalValue & 0x0000ff);
  _color.a = 0;
}

Color::Color(const Color& ref)
{
  //this->_color = ref.Col();
}

Color::~Color(void)
{
}

Uint8 Color::Red()
{ return _color.r;}

Uint8 Color::Blue()
{ return _color.b;}

Uint8 Color::Green()
{ return _color.g;}

Uint8 Color::Alpha()
{ return _color.a;}

COLOR Color::Col()
{ return _color;}

string Color::ToString()
{
  return "FFFFFF"; //TODO: generate hex string
}