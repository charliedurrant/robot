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
    this->Background = this->ObjectGet("background");
    this->Brick  = this->ObjectGet("brick");
    this->Robot  = this->ObjectGet("robot");
    this->BoardBoardRotationArrowClockwise = this->ObjectGet("board_rotation_arrow_clockwise");
    this->BoardBoardRotationArrowAntiClockwise = this->ObjectGet("board_rotation_arrow_anti_clockwise");
  
    this->Tile2 = this->ObjectGet("tile");     
    this->TileOn2 = this->ObjectGet("tile_on");     
    this->TileOff2 = this->ObjectGet("tile_off");     

    this->CommandBarButtonMoveForward = this->ObjectGet("command_bar_button_move_forward");
    this->CommandBarButtonTurnRight90Degrees = this->ObjectGet("command_bar_button_turn_right_90_degrees");
    this->CommandBarButtonTurnLeft90Degrees = this->ObjectGet("command_bar_button_turn_left_90_degrees");
    this->CommandBarButtonNone = this->ObjectGet("command_bar_button_none");
    this->CommandBarButtonSwitchLightSwitch = this->ObjectGet("command_bar_button_switch_light_switch");
    this->CommandBarButtonJump = this->ObjectGet("command_bar_button_jump");
    this->CommandBarButtonFunction1 = this->ObjectGet("command_bar_button_function_1");
    this->CommandBarButtonFunction2 = this->ObjectGet("command_bar_button_function_2");

    this->ButtonRunProgram = this->ObjectGet("button_run_program");
    this->ButtonStopProgram = this->ObjectGet("button_stop_program");
    this->ButtonResetProgram = this->ObjectGet("button_reset_program");       
  
    this->FontGeneral = this->LoadFont(this->ItemGet("font","general"));
    //Game::GameInstance->DebugInfoFont = this->LoadFont(this->ItemGet("font","debug_info")); //TODO: utter rubbish, need system config file or we have a base theme?? which is always on the game
    //TODO: same as above
    //Game::GameInstance->DebugTextColor = this->ColorGet("debug_text_color");        

    this->ConstructorEnd();
  }
  catch( Exception* ex )
  {
    throw new Exception( str(fmt::Format("Failed to load the theme from the file '{0}'") << pathAndFile),ex);
  }
}

//TODO: add to collection so can delete in one
GameTheme::~GameTheme(void)
{
  if ( this->Background ) { delete this->Background; }
  if ( this->Brick ) { delete this->Brick; }
  if ( this->Robot ) { delete this->Robot; }
  if ( this->BoardBoardRotationArrowClockwise ) { delete this->BoardBoardRotationArrowClockwise; }
  if ( this->BoardBoardRotationArrowAntiClockwise ) { delete this->BoardBoardRotationArrowAntiClockwise; }
  if ( this->Tile2 ) { delete this->Tile2; }
  if ( this->TileOn2 ) { delete this->TileOn2; }
  if ( this->TileOff2 ) { delete this->TileOff2; }
  if ( this->FontGeneral ) { delete this->FontGeneral; }
  if ( this->CommandBarButtonMoveForward ) { delete this->CommandBarButtonMoveForward; }
  if ( this->CommandBarButtonTurnLeft90Degrees ) { delete this->CommandBarButtonTurnLeft90Degrees; }
  if ( this->CommandBarButtonTurnRight90Degrees ) { delete this->CommandBarButtonTurnRight90Degrees; }
  if ( this->CommandBarButtonNone ) { delete this->CommandBarButtonNone; }
  if ( this->CommandBarButtonSwitchLightSwitch ) { delete this->CommandBarButtonSwitchLightSwitch; }
  if ( this->CommandBarButtonJump ) { delete this->CommandBarButtonJump; }
  if ( this->CommandBarButtonFunction1 ) { delete this->CommandBarButtonFunction2; }
  if ( this->ButtonStopProgram ) { delete this->ButtonStopProgram; }
  if ( this->ButtonRunProgram ) { delete this->ButtonRunProgram; }
  if ( this->ButtonResetProgram ) { delete this->ButtonResetProgram; }
  
}



