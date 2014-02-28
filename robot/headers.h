#pragma once

#include "framework.h"

typedef struct BRICKDATA
{
  SIZE Size;
  int VerticalDrawOffset;
} BRICKDATA;



typedef enum LightState
{
  LightStateNone,
  LightStateOn,
  LightStateOff
} LightState;

enum Rotation
{
  RotationClockWise0 = 0,
  _RotationMinumum = RotationClockWise0,
  RotationClockWise90 = 1,
  RotationClockWise180 = 2,
  RotationClockWise270 = 3,
  _RotationMaximum = RotationClockWise270,
};

#include "settings.h"

#include "level_square.h"
#include "level.h"
#include "level_pack.h"
#include "level_packs.h"
#include "robot_program.h"
#include "theme.h"
#include "standard_background.h"
#include "robot.h"

#include "head_up_display.h"

#include "board.h"
#include "label.h"

#include "button.h"
#include "button_bar.h"
#include "command_bar.h"
#include "command_bar_button.h"

#include "board_square.h"
#include "board_rotation_arrow.h"

#include "error_state.h"
#include "menu_item.h"
#include "menu_state.h"
#include "menu_play_state.h"
#include "play_state.h"

#include "my_game.h"




