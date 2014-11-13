#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;


ProgramText::ProgramText(PlayState* playState) : GameObject(), _currentLineNumber(-1), _imageProgramText(nullptr), _fontData(nullptr), _imageProgramPointer(nullptr)
{
  this->_playState = playState;    
  this->Padding.Left = this->Padding.Top = 10;
}


ProgramText::~ProgramText()
{
  this->DeleteTextImage();
  if ( _imageProgramPointer != nullptr )
  {
    delete _imageProgramPointer;
    _imageProgramPointer = nullptr;
  }
  if ( _fontData != nullptr )
  { 
    delete _fontData; 
    _fontData = nullptr;
  }
}


void ProgramText::DeleteTextImage()
{
  if ( this->_imageProgramText != nullptr )
  { 
    delete  this->_imageProgramText;
    this->_imageProgramText = nullptr;
  }  
}
  
void ProgramText::TextSet(string text)
{
  //delete the 
  
  this->_text = text;
  this->_currentLineNumber = 0;

  this->DeleteTextImage();
  

}

void ProgramText::Update()
{
  //get the currrent command
  ProgramCommandData command;
  Color c;
  
  command = this->_playState->GameBoard->RoBot->CommandGet();
  if (command.Command == ProgramCommandEnd || command.Command == ProgramCommandNext || command.Command == ProgramCommandNone)
  { return; }
  this->_currentLineNumber = command.LineNumber;

  if ( this->_imageProgramText == nullptr)
  {
    SIZE_FRAMEWORK sz;
    RECT_FRAMEWORK r;
    
    r = this->Rentangle();
    sz = r.Size();
    //create the text texture;
    this->_imageProgramText = new Image("program_text", MyGame::Instance->Theme->Brick->FirstImage()->Img, &sz);
    MyGame::Instance->WindowMain->RendererTargetSet(this->_imageProgramText);
    SDL_SetRenderDrawColor(MyGame::Instance->WindowMain->Renderer,255,255,255,100);
    SDL_RenderClear(MyGame::Instance->WindowMain->Renderer);

    r.X = this->Padding.Left;
    r.Y = this->Padding.Top;
    SDL_RenderDrawRect(MyGame::Instance->WindowMain->Renderer, NULL);
    MyGame::Instance->WindowMain->RenderText(this->_text, MyGame::Instance->SystemFont, &c, &r, TextAlignTopLeft);
    MyGame::Instance->WindowMain->RendererTargetClear();

    if ( this->_imageProgramPointer == nullptr)
    {
      _fontData = MyGame::Instance->WindowMain->FontDataGet(MyGame::Instance->SystemFont);
      sz.Height = sz.Width = _fontData->LineHeight;      
      this->_imageProgramPointer = new Image("program_pointer", MyGame::Instance->Theme->Brick->FirstImage()->Img, &sz);
      MyGame::Instance->WindowMain->RendererTargetSet(this->_imageProgramPointer);
      SDL_SetRenderDrawColor(MyGame::Instance->WindowMain->Renderer, c.Red(), c.Green(), c.Blue(), c.Alpha());
      SDL_RenderClear(MyGame::Instance->WindowMain->Renderer);
      MyGame::Instance->WindowMain->RendererTargetClear();
    
    }
  }

}

void ProgramText::Render()
{
  RECT_FRAMEWORK r;
  POINT_FRAMEWORK ptProgramMarker;
  if (this->_imageProgramText == nullptr)
  { return; }

  r = this->Rentangle();
  
  MyGame::Instance->Images->RenderWholeImage(this->_imageProgramText, &r,255, FlipTypeNone);
  if ( this->_currentLineNumber != 0 )
  {
    r.X += 1;
    r.Y += this->Padding.Top;
    r.Y += (this->_currentLineNumber - 1) * this->_fontData->LineHeight;
    r.Height = r.Width = this->_imageProgramPointer->Size.Height;
    MyGame::Instance->Images->RenderWholeImage(this->_imageProgramPointer, &r, 255, FlipTypeNone);
  }
  
}