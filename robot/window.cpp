#pragma once
#include "stdafx.h"
#include "framework.h"

Window::Window(string title,int x, int y, int w, int h,Uint32 flags, int logicalWidthDesign, int logicalHeightDesign)
{
  //SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC |
  this->Construct(title, x, y, w, h, flags, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC, logicalWidthDesign, logicalHeightDesign);// | SDL_RENDERER_PRESENTVSYNC);
}

Window::Window(string title,int x, int y, int w, int h,Uint32 flags, int rendererIndex,Uint32 rendererFlags,int logicalWidthDesign, int logicalHeightDesign)
{
  this->Construct(title,x,y,w,h,flags,rendererIndex,rendererFlags,logicalWidthDesign,logicalHeightDesign);
}

//logocalDesignSize is the ideal size, if the windows w and h is not ideal we can use the scale functions to scale to the logicalDesign sizes, it really is only for debugging purposes so we 
//can create windows to odd sizes and everything still scales 
void Window::Construct(string title,int x, int y, int w, int h,Uint32 flags, int rendererIndex,Uint32 rendererFlags,int logicalWidthDesign, int logicalHeightDesign)
{
  
  #if defined(__OPENGL_TEST__)
    this->_windowDrawMode = WindowDrawModeNone;
    flags |= SDL_WINDOW_OPENGL;
  #endif

  this->Pointer = SDL_CreateWindow(title.c_str(),x,y,w,h,flags);  
  
  #if defined(__OPENGL_TEST__)
    rendererIndex = this->RendererIndex("opengl");
  #endif

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
  
  #if defined(__OPENGL_TEST__)
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  #endif

  SDL_RenderSetLogicalSize(this->Renderer, w, h); //SDL will do all the image scaling, we just scale to the with and height!
  this->LogicalSize.Height = h;
  this->LogicalSize.Width = w;
  this->LogicalSizeDesign.Width = logicalWidthDesign; 
  this->LogicalSizeDesign.Height = logicalHeightDesign; 
  
}

#if defined (__OPENGL_TEST__)
void Window::DrawModeSet(WindowDrawMode windowDrawMode)
{
  SIZE_FRAMEWORK sz;

  if (windowDrawMode != _windowDrawMode)
  {
    sz = this->Size();
    switch (windowDrawMode)
    {
      case WindowDrawMode2D:
        glMatrixMode(GL_MODELVIEW);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //glPushMatrix();        ----Not sure if I need this
        glOrtho(0, sz.Width, sz.Height, 0, -1, 1);
        glViewport(0, 0, sz.Width, sz.Height);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glDisable(GL_CULL_FACE);
        glDisable(GL_DEPTH_TEST);

        this->_windowDrawMode = windowDrawMode;       
        break;
      case WindowDrawMode3D:
        
        glPopMatrix(); //From 2D
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        this->gluPerspective(45.0f, 4.0f / 3.0f, 0.1f, 1000.0f); //isometric??, see 

        glViewport(0, 0, sz.Width, sz.Height);
        glMatrixMode(GL_MODELVIEW);

        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);
        

        this->_windowDrawMode = windowDrawMode;        
        break;
    }
  }
}


void Window::gluPerspective(float fovy, float aspect, float zNear, float zFar)
{
  // Start in projection mode.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  double xmin, xmax, ymin, ymax;
  ymax = zNear * tan(fovy * M_PI / 360.0);
  ymin = -ymax;
  xmin = ymin * aspect;
  xmax = ymax * aspect;
  glFrustum((GLdouble)xmin, (GLdouble)xmax, (GLdouble)ymin, (GLdouble)ymax, (GLdouble)zNear, (GLdouble)zFar);
  //glFrustumf(xmin, xmax, ymin, ymax, zNear, zFar);
}
#endif

int Window::RendererIndex(string  nameSearchMatch)
{
  int nRD;
  int i;
  SDL_RendererInfo info;;

  nRD = SDL_GetNumRenderDrivers();
  for (i = 0; i < nRD; i++)
  {
    
    if (!SDL_GetRenderDriverInfo(i, &info))
    {
      if (Functions::StrPos(info.name, nameSearchMatch) != -1)
      {
        return i;
      }
      
    }
  } 
  return -1;
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

void Window::RendererTargetSet(Image* image)
{
  if (image == nullptr)
  { 
    SDL_SetRenderTarget(this->Renderer,NULL);
  }
  else
  {
    SDL_SetRenderTarget(this->Renderer, image->Texture);
  }
}

void Window::RendererTargetClear()
{
  this->RendererTargetSet(nullptr);
}

void RendererTargetClear();

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

void Window::RenderDebugText(const string& message, RECT_FRAMEWORK* rectangle, TextAlign textAlignment)
{    
  this->RenderText(message, Game::GameInstance->SystemFont, Game::GameInstance->SystemFontColor, rectangle, textAlignment);  
}

void Window::RenderText(const string& message, GameFont* font, Color* color, RECT_FRAMEWORK* rectangle, TextAlign textAlignment, bool wrap )
{    
  Image* image;
  RECT_FRAMEWORK rectposition;
  int wrapWidth;
  if ( message.length() == 0 )
  { return; }
  
  if (wrap)
  { wrapWidth = rectangle->Width; }
  else
  { wrapWidth = 0; }

  image = this->CreateTextImage(message, font, color,wrapWidth);
  rectposition = *rectangle;
  rectposition.Width = image->Size.Width;
  rectposition.Height = image->Size.Height;
  switch (textAlignment)
  {
    case TextAlignTopLeft:
      break;
    case TextAlignMiddleCenter:
      if (image->Size.Width < rectangle->Width)
      { rectposition.X += (rectangle->Width - image->Size.Width) / 2; }
      if (image->Size.Height < rectangle->Height)
      { rectposition.Y += (rectangle->Height - image->Size.Height) / 2; }
      break;
  }
  
  Game::GameInstance->Images->RenderFrame(image, 0,&rectposition, SDL_ALPHA_OPAQUE,FlipTypeNone);
  delete image;
}

//Todo go into the image manager
Image* Window::CreateTextImage(const string& message, GameFont* font, Color* color, int wrapWidth )
{    
  SDL_Surface *surface;
  SDL_Texture *texture;
  Uint32 format;
  int access;
  SIZE_FRAMEWORK sz;
  Image* image;
  
  surface = this->CreateTextSurface(message, font, color, wrapWidth);
  texture = SDL_CreateTextureFromSurface(this->Renderer, surface);    
  //Clean up unneeded stuff    
  SDL_FreeSurface(surface);
  SDL_QueryTexture(texture, &format, &access, &sz.Width, &sz.Height);
  image= new Image(string(""),texture,&sz);  
  return image;
}

SDL_Surface* Window::CreateTextSurface(const string& message, GameFont* font, Color* color, int wrapWidth)
{
  SDL_Surface *surface;

  if (wrapWidth < 1)
  {
    wrapWidth = 4000; //make large so no auto wrapping occurs. We have to always use wrap otherwise \n are not taken into account
  }
  surface = TTF_RenderText_Blended_Wrapped(font->Font, message.c_str(), (SDL_Color)color->Col(), wrapWidth);
  return surface;
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


SIZE_FRAMEWORK Window::Size()
{
  SIZE_FRAMEWORK sz;

  SDL_GetWindowSize(this->Pointer,&sz.Width, &sz.Height);
  return sz;
}

POINT_FRAMEWORK Window::Position()
{
  POINT_FRAMEWORK pt;

  SDL_GetWindowPosition(this->Pointer,&pt.X, &pt.Y);
  return pt;
}


RECT_FRAMEWORK Window::Rectangle()
{
  SIZE_FRAMEWORK sz;
  POINT_FRAMEWORK pt;
  RECT_FRAMEWORK r;
  pt = this->Position();
  sz = this->Size();
  r.X = pt.X;
  r.Y = pt.Y;
  r.Width = sz.Width;
  r.Height = sz.Height;
  return r;
}

FontData* Window::FontDataGet(GameFont* font)
{
  SDL_Surface* surface;
  Color c;
  FontData* fontData;

  fontData = new FontData();
  surface = this->CreateTextSurface("A", font, &c, 200);
  fontData->LineHeight = surface->h;
  SDL_FreeSurface(surface);

  surface = this->CreateTextSurface("A\r\nA", font, &c, 200);
  fontData->LineGap = surface->h - (2 * fontData->LineHeight);
  SDL_FreeSurface(surface);

  return fontData;
}
