#pragma once 
#include "stdafx.h"
#include "headers.h"
using namespace std;

MyGame* MyGame::Instance = nullptr;

MyGame::MyGame(void) : Game(), Theme(nullptr)
{
  MyGame::Instance = this;
}

MyGame::~MyGame(void)
{
  if ( this->Theme != nullptr )
  {
    delete this->Theme;
    this->Theme = nullptr;
  } 												   
}

void MyGame::Init()
{
  State* state;
  string path;
  string applicationPath;
  
  try
  {
     Game::Init();
     applicationPath = Functions::ApplicationPath();
     this->Settngs = new Settings();

     //load the system font in first as we need it for error messages
     //now parse the settings file
     path = applicationPath + "system/settings.xml";
     this->Settngs->Load(path);

     path = applicationPath + "themes/default/theme.xml";
     
     this->Theme = new GameTheme(path);
     path = applicationPath + "level_packs/level_packs.xml";
     this->LevlPacks = new LevelPacks(path);

     state = new MenuPlayState();
     this->States->Push(state);
  }
  catch (Exception* ex)
  {     
     throw new Exception("Failed to init the game", ex); 
  }
}

//http://www.codeguru.com/cpp/cpp/article.php/c17401/C-Tutorial-PointertoMember-Function.Heighttm

Rotation MyGame::Rotate90Degrees(Rotation currentRotation, bool clockwise)
{
  if ( clockwise )
  {
    if ((currentRotation) + 1 > _RotationMaximum)
    { return _RotationMinumum; }
    else
    { return (Rotation)((int)(currentRotation) + 1); }
  }
  else
  {
    if ((currentRotation) - 1 < _RotationMinumum)
    { return  _RotationMaximum; }
    else
    { return  (Rotation)((int)(currentRotation) - 1); }    
  }
}

bool MyGame::ErrorStatePush(const string& message, Exception* ex)
{
  ErrorState* errorState;
  if ((this->States == nullptr) || (this->SystemFont == nullptr) )
  {
    Functions::ErrorMessageConsole(message, ex);
  }
  else
  {
    errorState = new ErrorState(message, ex);
    this->States->Push(errorState);
    return true;
  }
  return false;

}
PlayState* MyGame::PlyState()
{
  return (PlayState*)this->States->Current();
}