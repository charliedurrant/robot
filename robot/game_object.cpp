#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

class Game;

GameObject::GameObject() : Position(0, 0), 
                           Size(),
                           Velocity(0, 0),
                           Acceleration(0, 0),
                           _children(nullptr),
                           _flipWithVerticalVelocity(false),
                           _flipWithHorizontalVelocity(true),
                           CurrentThemeObject(nullptr),
                           _flip(FlipTypeNone),  
                           Visible(true), _onClickCallBack(nullptr), ParentState(nullptr), DebugInfoTextAlign(TextAlignTopLeft), BackgorundImage(nullptr)
{  
  ;
}

GameObjects* GameObject::Children()
{
  if ( this->_children == nullptr )
  {
    this->_children = new GameObjects();    
  }
  return this->_children;
}

GameObject::~GameObject()
{
  if ( this->_children )
  {
    delete this->_children;      
    this->_children = nullptr;
  }
} 

bool GameObject::Contains( Vector2D* position )
{
  POINTF point;
  POINTF myPoint;
  
  point.X = position->X;
  point.Y = position->Y;

  myPoint.X = this->Position.X;
  myPoint.Y = this->Position.Y;

  if ( (point.X < this->Size.Width + myPoint.X) && (point.X > myPoint.X) )
  {
    if ( (point.Y < this->Size.Height + myPoint.Y) && (point.Y > myPoint.Y) )
    {
      return true;      
    }     
  }
  return false;  
}


bool GameObject::ContainsMouse()
{
  return this->Contains( Game::GameInstance->Input->Mouse->Position );
}


void GameObject::Update()
{
  POINTF point;
  GameObject* captured;
  if ( ! this->Visible )
  { return; }

  if ( this->CurrentThemeObject )
  {
    GameObject::UpdateThemeObject(this,this->CurrentThemeObject);
  }
  
  this->Velocity += this->Acceleration;
  this->Position += this->Velocity;

  //set flip flag according to velocity
  point = this->Velocity.PointF();
  if (_flipWithHorizontalVelocity)
  {
    if (point.X < 0)
    { _flip = (FlipType)(_flip | FlipTypeHorizontal); }
    else
    { _flip = (FlipType)(_flip & ~FlipTypeHorizontal); }
  }

  if (_flipWithVerticalVelocity)
  {
    if (point.Y < 0)
    { _flip = (FlipType)(_flip | FlipTypeVertical); }
    else
    { _flip = (FlipType)(_flip & ~FlipTypeVertical); }
  }  
  
  if ( _children  )
  {
    _children->Update();
  }

  if ((Game::GameInstance->Input->Mouse->LeftButton == MouseButtonClicked) && this->ContainsMouse() )
  { 
    captured = Game::GameInstance->Input->Mouse->GetCapture();
    if ( (captured != nullptr && captured == this) || captured == nullptr )
    {      
      this->Click(this); ///can be overriden
      if (_onClickCallBack != nullptr)
      {
        this->_onClickCallBack(this);   //the envet handler
      }      
    }    
  }
}

void GameObject::UpdateThemeObject(GameObject* gameObject,ThemeObject* themeObject)
{
  size_t i, length;
  ThemeObjectImage* themeObjectImage;
  
  length = themeObject->ObjectImages.size();
  //this is where we change the frames / alpha etc and decide if it renders??
  if ( gameObject  && gameObject->ContainsMouse() )
  {
    for( i = 0; i < length; i++ )
    {
      themeObjectImage = themeObject->ObjectImages[i]; 
      themeObjectImage->Render = themeObjectImage->MouseOver;
      if ( Game::GameInstance->Input->Mouse->LeftButton )
      { themeObjectImage->Render = themeObjectImage->MouseDown; }
    }
  }
  else
  {
    for( i = 0; i < length; i++ )
    {
      themeObjectImage = themeObject->ObjectImages[i]; 
      themeObjectImage->Render = themeObjectImage->MouseOut;
    }    
  }
  
  
  for( i = 0; i < length; i++ )
  {    
    themeObjectImage = themeObject->ObjectImages[i];   
    if ( themeObjectImage->Render )
    {
      if ( themeObjectImage->AutomaticallyCalculateFrame )
      {
        if ( themeObjectImage->FrameData.HasFramesToClycle())
        {
          themeObjectImage->FrameData.Current = themeObjectImage->FrameData.Start +  themeObjectImage->Img->FrameCalculate( themeObjectImage->FrameData.PerSecond, themeObjectImage->FrameData.Total);
        }
        else
        {
          themeObjectImage->FrameData.Current = themeObjectImage->FrameData.Start;
        }
      }
      //TODO: alphastep??
      if ( themeObjectImage->AlphaData.HasFramesToClycle() )
      {        
        //newValue = themeObjectImage->AlphaData.Start +  themeObjectImage->Img->FrameCalculate(themeObjectImage->AlphaData.PerSecond, themeObjectImage->AlphaData.Total);

        themeObjectImage->FrameCalculate(&themeObjectImage->AlphaData);

        /*
        if ( newValue < themeObjectImage->AlphaData.Current && themeObjectImage->AlphaData.CycleIncrement == 1 ) //cycled around, change the increment
        {
           themeObjectImage->AlphaData.CycleIncrement = -1;
        }
        else if ( newValue > themeObjectImage->AlphaData.Current && themeObjectImage->AlphaData.CycleIncrement == -1 )
        {
          themeObjectImage->AlphaData.CycleIncrement = 1;
        }

        if ( themeObjectImage->AlphaData.CycleIncrement == 1 )
        {
          themeObjectImage->AlphaData.Current = newValue;
        }
        else
        {
          themeObjectImage->AlphaData.Current = themeObjectImage->AlphaData.End - newValue;
        }
        */
      }
      else if ( themeObjectImage->AlphaData.Start != SDL_ALPHA_OPAQUE )
      {
        themeObjectImage->AlphaData.Current = themeObjectImage->AlphaData.Start;
      }
      
    }   
  }
}

RECT_FRAMEWORK GameObject::Rentangle()
{
  POINT_FRAMEWORK pt;
  RECT_FRAMEWORK r;
  
  pt = this->Position.Point();
  r.X = pt.X;
  r.Y = pt.Y;
  r.Width = this->Size.Width;
  r.Height = this->Size.Height;
  return r;
}

void GameObject::PositionAndSize(RECT_FRAMEWORK r) { this->PositionAndSize((float)r.X, (float)r.Y, r.Width, r.Height); }

void GameObject::PositionAndSize(int x, int y, int width, int height) { this->PositionAndSize((float)x, (float)y, width, height); }

void GameObject::PositionAndSize(Vector2D* position, int width, int height) { this->PositionAndSize(position->X, position->Y, width, height); }

void GameObject::PositionAndSize(float X, float Y, int width, int height)
{
  this->Position.X = X;
  this->Position.Y = Y;
  this->Resize(width, height);  
}

void GameObject::Resize(int width, int height )
{
  this->Size.Width = width;
  this->Size.Height = height;  
}

RECT_FRAMEWORK GameObject::RectangleLessPadding()
{
  RECT_FRAMEWORK r;

  r = this->Rentangle();
  r.Width -= this->Padding.Left + this->Padding.Right;
  r.X += this->Padding.Left;

  r.Height -= this->Padding.Top + this->Padding.Bottom;
  r.Y += this->Padding.Top;
  return r;
}

void GameObject::Render()
{
  this->RenderBackground();

  if ( _children  )
  { _children->Render(); }

  if ( this->CurrentThemeObject != nullptr )
  { this->CurrentThemeObject->Render(this->RectangleLessPadding()); }   
}

void GameObject::RenderBackground()
{
  if (this->BackgorundImage)
  { this->BackgorundImage->Render(this->Rentangle()); }
}

void GameObject::RenderDebugInfo() 
{   
  if ( ! this->Visible )
  { return; }
  this->RenderDebugInfo(this->Rentangle().ToString());  
}

void GameObject::RenderDebugInfo(string& text)
{
  RECT_FRAMEWORK r;

  if (!this->Visible)
  { return; }

  r = this->Rentangle();
  Game::GameInstance->WindowMain->RenderDebugText(text, &r, this->DebugInfoTextAlign);
  if (_children)
  { _children->RenderDebugInfo(); }
}

void GameObject::Clean(){ ; }


void GameObject::Accelerate(float value)
{
  float x, y;
  x = (float)Velocity.X;
  
  if ( x < 0 )
  { x = value * -1;  }
  else if ( x > 0 )
  { x = value; }
  else
  { x = 0; }

  y = (float)this->Velocity.Y;

  if ( y < 0 )
  { y = value * -1; }
  else if ( y > 0 )
  { y = value; }
  else
  { y = 0; }

  this->Acceleration.X = x;
  this->Acceleration.Y = y;  
}

//see http://stackoverflow.com/questions/14189440/c-class-member-callback-simple-examples
void GameObject::OnClick(std::function<void(void*)> onClickCallBack)
{  
  this->_onClickCallBack = onClickCallBack;
}

void GameObject::Click(void* sender)
{
  
}
