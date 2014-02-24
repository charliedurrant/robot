#pragma once
#include "stdafx.h"

#include "framework.h"
using namespace std;

class Game;
InputHandler::InputHandler(void) : Mouse(nullptr), _keystates(nullptr), LastKeyUp(SDL_SCANCODE_UNKNOWN), LastKeyDown(SDL_SCANCODE_UNKNOWN)
{
  this->Mouse = new MouseData();
}

InputHandler::~InputHandler(void)
{
  if ( this->Mouse )
  {
    delete this->Mouse;
    this->Mouse = nullptr;
  }
}

void InputHandler::ResetMouseClick()
{
  if ( this->Mouse->LeftButton == MouseButtonClicked )
  {
    this->Mouse->LeftButton = MouseButtonUp;
  }
  if ( this->Mouse->MiddleButton == MouseButtonClicked )
  {
    this->Mouse->MiddleButton = MouseButtonUp;
  }
  if ( this->Mouse->RightButton == MouseButtonClicked )
  {
    this->Mouse->RightButton = MouseButtonUp;
  }
}

void InputHandler::OnMouseButtonUpDown(Uint8 mouseButton, MouseButtonState state)
{
  if ( state == MouseButtonUp )
  {
    state = MouseButtonClicked;
  }
  if(mouseButton == SDL_BUTTON_LEFT)
  { 
    this->Mouse->LeftButton = state; 
  }
  else if(mouseButton == SDL_BUTTON_MIDDLE)
  {   
    this->Mouse->MiddleButton = state; 
    
  }
  else if(mouseButton == SDL_BUTTON_RIGHT)
  { 
    this->Mouse->RightButton = state; 
  } 
  
}

/*
switch( event->key.keysym.sym )
{
case SDLK_DOWN:
case SDLK_UP:
//this->Images->Image("x1")->Texture()->RenderCopy(NULL,NULL);
break;              
}
*/


void InputHandler::Update()
{
  SDL_Event event;

  this->LastKeyDown = SDL_SCANCODE_UNKNOWN;
  this->LastKeyUp = SDL_SCANCODE_UNKNOWN;
  this->ResetMouseClick();
  while( SDL_PollEvent( &event ) != 0 && ! Game::GameInstance->Quitted())
  { 
    switch( event.type )
    {
      case SDL_QUIT:
        Game::GameInstance->Quit();
        break;
      case SDL_MOUSEBUTTONDOWN: 
        OnMouseButtonUpDown(event.button.button,MouseButtonDown);
        break;        
      case SDL_MOUSEBUTTONUP:
        OnMouseButtonUpDown(event.button.button,MouseButtonUp);        
        break;        
      case SDL_MOUSEMOTION:
        this->Mouse->Position->X = (float)event.motion.x;
        this->Mouse->Position->Y = (float)event.motion.y;        
        break;  
      case SDL_KEYUP:
        _keystates = SDL_GetKeyboardState(0);
        this->LastKeyUp = event.key.keysym.scancode;                
        break;
      case SDL_KEYDOWN:
        this->LastKeyDown = event.key.keysym.scancode;        
        _keystates = SDL_GetKeyboardState(0);
        if ( this->KeyDown(SDL_SCANCODE_ESCAPE) )
        {
          Game::GameInstance->Quit();
        }
        break;      
    }
  }
}

bool InputHandler::KeyDown(SDL_Scancode key)
{
  if(_keystates != nullptr)
  {
    if(_keystates[key] == 1)
    {
      return true;
    }   
  }
  return false;
}

bool InputHandler::KeyDownAltControl(SDL_Scancode key)
{
  if ( 
    this->KeyDown(SDL_SCANCODE_LALT) &&
    this->KeyDown(SDL_SCANCODE_LCTRL) &&
    this->LastKeyDown == key
  )
  {
    return true;
  }
  return false;

}