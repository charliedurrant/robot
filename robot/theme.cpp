#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

//TODO, should this all be accessed by key, this is getting dull
//TODO, delete objects!!!!
GameTheme::GameTheme(string pathAndFile) : BaseGameTheme(pathAndFile), 
  Background(nullptr),
  Brick(nullptr),
  Robot(nullptr),
  BoardBoardRotationArrowClockwise(nullptr),
  BoardBoardRotationArrowAntiClockwise(nullptr),
  Tile2(nullptr),
  TileOn2(nullptr),
  TileOff2(nullptr),
  FontGeneral(nullptr),
  CommandBarButtonForward(nullptr),
  CommandBarButtonTurnRight(nullptr),
  CommandBarButtonTurnLeft(nullptr),
  CommandBarButtonSwitch(nullptr),
  CommandBarButtonFunction1(nullptr),
  CommandBarButtonFunction2(nullptr),

  CommandBarButtonJump(nullptr),
  ButtonStopProgram(nullptr),
  ButtonRunProgram(nullptr)
{
  try
  {
    this->Background = this->ObjectLoad("background");
    this->Brick = this->ObjectLoad("brick");
    this->Robot = this->ObjectLoad("robot");
    this->BoardBoardRotationArrowClockwise = this->ObjectLoad("board_rotation_arrow_clockwise");
    this->BoardBoardRotationArrowAntiClockwise = this->ObjectLoad("board_rotation_arrow_anti_clockwise");
  
    this->Tile2 = this->ObjectLoad("tile");
    this->TileOn2 = this->ObjectLoad("tile_on");
    this->TileOff2 = this->ObjectLoad("tile_off");

    this->CommandBarButtonForward = this->ObjectLoad("command_bar_button_forward");
    this->CommandBarButtonTurnRight = this->ObjectLoad("command_bar_button_right");
    this->CommandBarButtonTurnLeft = this->ObjectLoad("command_bar_button_left");
    this->CommandBarButtonNone = this->ObjectLoad("command_bar_button_none");
    this->CommandBarButtonSwitch = this->ObjectLoad("command_bar_button_switch");
    this->CommandBarButtonJump = this->ObjectLoad("command_bar_button_jump");
    this->CommandBarButtonFunction1 = this->ObjectLoad("command_bar_button_function1");
    this->CommandBarButtonFunction2 = this->ObjectLoad("command_bar_button_function2");

    this->ButtonRunProgram = this->ObjectLoad("button_run_program");
    this->ButtonRunProgramTest = this->ObjectLoad("button_run_program_test");
    this->ButtonStopProgram = this->ObjectLoad("button_stop_program");
    this->ButtonResetProgram = this->ObjectLoad("button_reset_program");
    this->FontGeneral = this->LoadFont(this->ItemGet("font","general"));    
  }
  catch( Exception* ex )
  {
    throw new Exception( str(fmt::Format("Failed to load the theme from the file '{0}'") << pathAndFile),ex);
  }
}

//TODO: add to collection so can delete in one
GameTheme::~GameTheme(void)
{
 
  
}



