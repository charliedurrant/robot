#pragma once
#include "headers.h"
using namespace std;

class GameTheme : public BaseGameTheme
{
public:
  GameTheme(string pathAndFile);
  ~GameTheme();
  ThemeObject* Background;
  ThemeObject* Brick;
  ThemeObject* BoardBoardRotationArrowClockwise;
  ThemeObject* BoardBoardRotationArrowAntiClockwise;
  ThemeObject* Robot;
  ThemeObject* Tile2;
  ThemeObject* CommandBarButtonForward;
  ThemeObject* CommandBarButtonTurnRight;
  ThemeObject* CommandBarButtonTurnLeft;
  ThemeObject* CommandBarButtonNone;
  ThemeObject* CommandBarButtonSwitch;
  ThemeObject* CommandBarButtonFunction1;
  ThemeObject* CommandBarButtonFunction2;
  ThemeObject* CommandBarButtonJump;
  ThemeObject* ButtonStopProgram;
  ThemeObject* ButtonRunProgram;
  ThemeObject* ButtonRunProgramTest;
  ThemeObject* ButtonResetProgram;
  
  ThemeObject* TileOn2;
  ThemeObject* TileOff2;
  
  GameFont* FontGeneral;  
  
private:
  

};

