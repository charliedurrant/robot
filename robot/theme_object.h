#pragma once
#include "framework.h"
using namespace std;

class ThemeObject
{
public:
  ThemeObject(BaseGameTheme* theme, string id, TiXmlElement* xmlElement);
  ThemeObject( const ThemeObject* copy );
  ~ThemeObject(void);
  string ID;
  std::vector<ThemeObjectImage*> ObjectImages;
  void Reset();  
  void Render(RECT rectangleDestination );
  float ScaleToParent;
  ThemeObjectImage* FirstImage();
};

