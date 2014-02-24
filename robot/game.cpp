#pragma once
#include "stdafx.h"
#include "framework.h"

Game* Game::GameInstance = nullptr;

Game::Game(void)
{ this->Construct(); }

void Game::Construct()
{
  int sdlImageFlags;
  this->WindowMain = nullptr;  
  this->_quit = false;
  this->_sdlInited = false;
  this->_nextTime = 0;
  this->FramesPerSecond = 30;
  this->Images = nullptr;
  this->_nextTime = 0;
  this->Input = nullptr;  
  this->States = nullptr;
  this->Fonts = nullptr;
  this->TicksDeltaUpdate = this->TicksCurrentUpdate = this->TicksLastUpdate = 0;
  this->SecondsDeltaUpdate = 0.0f;

  #if _DEBUG 
    this->DebugInfo = true;
  #else
    this->DebugInfo = false;
  #endif

  
  this->SystemFont = nullptr;
  this->SystemFontColor = nullptr;
  try
  {   
    this->CurrentFramesPerSecond = 0.0f;
    Game::GameInstance = this;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	  { throw new ExceptionSDL(string("VIDEO could not be initialised")); }
    this->_sdlInited = true;
    sdlImageFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    if( (IMG_Init(sdlImageFlags) & sdlImageFlags) != sdlImageFlags) 
    { throw new ExceptionSDLImage(string("Image library could not be initialised")); }   
    if (TTF_Init() == -1)
    { throw new ExceptionSDLTTF(string("SDL2 Font library could not be initialised")); }       

    this->Input = new InputHandler();
    this->States = new StateManager();
    this->Fonts = new FontManager();
  }
  catch( Exception* ex )
  { throw new Exception("Failed to create the game", ex); }
}

Game::~Game(void) 
{
  if ( this->States )
  {
    delete this->States;
    this->States = nullptr;
  }
  
  if ( this->Input )
  {
    delete this->Input;
    this->Input = nullptr;
  }

  if ( this->WindowMain ) 
  { delete this->WindowMain; }        
  
  if ( this->Images )
  {
    delete this->Images;
    this->Images = nullptr;
  }
  
  if ( this->SystemFontColor )
  {
    delete this->SystemFontColor;
    this->SystemFontColor = nullptr;
  }

  if ( this->Fonts )
  {
    delete this->Fonts;
    this->Fonts = nullptr;
  }


  if ( this->_sdlInited )
  { 
     SDL_Quit();
     this->_sdlInited = false;
  }  
}

void Game::Run()
{  
  RECT r;
  float ratio;
  SIZE sz;
  SIZE szDesign;
  float scaleDown;
  Uint32 windowFlags;
  try
  {

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
    SDL_GetDisplayBounds(0,(SDL_Rect*)&r);

    szDesign.Width = 1920;
    szDesign.Height = 1080;

    //use scale down to make the window smaller based on a widescreen ratio
    //TODO: this needs attention, what am I realy trying to do?

    #if  _DEBUG 
      scaleDown  = 0.7f;
    #else
      scaleDown  = 1.0f;
    #endif

    ratio = (float)r.Width / (float)r.Height; //widescreen
    sz.Width = (int)Functions::Round((float)r.Width * (float)scaleDown);
    sz.Height = (int)Functions::Round((float)sz.Width / ratio);

    windowFlags =  SDL_WINDOW_SHOWN 
      | SDL_WINDOW_INPUT_FOCUS  
      | SDL_WINDOW_MOUSE_FOCUS 
      | SDL_WINDOW_RESIZABLE 
      | SDL_WINDOW_MAXIMIZED 
      ;


    #if ! _DEBUG 
      windowFlags |= SDL_WINDOW_FULLSCREEN; 
    #endif
    this->WindowMain = new Window(string("Robot"),  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sz.Width, sz.Height, windowFlags,szDesign.Width,szDesign.Height); 
     
    this->Images = new ImageManager(this->WindowMain); 
    this->Init();

    while ( ! this->_quit )
    {
      
      this->Update();

      this->Render();
      this->FrameRateDelay();      
    }
  }
  catch( Exception* ex )
  { throw new Exception("Failed in the application run",ex); }  
}


void Game::FrameRateDelay()
{
  unsigned int now;
  unsigned int delay;
  
  if ( this->FramesPerSecond < 1 )
  { return; }

  now = SDL_GetTicks();
  if(this->_nextTime <= now)
  {
    this->_nextTime = now + (1000 / this->FramesPerSecond ); //INTERVAL FPS at 60
    delay =  0;
  }
  else
  {
    delay = this->_nextTime - now;
    SDL_Delay(delay);
  }
} 

void Game::Update()
{
  this->CalculateCurrentFramesPerSecond();
  this->Input->Update();
  if (this->Input->KeyDownAltControl(SDL_SCANCODE_D))
  {
    this->DebugInfo = !this->DebugInfo;
  }
  
  this->States->Update();
}

void Game::Render()
{
  this->Images->RenderCounter = 0;
  this->WindowMain->Clear();
 // SDL_FillRect(this->WindowMain,null,)
  
	  
  this->States->Render();
  this->WindowMain->Render();  
}

void Game::Init()
{
  ;
}

void Game::Quit()
{
  _quit = true;
}

bool Game::Quitted()
{
  return _quit;
}

void Game::CalculateCurrentFramesPerSecond()
 {
    this->TicksLastUpdate = this->TicksCurrentUpdate;
    this->TicksCurrentUpdate = SDL_GetTicks();
    this->TicksDeltaUpdate = this->TicksCurrentUpdate - this->TicksLastUpdate;
    this->SecondsDeltaUpdate = (float)this->TicksDeltaUpdate / 1000.0f;

    if ( this->TicksDeltaUpdate != 0 )
    { this->CurrentFramesPerSecond = 1000.0f / (float)this->TicksDeltaUpdate; }    
 }
