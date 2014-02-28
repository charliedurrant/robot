#pragma once
#include "headers.h"
using namespace std;


class Buttn : public GameObject
{
public:
  Buttn(ThemeObject* themeObject);
  Buttn(ThemeObject* themeObject, int id);
  virtual ~Buttn(void);
  int ID;
};

