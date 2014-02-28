#pragma once
#include "headers.h"
using namespace std;

class MyGame : public Game
{
  public:
    MyGame(void); 
    ~MyGame(void);
    virtual void Init();
    GameTheme* Theme;
    LevelPacks* LevlPacks;
    static MyGame* Instance;
    PlayState* PlyState();
    Rotation Rotate90Degrees(Rotation currentRotation, bool clockwise);
    Settings* Settngs;
    
};

