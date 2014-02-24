#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

HeadUpDisplay::HeadUpDisplay(void) : GameObject(), _lastSecond(-1)
{
  string textureSize;
  SDL_RendererInfo rendererInfo;    
  
  this->_text = string("");


  SDL_GetRendererInfo(MyGame::Instance->WindowMain->Renderer,&rendererInfo);  

  if (rendererInfo.max_texture_height == 0 )
  {
    textureSize = "N/A";
  }
  else
  {
    textureSize = str(fmt::Format("{0} x {1}") << rendererInfo.max_texture_width << rendererInfo.max_texture_height );
  }

  //textureSize = str(fmt::Format() <<

  this->_rendererInfo = str(
        fmt::Format
        (
        "Renderer: {0}\nSupports rendering to textures: {1}\nHardware acceleration: {2}\nSynced to screen refresh rate: {3}\nMax texture size: {4}\nRender bricks as tower blocks: {5}\nRender board in one go: {6}"
        )
        << string(rendererInfo.name) 
        << this->FlagToBool(rendererInfo.flags,SDL_RENDERER_TARGETTEXTURE)
        << this->FlagToBool(rendererInfo.flags,SDL_RENDERER_ACCELERATED)
        << this->FlagToBool(rendererInfo.flags,SDL_RENDERER_PRESENTVSYNC)        
        << textureSize
        << Functions::BoolToString(MyGame::Instance->Settngs->RenderBricksAsTowerBlocks)
        << Functions::BoolToString(MyGame::Instance->Settngs->RenderBoardInOneGo)
       );
  
  //draws the text
}

string HeadUpDisplay::FlagToBool(Uint32 flags, Uint32 flag)
{
  string s;
  return Functions::BoolToString( (flags & flag) == flag );  
}

HeadUpDisplay::~HeadUpDisplay(void)
{
  ;
}

void HeadUpDisplay::Update()
{
  static bool b = false;
  int seconds;
  int framesPerSecond;
  
  if ( MyGame::Instance->Input->KeyDownAltControl(SDL_SCANCODE_H) )
  {
    this->Visible = ! this->Visible;    
  }
      
  if ( this->Visible )
  {
    seconds = SDL_GetTicks() / 1000;
    if ( seconds != _lastSecond  )
    {
      _lastSecond = seconds;    
      framesPerSecond = (int)MyGame::Instance->CurrentFramesPerSecond;
      this->_text.assign(str(fmt::Format("FPS: {0}\nTextures drawn: {1}") << framesPerSecond << MyGame::Instance->Images->RenderCounter));    
    }
  }
}

void HeadUpDisplay::Render()
{
  string s;
  s = this->_rendererInfo + string("\n") + this->_text;
  MyGame::Instance->WindowMain->RenderText(s, MyGame::Instance->Theme->FontGeneral, MyGame::Instance->SystemFontColor, &(this->Rentangle()));
}

void HeadUpDisplay::RenderDebugInfo()
{
  return;
  
}
