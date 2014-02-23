#pragma once
#include "Headers.h"
class Player : public MyGameObject
{
public:
  Player();
  ~Player(void);  
  void Render() override;
  void Update() override;
  void Clean() override;

};