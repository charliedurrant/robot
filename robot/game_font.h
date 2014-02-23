#pragma once
#include "framework.h"

enum FontWeight
{
  FontWeightNormal,
  FontWeightBold
};

enum FontStyle
{
  FontStyleNormal,
  FontStyleItalic
};

class GameFont
{
public:
  GameFont(string pathAndFile, int pointSize);
  ~GameFont(void);
  FontWeight Weight;
  FontStyle Style;
  int PointSize;
  TTF_Font* Font;    
};
