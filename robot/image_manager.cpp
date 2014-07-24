#pragma once
#include "stdafx.h"
#include "framework.h"

using namespace std;
using namespace fmt;

class Image;

ImageManager::ImageManager(Window *window) : _window(nullptr), RenderCounter(0)
{
  this->_window = window;
}

ImageManager::~ImageManager(void)
{
  //delete all the images
  for (auto it=this->_imageMap.begin(); it!=this->_imageMap.end(); ++it)
  {
    delete it->second;
    it->second = nullptr;
  }
  _imageMap.clear();
}

bool ImageManager::Contains(string& key)
{  
  auto it = _imageMap.find(key);
  return it != _imageMap.end();  
}

Image* ImageManager::Load(string key, string resourcePath)
{
  Image* image = nullptr;

  image = ImageManager::Load(key, resourcePath, 1, 1, 1);
 
  return image;
}

Image* ImageManager::Load(string key, string resourcePath, int numberOfFrames, int numberOfFrameRows, int numberOfFramesPerRow)
{
  Image* image = nullptr;
  SDL_Texture* texture = nullptr;
  SIZE_FRAMEWORK sz;
  try
  {
    if ( this->Contains(key) )
    { return this->Item(key);  }
    
    texture = IMG_LoadTexture(this->_window->Renderer,resourcePath.c_str());
    if ( ! texture )
    { throw new ExceptionSDL(string("Failed to create a texture")); }
    
    SDL_QueryTexture(texture,nullptr,nullptr,&sz.Width,&sz.Height);
    image = new Image(key, texture,&sz, numberOfFrames, numberOfFrameRows, numberOfFramesPerRow);    
    _imageMap[key] = image;
  }
  catch( Exception* ex )
  {
    if ( texture ) { SDL_DestroyTexture(texture) ; texture = nullptr; } 
    throw new Exception(string("Failed to add image to the manager: ") + resourcePath,ex); 
  }
  
  return image;
}

Image* ImageManager::Load(string key, string& resourceRoot, TiXmlElement* xmlElement)
{
  string path;
  Image* image;
  int numberOfFrames, numberOfFrameRows, numberOfFramesPerRow;

  path = resourceRoot + xmlElement->Attribute("src");

  numberOfFrames = 1;
  xmlElement->Attribute("frames",&numberOfFrames);
    
  numberOfFrameRows = -1;
  xmlElement->Attribute("rows",&numberOfFrameRows);
    
  numberOfFramesPerRow = -1;
  xmlElement->Attribute("frames_per_row",&numberOfFramesPerRow);
  if ( numberOfFramesPerRow == -1 && numberOfFrameRows == -1 )
  {
    numberOfFrameRows = 1;
    numberOfFramesPerRow = numberOfFrames;
  } 

  image = Load(key, path,numberOfFrames,numberOfFrameRows, numberOfFramesPerRow);    
  return image;
}



Image* ImageManager::Item(string& key)
{
  auto it = this->_imageMap.find(key);

  if ( it == this->_imageMap.end() )
  {
    throw new Exception("Failed to find image with key :" + key);
  }
  
  return it->second;
}


void ImageManager::Render( Image* image,RECT_FRAMEWORK* rectangleSource, RECT_FRAMEWORK* rectangleDestination, Uint8 alpha, FlipType flip  )
{
  Uint8 alphaCurrent;

  SDL_GetTextureAlphaMod(image->Texture,&alphaCurrent);
  if ( alphaCurrent != alpha )
  { SDL_SetTextureAlphaMod(image->Texture, alpha); } //probably not required
  
  if ( SDL_RenderCopyEx(this->_window->Renderer,image->Texture,(SDL_Rect*)rectangleSource,(SDL_Rect*)rectangleDestination, 0,0,(SDL_RendererFlip)flip) )
  {
    throw new ExceptionSDL("Failed to RenderCopy the texture: " + image->ID);
  }
  this->RenderCounter++;
}

void ImageManager::RenderFrame( Image* image,int frame, RECT_FRAMEWORK* rectangleDestination, Uint8 alpha, FlipType flip  )
{
  RECT_FRAMEWORK rectangleSource;

   rectangleSource = image->FrameRectangle(frame);
   this->Render(image, &rectangleSource, rectangleDestination,alpha, flip);  
}


void ImageManager::RenderWholeImage( Image* image,RECT_FRAMEWORK* rectangleDestination, Uint8 alpha, FlipType flip  )
{
  this->Render(image, nullptr,rectangleDestination,alpha, flip);
}

void ImageManager::RenderTile( Image* image,RECT_FRAMEWORK* rectDestination, Uint8 alpha, FlipType flip  )
{
  SIZE_FRAMEWORK sz;
  RECT_FRAMEWORK rectangleSource, rectangleDestination;
  POINT_FRAMEWORK ptBottomRight;
  POINT_FRAMEWORK maxXY, pt;
  
  sz = image->Size;
  rectangleSource.X = 0;
  rectangleSource.Y = 0;
  
  ptBottomRight.X = rectDestination->Right();
  ptBottomRight.Y = rectDestination->Bottom();

  maxXY.X = (int)ceil((float)rectDestination->Width /  (float)image->Size.Width);
  maxXY.Y = (int)ceil((float)rectDestination->Width /  (float)image->Size.Width);
  
  for( pt.X = 0; pt.X < maxXY.X; pt.X ++ )
  {
    //trim rect in X
      
    if ( pt.X == maxXY.X - 1 )
    { rectangleDestination.Width = rectDestination->Right() - (pt.X * image->Size.Width); }
    else
    { rectangleDestination.Width = image->Size.Width; }

    rectangleDestination.X = rectDestination->X +  (pt.X * image->Size.Width);
    rectangleSource.Width = rectangleDestination.Width;

    for( pt.Y = 0; pt.Y < maxXY.Y; pt.Y++ )
    {
      //trim rect in Y
      if ( pt.Y == maxXY.Y - 1 )
      { rectangleDestination.Height = rectDestination->Bottom() - (pt.Y * image->Size.Height); }
      else
      { rectangleDestination.Height = image->Size.Height; }

      rectangleDestination.Y = rectDestination->Y +  (pt.Y * image->Size.Height);
      rectangleSource.Height = rectangleDestination.Height;

      if (SDL_RenderCopyEx(this->_window->Renderer, image->Texture, (SDL_Rect*)&rectangleSource, (SDL_Rect*)&rectangleDestination, 0, 0, (SDL_RendererFlip)flip))
      {
        throw new ExceptionSDL("Failed to RenderCopy the texture from an image");
      }
      this->RenderCounter++;
    }
  }  
  this->Render(image, nullptr,&rectangleDestination,alpha, flip);
}

