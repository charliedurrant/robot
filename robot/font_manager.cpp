#pragma once
#include "stdafx.h"
#include "framework.h"

using namespace std;
using namespace fmt;


FontManager::FontManager(void)
{

}

FontManager::~FontManager(void)
{
  for (auto it=this->_fonts.begin(); it!=this->_fonts.end(); ++it)
  {
    delete it->second;
    it->second = nullptr;
  }  
  _fonts.clear();
}

void FontManager::Add(string family, string path)
{
  FontManagerFont* font;
  if ( this->Contains(family) )
  {
    font = _fonts.find(family)->second;
    throw new Exception(str(fmt::Format("The font family '{0}' has already been loaded from '{1}'") << family << font->PathAndFile));
  }
  _fonts[family] = new FontManagerFont(family,path);  
}

bool FontManager::Contains(string family)
{
  auto it = _fonts.find(family);
  return it != _fonts.end();  
}

//TODO: fontManagerFont needs to be keyed on size:weight:style
GameFont* FontManager::Item(string family, int pointSize)
{
  FontManagerFont* fontManagerFont;
  try
  {
    if ( ! this->Contains(family) )
    { throw new Exception("Font does not exist"); }     
    fontManagerFont = this->_fonts.find(family)->second;
    return fontManagerFont->Item(pointSize);
  }
  catch( Exception* ex )
  {
    throw new Exception(str(fmt::Format("Error getting a font with family '{0}'") << family),ex);
  }
}


