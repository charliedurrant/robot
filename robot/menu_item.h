#pragma once
#include "headers.h"
using namespace std;

class MyGame;

class MenuItem : public GameObject
{
public:
  MenuItem(MyGame *game);
  virtual ~MenuItem(void);
  void Update() override;
private:
  MyGame* _game; 
};

