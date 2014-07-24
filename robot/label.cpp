#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

Labl::Labl(string text) : GameObject(), _foreColor(nullptr), TextAlignment(TextAlignTopLeft)
{
  this->Text = text;
}

Labl::~Labl(void)
{
  if ( _foreColor != nullptr ) { delete _foreColor; _foreColor = nullptr; }
}

void Labl::Render()
{
  RECT_FRAMEWORK r;
  
  r = this->Rentangle();
  MyGame::Instance->WindowMain->RenderText(this->Text,this->FontGet(),this->ForeColorGet(),&r);
}

void Labl::RenderDebugInfo()
{
  return;
}

GameFont* Labl::FontGet()
{
  return MyGame::Instance->SystemFont;
}

Color* Labl::ForeColorGet()
{
  if ( _foreColor == nullptr )
  { _foreColor = new Color(MyGame::Instance->SystemFontColor->ToString()); }
  return _foreColor;
}