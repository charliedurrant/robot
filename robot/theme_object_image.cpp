#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

class Image;
class GameTheme;

ThemeObjectImage::ThemeObjectImage (Image* image, 
  int framesPerSecond, int frameStart, int frameEnd, CycleMode frameCycleMode, 
   int alphaPerSecond, int alphaStart, int alphaEnd, int alphaStep, CycleMode alphaCycleMode
  
   ) : Flip(FlipTypeNone), _imageIsMine(false), _text("")
{
  
  this->Img = image;
  this->FrameData.Start = frameStart;
  this->FrameData.End = frameEnd;
  this->FrameData.PerSecond = framesPerSecond;
  this->FrameData.Current = this->FrameData.Start;
  this->FrameData.Total = this->FrameData.TotalCalculate();

  this->AlphaData.Start = alphaStart;
  this->AlphaData.End = alphaEnd;
  this->AlphaData.PerSecond = alphaPerSecond;
  this->AlphaData.Current = this->AlphaData.Start;
  this->AlphaData.Total = this->AlphaData.TotalCalculate();
  this->MouseDown = true;
  this->MouseOver = true;
  this->MouseOut = true;
}

ThemeObjectImage::ThemeObjectImage (BaseGameTheme* theme, TiXmlElement* xmlElement) 
{
  string imageID;
  Image* image;
  const int NO_DATA = -99999;

  imageID = xmlElement->Attribute("image");
  if ( ! Game::GameInstance->Images->Contains(imageID) )
  {         
    image = theme->ImageGet2(imageID);    
  }
  else
  { image = Game::GameInstance->Images->Item(imageID); }

  this->Img = image;
  this->TextSet(Functions::XMLAttributeString(xmlElement, "text", ""));
  this->FrameData.PerSecond = Functions::XMLAttributeInt(xmlElement,"frames_per_second",0);
  
  this->FrameData.Start = Functions::XMLAttributeInt(xmlElement, "frame", NO_DATA);
  if ( this->FrameData.Start < 0 ) //we exepct frame start and end
  {
     this->FrameData.Start = Functions::XMLAttributeInt(xmlElement,"frame_start",1);
     this->FrameData.End = Functions::XMLAttributeInt(xmlElement, "frame_end", 1);
  }
  else
  { this->FrameData.End = this->FrameData.Start; }
  this->FrameData.Total = this->FrameData.TotalCalculate();
  
  this->FrameData.CyclMode = BaseGameTheme::CycleMde(xmlElement,"frame_cycle_mode",CycleModeLeftToRight);
  this->FrameData.Reset();
  
  
  this->AlphaData.PerSecond = Functions::XMLAttributeInt(xmlElement,"alpha_per_second",1);

  this->AlphaData.Start = Functions::XMLAttributeInt(xmlElement, "alpha", NO_DATA);
  if (this->AlphaData.Start < 0)
  {
    this->AlphaData.Start = Functions::XMLAttributeInt(xmlElement, "alpha_start", SDL_ALPHA_OPAQUE);
    this->AlphaData.End = Functions::XMLAttributeInt(xmlElement, "alpha_end", SDL_ALPHA_OPAQUE);
  }
  else
  { this->AlphaData.End = this->AlphaData.Start; }
  this->AlphaData.Total = this->AlphaData.TotalCalculate();
  
  this->AlphaData.CyclMode = BaseGameTheme::CycleMde(xmlElement,"alpha_cycle_mode",CycleModeBackAndForth);  
  this->AlphaData.Reset();
  
  if ( ! Functions::XMLAttributeExists(xmlElement, "mouse_out") && ! Functions::XMLAttributeExists(xmlElement, "mouse_over") & ! Functions::XMLAttributeExists(xmlElement, "mouse_down") )
  {
    this->MouseDown = true;
    this->MouseOver = true;
    this->MouseOut = true;
  }
  else
  {
    this->MouseDown = Functions::XMLAttributeBool(xmlElement,"mouse_down",false);
    this->MouseOver = Functions::XMLAttributeBool(xmlElement,"mouse_over",false);
    this->MouseOut = Functions::XMLAttributeBool(xmlElement,"mouse_out",false);
  }

  this->AutomaticallyCalculateFrame = Functions::XMLAttributeBool(xmlElement,"automatically_calculate_frame",true);
  
  this->Flip = FlipTypeNone;
  if ( Functions::XMLAttributeBool(xmlElement,"flip_horizontal",false) )
  { this->Flip = (FlipType)(this->Flip | FlipTypeHorizontal); }

  if ( Functions::XMLAttributeBool(xmlElement,"flip_vertical",false) )
  { this->Flip = (FlipType)(this->Flip | FlipTypeVertical); }

  this->Tile = Functions::XMLAttributeBool(xmlElement,"tile",false);

  this->Render = true;
  this->_imageIsMine = false;
}


ThemeObjectImage::~ThemeObjectImage(void)
{

}

void ThemeObjectImage::TextSet(string s)
{
  Image* image;
  RECT_FRAMEWORK r;

  if (s == this->_text)
  { return; }

  if (!this->_imageIsMine)
  {
    _originalImage = this->Img;
    this->_imageIsMine = true;
    r.X = r.Y = 0;
    r.SizeSet(_originalImage->FrameSize);
    image = new Image("temp",_originalImage,&_originalImage->FrameSize); //need to fix here as we may have multiple frames, need to create multiple frames and also store the offset as our indexing may be different
    Game::GameInstance->WindowMain->RendererTargetSet(image);
    //copy the image
    Game::GameInstance->Images->RenderFrame(_originalImage,this->FrameData.Start - 1,NULL,SDL_ALPHA_OPAQUE,FlipTypeNone);     
    this->FrameData.End = this->FrameData.Start = 1;
    GameFont* gf =  Game::GameInstance->Fonts->Item(Game::GameInstance->SystemFont->Family,50);
    Game::GameInstance->WindowMain->RenderText(s, gf, Game::GameInstance->SystemFontColor, &r);
    Game::GameInstance->WindowMain->RendererTargetClear();    
    this->Img = image;
  }
  this->_text = s;
}

int ThemeObjectImage::FrameCalculateByPercentage(float percentage)
{
  int frame;
  
  frame = ((int)Functions::Round(((float)(this->FrameData.Total - 1)) * percentage)) + 1;
  //frame -= 1;
  return frame;
}


void ThemeObjectImage::FrameCalculate(FRAME_DATA* frameData)
{
  //I have got to cycle X frames per second

  //this say I do a certain frame at a certain offset in a second, depending on when we 
  //call this function we get a different frame and thus 

  int delta;
  int newFrame = 0;
  float secondsElapsed;
  int frameIncrement;

  if ( frameData->HasFramesToClycle() )
  {
    //Game::GameInstance->SecondsDeltaUpdate
    delta = Game::GameInstance->TicksCurrentUpdate - frameData->LastTicks;
    secondsElapsed = (float)delta / 1000.0f;
    frameIncrement =  (int)(secondsElapsed * (float)frameData->PerSecond);;

    if ( frameIncrement > 0 )
    {
      switch( frameData->CyclMode )
      {
        case CycleModeLeftToRight:
          break;
        case CycleModeRightToLeft:
          newFrame = (frameData->Current - frameIncrement) ; 
          if ( newFrame <= 0)
          { 
            frameData->CycleIncrement = 1; 
            newFrame = frameData->End;
          }
          break;
        case CycleModeBackAndForth:        
          if ( frameData->CycleIncrement == 1 )
          {          
            newFrame = (frameData->Current  + frameIncrement); 
            //newFrame = (this->FramesTotal - newFrame) + 1; 
            if ( newFrame >= frameData->End)
            { 
              frameData->CycleIncrement = -1; 
              newFrame = frameData->End;
            }
          }
          else if ( frameData->CycleIncrement == -1 )
          {
            newFrame = (frameData->Current  - frameIncrement); 
            if ( newFrame <= 0)
            { 
              frameData->CycleIncrement = 1; 
              newFrame = frameData->Start;
            }
          }
          break;

      }
      frameData->Current = newFrame;
      frameData->LastTicks = Game::GameInstance->TicksCurrentUpdate; //if we have moved a frame, store the current ticks
    }
   }
   /*
   int framesToStep = (int)(f * (float)frameData->Total);

   newFrame = frameData->Current + framesToStep;
   */
   if ( newFrame > frameData->Total - 1 )
   {
     newFrame = frameData->Start;
   }
   /*
   if ( frameData->CycleIncrement < 0 )
   {
      framesToStep *= -1;
   }
   */
   


   /*
   //newFrame = int(((SDL_GetTicks() / (1000 / this->FrameData.PerSecond)) % ((this->FrameData.Total))));    
   switch( this->FrameData.CyclMode )
   {
      case CycleModeLeftToRight:
        break;
      case CycleModeRightToLeft:
        newFrame = (frameData->Total - newFrame) - 1; 
        break;
      case CycleModeBackAndForth:        
        if ( frameData->CycleIncrement == 1 )
        {          
          //newFrame = (this->FramesTotal - newFrame) + 1; 
          if ( newFrame == frameData->Total  - 1)
          { frameData->CycleIncrement = -1; }
        }
        else if ( frameData->CycleIncrement == -1 )
        {
          newFrame = ((frameData->Total - 1) - (newFrame)); 
          if ( newFrame == 0)
          { frameData->CycleIncrement = 1; }
        }
        break;

   }
   */
   //frameData->Current = newFrame;
}