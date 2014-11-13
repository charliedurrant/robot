#pragma once
#include "framework.h"
using namespace std;

class GameObjects;

class Color
{
public:
  Color(void);
  Color(string hexValue);
  //copy constructor
  Color(const Color& ref);

  ~Color(void);
  Uint8 Red();
  Uint8 Green();
  Uint8 Blue();
  Uint8 Alpha();
  COLOR Col();
  string ToString();
private: 
  COLOR _color;
};

