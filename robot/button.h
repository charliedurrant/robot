#pragma once
#include "headers.h"
using namespace std;


class Buttn : public GameObject
{
public:
  
  bool ForceLeftButtonMouseDown;
  Buttn(ThemeObject* themeObject);
  Buttn(ThemeObject* themeObject, int id);
  virtual ~Buttn(void);
  int ID;
  void Render() override;  
private:
  int _mouseDownOffset;
};

