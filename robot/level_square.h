#pragma once
#include "headers.h"
using namespace std;

class LevelSquare
{
public:
  LevelSquare(TiXmlElement* xmlElement);
  ~LevelSquare(void);
  POINT Coordinate;
  LightState Light;
  int BrickCount;  
};

