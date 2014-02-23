#pragma once
#include "stdafx.h"
#include "framework.h"

Window::Window(string title,int x, int y, int w, int h,Uint32 flags, int logicalWidthDesign, int logicalHeightDesign)
{
  //SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC |
  this->Construct(title,x,y,w,h,flags,-1,SDL_RENDERER_ACCELERATED |  SDL_RENDERER_TARGETTEXTURE,logicalWidthDesign,logicalHeightDesign);// | SDL_RENDERER_PRESENTVSYNC);
}

Window::Window(string title,int x, int y, int w, int h,Uint32 flags, int rendererIndex,Uint32 rendererFlags,int logicalWidthDesign, int logicalHeightDesign)
{
  this->Construct(title,x,y,w,h,flags,rendererIndex,rendererFlags,logicalWidthDesign,logicalHeightDesign);
}

//logocalDesignSize is the ideal size, if the windows w and h is not ideal we can use the scale functions to scale to the logicalDesign sizes, it really is only for debugging purposes so we 
//can create windows to odd sizes and everything still scales 
void Window::Construct(string title,int x, int y, int w, int h,Uint32 flags, int rendererIndex,Uint32 rendererFlags,int logicalWidthDesign, int logicalHeightDesign)
{
  this->Pointer = SDL_CreateWindow(title.c_str(),x,y,w,h,flags);  
  if ( ! this->Pointer )
  {
    this->Pointer = nullptr;
    throw new ExceptionSDL(string("Failed to create window"));
  }
  this->Renderer = SDL_CreateRenderer(this->Pointer,rendererIndex,rendererFlags);  
  if ( ! this->Renderer )
  {
    throw new ExceptionSDL(string("Failed to create a renderer")); 
  }
  SDL_RenderSetLogicalSize(this->Renderer, w, h); //SDL will do all the image scaling, we just scale to the with and height!
  this->LogicalSize.Height = h;
  this->LogicalSize.Width = w;
  this->LogicalSizeDesign.Width = logicalWidthDesign; 
  this->LogicalSizeDesign.Height = logicalHeightDesign; 
}

Window::~Window(void)
{
  if ( this->Renderer )
  {
    SDL_DestroyRenderer(this->Renderer);
    this->Renderer = nullptr;   
  }
  if ( this->Pointer )
  {
    SDL_DestroyWindow(this->Pointer);
    this->Pointer = nullptr;
  }  
}

void Window::Render(void)
{
  SDL_RenderPresent(this->Renderer);
}

void Window::Update(void)
{
  //get the window size?
}

void Window::Clear(void)
{
  SDL_RenderClear(this->Renderer);
}

void Window::RenderDebugText(const string& message, POINT pt)
{    
  RECT rect;

  rect.X = pt.X;
  rect.Y = pt.Y;
  rect.Width = 400;
  rect.Height = 400;
  this->RenderText(message,Game::GameInstance->SystemFont,Game::GameInstance->SystemFontColor,&rect);  
  
}


void Window::RenderText(const string& message, GameFont* font, Color* color, RECT* rectangle )
{    
  Image* image;
  RECT rect;
  if ( message.length() == 0 )
  { return; }
  image = this->CreateTextImage(message, font, color, rectangle->Width);
  rect = *rectangle;
  rect.Width = image->Size.Width;
  rect.Height = image->Size.Height;
  Game::GameInstance->Images->RenderFrame(image, 0,&rect, SDL_ALPHA_OPAQUE,FlipTypeNone);
  delete image;
}

//Todo go into the image manager
Image* Window::CreateTextImage(const string& message, GameFont* font, Color* color, int boundingWith)
{    
  SDL_Surface *surface;
  SDL_Texture *texture;
  Uint32 format;
  int access;
  SIZE sz;

  Image* image;
  
  surface = TTF_RenderText_Blended_Wrapped(font->Font, message.c_str(), (SDL_Color)color->Col(),boundingWith);    
  
  texture = SDL_CreateTextureFromSurface(this->Renderer, surface);    
      //Clean up unneeded stuff    
  SDL_FreeSurface(surface);
  SDL_QueryTexture(texture, &format, &access, &sz.Width, &sz.Height);
  image= new Image(string(""),texture,&sz);
  
  return image;

}

int Window::ScaleToLogicalDesignWidth(int valueUnscaled)
{
  int scaled;

  scaled =  Functions::Scale(valueUnscaled, this->Size().Width,this->LogicalSizeDesign.Width );
  return scaled;
}

int Window::ScaleToLogicalDesignHeight(int valueUnscaled)
{
  int scaled;

  scaled =  Functions::Scale(valueUnscaled,  this->Size().Height, this->LogicalSizeDesign.Height);
  return scaled;
}


SIZE Window::Size()
{
  SIZE sz;

  SDL_GetWindowSize(this->Pointer,&sz.Width, &sz.Height);
  return sz;
}

POINT Window::Position()
{
  POINT pt;

  SDL_GetWindowPosition(this->Pointer,&pt.X, &pt.Y);
  return pt;
}


RECT Window::Rectangle()
{
  SIZE sz;
  POINT pt;
  RECT r;
  pt = this->Position();
  sz = this->Size();
  r.X = pt.X;
  r.Y = pt.Y;
  r.Width = sz.Width;
  r.Height = sz.Height;
  return r;
}
