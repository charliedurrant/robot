#pragma once
#include "headers.h"
using namespace std;

class LevelSquare
{
public:
  LevelSquare(TiXmlElement* xmlElement);
  ~LevelSquare(void);
  POINT_FRAMEWORK Coordinate;
  LightState Light;
  int BrickCount;  
};

