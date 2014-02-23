#pragma once
#include "StdAfx.h"
#include "FrameWork.h"
using namespace std;

/*
class Image;

ThemeImage::ThemeImage(Image* image, int framesPerSecond, int frameStart, int frameEnd, CycleMode frameCycleMode) 
{
  this->Img = image;
  this->FramesPerSecond = framesPerSecond;
  this->FrameStart = frameStart;
  this->FrameEnd = frameEnd; 
  this->FramesTotal = (this->FrameEnd - this->FrameStart) + 1;
  this->FrmeCycleMode = frameCycleMode;

}

ThemeImage::~ThemeImage(void)
{
}

int ThemeImage::FrameCalculate(int* frameIncrement)
{
   int newFrame;

   newFrame = int(((SDL_GetTicks() / (1000 / this->FramesPerSecond)) % ((this->FramesTotal))));    
   switch( this->FrmeCycleMode )
   {
      case CycleModeLeftToRight:
        break;
      case CycleModeRightToLeft:
        newFrame = (this->FramesTotal - newFrame) - 1; 
        break;
      case CycleModeBackAndForth:
        
        if ( *frameIncrement == 1 )
        {          
          //newFrame = (this->FramesTotal - newFrame) + 1; 
          if ( newFrame == this->FramesTotal  - 1)
          { *frameIncrement = -1; }
        }
        else if ( *frameIncrement == -1 )
        {
          newFrame = ((this->FramesTotal - 1) - (newFrame)); 
          if ( newFrame == 0)
          { *frameIncrement = 1; }
        }
        break;

   }
   return newFrame;
}
*/