#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

Image::Image(string id,SDL_Texture* texture, SIZE* size) 
{
  this->Construct(id, texture,size,1,1,1) ;
}

Image::Image(string id,Image* imageAttributes, SIZE* size) 
{
  SIZE sz;
  Uint32 format;
  int access;
  SDL_Texture* texture;

  SDL_QueryTexture(imageAttributes->Texture, &format,&access, &sz.Width, &sz.Height);
  texture = SDL_CreateTexture(Game::GameInstance->WindowMain->Renderer, format, SDL_TEXTUREACCESS_TARGET, size->Width, size->Height);
  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND); //alwows transparency

  this->Construct(id,texture,size,1,1,1);  
}



Image::Image( string id, SDL_Texture* texture, SIZE* size,int numberOfFrames, int numberOfFrameRows, int numberOfFramesPerRow )
{
  this->Construct(id, texture, size, numberOfFrames, numberOfFrameRows, numberOfFramesPerRow);
}

void Image::AlphaSet(Uint8 alpha)
{
  SDL_SetTextureAlphaMod(this->Texture,alpha);
}

RECT Image::FrameRectangle(int frame)
{
  RECT rectSource;
  int fullRows,framesInTheFullRows, row, frameInRow;
   
  if ( frame > this->NumberOfFrames - 1 )
  {
    throw new Exception( str(fmt::Format("The frame '{0}' is outside of the number of frames '{1}'") << (frame - 1) << this->NumberOfFrames) );       
  }
    
  frame++; //increment to 1 based for division
  fullRows = frame / this->NumberOfFramesPerRow;
  framesInTheFullRows = fullRows * this->NumberOfFramesPerRow;

  if ( framesInTheFullRows == frame)
  {
    //end of row
    row = fullRows;
    frameInRow = this->NumberOfFramesPerRow;
  }
  else
  {
    row = fullRows + 1;
    frameInRow = frame - framesInTheFullRows;
  }

  row--;
  frameInRow--;

  rectSource.Width = this->Size.Width / this->NumberOfFramesPerRow;
  rectSource.Height = this->Size.Height / this->NumberOfFrameRows;

  rectSource.X = (rectSource.Width) * frameInRow;
  rectSource.Y = (rectSource.Height) * row;
  return rectSource;
}

void Image::Construct( string& id, SDL_Texture* texture, SIZE* size,int numberOfFrames, int intNumberOfFrameRows, int numberOfFramesPerRow )
{
  try
  {    
    this->ID = id;
    this->Texture = texture;
    this->Size = *size;  
    this->NumberOfFrames = numberOfFrames;
    this->NumberOfFrameRows = intNumberOfFrameRows;
    this->NumberOfFramesPerRow = numberOfFramesPerRow;  

    if ( this->NumberOfFrames == 1 )
    {
      this->FrameSize = this->Size;
    }
    else
    {
      this->FrameSize.Height = this->Size.Height / this->NumberOfFrameRows;
      this->FrameSize.Width = this->Size.Width / this->NumberOfFramesPerRow;
    }    
  }

  catch( Exception* ex )
  {
    throw new Exception(string("Failed to create an image: "),ex);
  }
}

Image::~Image(void) 
{
  if ( this->Texture )
  {
    SDL_DestroyTexture(this->Texture);
    this->Texture = nullptr;
  }
}