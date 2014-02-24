#pragma once
#include "headers.h"
using namespace std;

class HeadUpDisplay :public GameObject
{
public:
  HeadUpDisplay(void);
  virtual ~HeadUpDisplay(void);
  void Render() override;
  void RenderDebugInfo() override;
  void Update() override;  
private:
  
  int _framesPerSecond;  
  int _lastSecond;  
  string _text;
  string _rendererInfo;
  string FlagToBool(Uint32 flags, Uint32 flag);
};

