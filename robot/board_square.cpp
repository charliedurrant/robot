#pragma once
#include "stdafx.h"
#include "headers.h"

using namespace std;

BoardSquare::BoardSquare(Board* board) : GameObject(), BrickCount(0), _lightState(LightStateNone), RenderOrder(-1), Rendered(false)
{
  this->CurrentThemeObject = MyGame::Instance->Theme->Tile2;
  _board = board;
  this->DebugInfoTextAlign = TextAlignMiddleCenter;
}

BoardSquare::~BoardSquare()
{ ; }

void BoardSquare::Render()
{
  Image* image;
  RECT_FRAMEWORK rectangle;
  size_t i;
  
  //render a tile;
  if ( this->BrickCount > 0 )
  {
    if (MyGame::Instance->Settngs->RenderBricksAsTowerBlocks && this->BrickCount > 1)
    {      
      image = _board->_towerBlocks[this->BrickCount - 1];
      rectangle = *this->RectangleRenderBase;
      rectangle.Height = image->Size.Height;
      rectangle.Y = this->RectangleRenderBase->Bottom() - rectangle.Height;            
      MyGame::Instance->Images->Render(image,nullptr, &rectangle,SDL_ALPHA_OPAQUE,FlipTypeNone);      
    }    
    else
    {
      rectangle = *this->RectangleRenderBase;
      rectangle.Width = _board->BrickData.Size.Width;
      rectangle.Height = _board->BrickData.Size.Height;        
      for (i = 1; i < this->BrickCount + 1; i++)
      {
        rectangle.Y -= _board->BrickData.VerticalDrawOffset;
        MyGame::Instance->Theme->Brick->Render(rectangle);        
      }
    }
  }
  this->RenderTile();
  this->Rendered = true;
}


void BoardSquare::RenderDebugInfo()
{
  string s;
  
  this->PositionAndSize(this->RectangleRenderTop); //need this as we don't use the gameobjects rectangle
  /* Coords */
  //s = str(fmt::Format("Render cord: {0}\nCoord: {1}") << this->CoordinateRender.ToString() << this->Coordinate.ToString() );  
  
  /* Render order */
  s = str(fmt::Format("{0}") << this->RenderOrder ); 
  GameObject::RenderDebugInfo(s);  
}

//done in the board. the image cycling is done by the board to keep things in sync
void BoardSquare::Update()
{
  ;
}


void BoardSquare::RenderTile()
{
  
  if ( this->BrickCount == 0 && this->_lightState == LightStateNone )
  {
    if ( ! MyGame::Instance->Settngs->RenderBoardInOneGo )
    { this->CurrentThemeObject->Render(this->RectangleRenderTop); }
  }
  else
  {
    this->CurrentThemeObject->Render(this->RectangleRenderTop);    
  }    
}

void BoardSquare::RenderFloorTileOnly(SIZE_FRAMEWORK moveBy)
{
   RECT_FRAMEWORK rectangleRenderBase;
   LightState lightState;
   int brickCount;

   //get current state
   rectangleRenderBase = *this->RectangleRenderBase;
   brickCount = this->BrickCount;
   lightState = this->LightStateGet();

   //adjust current state
   rectangleRenderBase.MoveBy(moveBy);
   
   this->LightStateSet(LightStateNone);
   this->BrickCount = 0;

   this->CurrentThemeObject->Render(rectangleRenderBase);
   
   //put back current state
   this->BrickCount = brickCount;
   this->LightStateSet(lightState);

}


void BoardSquare::LightStateSet(LightState lightState)
{
  if ( lightState != _lightState )
  {
    switch ( lightState )
    {
      case LightStateOn:
        this->CurrentThemeObject = MyGame::Instance->Theme->TileOn2;
        break;
      case LightStateOff:
        this->CurrentThemeObject = MyGame::Instance->Theme->TileOff2;
        break;
      case LightStateNone:
        this->CurrentThemeObject = MyGame::Instance->Theme->Tile2;
        break;
    }
  }
  _lightState = lightState;
}


LightState BoardSquare::LightStateGet()
{
  return _lightState;
}

void BoardSquare::LightStateSwitch()
{
  if ( _lightState == LightStateNone )
  { return; }
  if ( _lightState == LightStateOff )
  { this->LightStateSet(LightStateOn); }
  else
  { this->LightStateSet(LightStateOff); }   
}




