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
  CommandBarButtonMoveForward(nullptr),
  CommandBarButtonTurnRight90Degrees(nullptr),
  CommandBarButtonTurnLeft90Degrees(nullptr),
  CommandBarButtonSwitchLightSwitch(nullptr),
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

    this->CommandBarButtonMoveForward = this->ObjectLoad("command_bar_button_move_forward");
    this->CommandBarButtonTurnRight90Degrees = this->ObjectLoad("command_bar_button_turn_right_90_degrees");
    this->CommandBarButtonTurnLeft90Degrees = this->ObjectLoad("command_bar_button_turn_left_90_degrees");
    this->CommandBarButtonNone = this->ObjectLoad("command_bar_button_none");
    this->CommandBarButtonSwitchLightSwitch = this->ObjectLoad("command_bar_button_switch_light_switch");
    this->CommandBarButtonJump = this->ObjectLoad("command_bar_button_jump");
    this->CommandBarButtonFunction1 = this->ObjectLoad("command_bar_button_function_1");
    this->CommandBarButtonFunction2 = this->ObjectLoad("command_bar_button_function_2");

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



