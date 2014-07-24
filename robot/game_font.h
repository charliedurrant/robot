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
    GameFont(string pathAndFile, int pointSize, string family);
    ~GameFont(void);
    FontWeight Weight;
    FontStyle Style;
    int PointSize;
    TTF_Font* Font;    
    string Family;
};
