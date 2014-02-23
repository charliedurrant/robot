#pragma once
#include "headers.h"
using namespace std;

class DebugInfo :public GameObject
{
public:
  DebugInfo(void);
  virtual ~DebugInfo(void);
  //void Render() override;
  void RenderDebugInfo() override;
  void Update() override;
private:

  int _framesPerSecond;  
  int _lastSecond;  
  string _text;
  string _rendererInfo;
  string FlagToBool(Uint32 flags, Uint32 flag);
};

