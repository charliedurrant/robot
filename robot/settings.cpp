#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

//TODO: system font is now loaded on the game, no need to load in a load function?
//TODO make a base class have the SystemFont as this is a global property, do like the theme
Settings::Settings() : SettingsBase(), RenderBricksAsTowerBlocks(false), RenderBoardInOneGo(false)
{
  //load is done separately as we may need to reload and also we need the system font
}

Settings::~Settings(void)
{
  
}

void Settings::Load(string pathAndFile)
{
  shared_ptr<SplitPath> splitPath;
     
  try
  {
    SettingsBase::Load(pathAndFile);    
    this->RenderBricksAsTowerBlocks = this->Bool("render_bricks_as_tower_blocks",true);    
    this->RenderBoardInOneGo = this->Bool("render_board_in_one_go",true);   
  } 
  catch( Exception* ex )
  {
    this->LoadEnd();
    throw new Exception(str(fmt::Format("Failed to load the system settings from '{0}'") << pathAndFile),ex);
  }   
  this->LoadEnd();  
}
 

  