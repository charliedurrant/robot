#pragma once
#include "headers.h"
using namespace std;

class StandardBackground : public GameObject
{

public:
  StandardBackground();
  virtual ~StandardBackground(void);
  void Render() override;

};