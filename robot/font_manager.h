#pragma once
#include "framework.h"

class FontManager
{
public:
  FontManager(void);
  ~FontManager(void);
  void Add(string family, string path);
  bool Contains(string family);
  GameFont* Item(string family, int pointSize);    
private:
  std::map<std::string, FontManagerFont*> _fonts;
};

