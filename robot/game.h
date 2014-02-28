#pragma once
#include "framework.h"

using namespace std;

class StateManager;
class ImageManager;
class InputHandler;
class Window;

class Game
{
  public:
    Game(void);
    ~Game(void);
    void Run();
    Window *WindowMain;  
    InputHandler* Input;  
    virtual void Update();
    virtual void Render();
    virtual void Init();
    void Quit();
    bool Quitted();
    ImageManager* Images;
    StateManager* States;
    FontManager* Fonts;
    void FrameRateDelay();
    static Game* GameInstance;
    unsigned int FramesPerSecond;    
    float CurrentFramesPerSecond;
    bool DebugInfo;
    GameFont* SystemFont; //need a system config section
    Color* SystemFontColor; //TODO: combine with font??!?
    int TicksCurrentUpdate;
    int TicksLastUpdate;
    int TicksDeltaUpdate;
    float SecondsDeltaUpdate;
  protected:
    bool _quit;  
    bool _sdlInited;
    unsigned int _nextTime;      
  private:
    void Construct();
    void CalculateCurrentFramesPerSecond();
};


