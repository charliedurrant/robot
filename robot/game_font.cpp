#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

GameFont::GameFont(string pathAndFile, int pointSize, string family) : Font(nullptr)
{  
  this->Font = TTF_OpenFont(pathAndFile.c_str(),pointSize);  
  
  if ( ! this->Font )
  {
    this->Font = nullptr;
    throw new ExceptionSDLTTF("Failed to load the font:" + pathAndFile);
  }       
  this->PointSize = pointSize;
  this->Family = family;
}


GameFont::~GameFont(void)
{
  if ( this->Font )
  {
    TTF_CloseFont(this->Font);
    this->Font = nullptr;
  }
}
