#pragma once
#include "framework.h"

class FontManagerFont
{
public:
  FontManagerFont(string family, string pathAndFile);
  ~FontManagerFont(void);
  GameFont* Item(int pointSize, bool temporary = false);  
  bool Contains(int pointSize);
  string Family;
  string PathAndFile;
private:
   std::map<int, GameFont*> _fonts;
};


