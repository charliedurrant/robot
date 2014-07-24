#pragma once
#include "stdafx.h"
#include "framework.h"

FontManagerFont::FontManagerFont(string family, string pathAndFile)
{
  this->Family = family;
  this->PathAndFile = pathAndFile;
}

FontManagerFont::~FontManagerFont(void)
{
  for (auto it=this->_fonts.begin(); it!=this->_fonts.end(); ++it)
  {
    delete it->second;
    it->second = nullptr;
  }
  _fonts.clear();
}

bool FontManagerFont::Contains(int pointSize)
{
  auto it = _fonts.find(pointSize);
  return it != _fonts.end();  
}

GameFont* FontManagerFont::Item(int pointSize, bool temporary)
{
  GameFont* gameFont;
  if ( temporary )
  { gameFont = new GameFont(this->PathAndFile,pointSize, this->Family); }
  else
  {
    if ( ! this->Contains(pointSize) )
    {
      gameFont = new GameFont(this->PathAndFile,pointSize, this->Family);
      _fonts[pointSize] = gameFont;
    }
    else
    {
      auto it = this->_fonts.find(pointSize);    
      gameFont  = it->second;
    }

  }
  return gameFont; 
}  
