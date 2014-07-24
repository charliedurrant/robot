#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

ThemeObject::ThemeObject(BaseGameTheme* theme, string id, TiXmlElement* xmlElement) 
{
  ThemeObjectImage* objectImage;
  TiXmlElement* objectImages;

  try
  {
    this->ID = id;  
   
    this->ScaleToParent = Functions::XMLAttributeFloat(xmlElement,"scale_to_parent",1.0f);

    objectImages = Functions::XMLFindFirstChildByName(xmlElement,"object_images");
    if ( objectImages == nullptr )
    { throw new Exception("Could not find the object_images element under the theme_object element"); }
    for(TiXmlElement* objectImageElement = objectImages->FirstChildElement(); objectImageElement != NULL; objectImageElement = objectImageElement->NextSiblingElement())
    {    
      objectImage = new ThemeObjectImage(theme,objectImageElement);
      this->ObjectImages.push_back(objectImage);      
    } 
  }
  catch( Exception* ex )
  {
    throw new Exception(str(fmt::Format("Failed to create a theme object with id='{0}'") << id),ex);
  }
}

void ThemeObject::Reset()
{
  ThemeObjectImage* objectImage;
 
  for(std::vector<ThemeObjectImage*>::size_type i = 0; i <  this->ObjectImages.size(); i++)
  {
    objectImage = this->ObjectImages[i];
    objectImage->AlphaData.Reset();
    objectImage->FrameData.Reset();
  }  
}

void ThemeObject::Render(RECT_FRAMEWORK rectangleDestination)
{
  ThemeObjectImage* objectImage;
  
  size_t size = this->ObjectImages.size();

  for(std::vector<ThemeObjectImage*>::size_type i = 0; i <  size; i++)
  {
    objectImage = this->ObjectImages[i];
    if ( ! objectImage->Render )
    { continue; }
    
    if ( objectImage->Tile )
    {
      Game::GameInstance->Images->RenderTile(objectImage->Img,&rectangleDestination, objectImage->AlphaData.Current,objectImage->Flip );  
    }
    else
    {
      Game::GameInstance->Images->RenderFrame(objectImage->Img,objectImage->FrameData.Current - 1,&rectangleDestination, objectImage->AlphaData.Current,objectImage->Flip );      
    }   
  }   
}

ThemeObject::ThemeObject( const ThemeObject* toCopy )
{
  const ThemeObjectImage* objectImageToCopy;
  ThemeObjectImage* objectImageNew;
  this->ID = string(toCopy->ID);

  for(std::vector<ThemeObjectImage*>::size_type i = 0; i <  toCopy->ObjectImages.size(); i++)
  {
    objectImageToCopy = toCopy->ObjectImages[i];
    objectImageNew = new ThemeObjectImage(*objectImageToCopy);
    this->ObjectImages.push_back(objectImageNew);
  } 
}

ThemeObjectImage* ThemeObject::FirstImage()
{
  return this->ObjectImages[0];
}

ThemeObject::~ThemeObject(void)
{
  for(std::vector<ThemeObjectImage*>::size_type i = 0; i <  this->ObjectImages.size(); i++)
  {
    delete this->ObjectImages[i];
    this->ObjectImages[i] = nullptr;    
  }
  this->ObjectImages.clear();
}
