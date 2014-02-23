#pragma once
#include "framework.h"

using namespace std;

class GameObjects;

class State
{
  protected:
    
  public:
    State(string id);
    virtual ~State(void);

    virtual void Update();
    virtual void Render();
    virtual void RenderDebugInfo();
    virtual void OnEnter() = 0;
    virtual void OnExit();
    void Pause();
    void Play();
    GameObjects* Objects;
    string ID;
  private:
    bool _paused;
};
