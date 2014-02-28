#pragma once
#include "headers.h"
using namespace std;



class Labl : public GameObject
{
public:
  Labl(string text);
  ~Labl(void);
  void Render() override;
  void RenderDebugInfo() override;
  string Text;
  TextAlign TextAlignment;
  Color* ForeColorGet();
  GameFont* FontGet();
private: 
  Color* _foreColor;
  GameFont* _font;
};

