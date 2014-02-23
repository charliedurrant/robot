#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

BaseGameTheme::BaseGameTheme(string pathAndFile) :  BackgroundColor(nullptr), _rootElement(nullptr), _imagesElement(nullptr), _objectsElement(nullptr), _xmlDocument(nullptr)
{
  SplitPath* splitPath = nullptr;
  string resourceRoot;
  try
  {    
    splitPath = new SplitPath(pathAndFile); 
    resourceRoot = splitPath->Drive + splitPath->Directory;
    this->ResourceRoot = Functions::FullPath( resourceRoot );
    _xmlDocument = Functions::XMLFileLoad(pathAndFile);
    _rootElement = _xmlDocument->RootElement();
    _objectsElement = Functions::XMLFindFirstElementByName(_rootElement,"objects");
    _imagesElement = Functions::XMLFindFirstElementByName(_rootElement,"images");

    this->BackgroundColor = this->ColorGet("background");    
    
  }
  catch( Exception* ex )
  {
    if ( splitPath != nullptr ) { delete splitPath; splitPath = nullptr; }
    this->ConstructorEnd();
    throw new Exception(string("Failed to load the theme: ") + pathAndFile , ex);
  }  
  if ( splitPath != nullptr ) { delete splitPath; splitPath = nullptr; }  
}

void BaseGameTheme::ConstructorEnd()
{
  if ( _xmlDocument != nullptr ) { delete _xmlDocument; _xmlDocument = nullptr; }
  if ( _rootElement != nullptr ) { _rootElement = nullptr; }
  if ( _imagesElement != nullptr ) { _imagesElement = nullptr; }
  if ( _objectsElement != nullptr ) { _objectsElement = nullptr; }
}

BaseGameTheme::~BaseGameTheme()
{
  if ( this->BackgroundColor != nullptr )
  {
    delete this->BackgroundColor;
    this->BackgroundColor = nullptr;
  }

}

Color* BaseGameTheme::ColorGet(string id)
{
  return ColorGet(id,"");
}

Color* BaseGameTheme::ColorGet(string id, string defaultValue)
{
  TiXmlElement* element;
  Color* color = nullptr;
  element = this->ItemGet("color",id);
  
  if ( element == nullptr )
  { 
    if ( defaultValue == "" )
    { throw new Exception(string( "Color could not be found:") + id);  }
  }
  else
  {
    defaultValue = element->Attribute("value");
  }

  color = new Color(defaultValue);
  
  return color;
}


Image* BaseGameTheme::ImageGet2(string id)
{
   TiXmlElement* imageXmlElement;

   if( Game::GameInstance->Images->Contains(id) )
   {
     return Game::GameInstance->Images->Item(id);
   }
   imageXmlElement = this->ItemGet(_imagesElement,"image",id);
   return Game::GameInstance->Images->Load(id,this->ResourceRoot,imageXmlElement);

}

/*
ThemeImage* BaseGameTheme::ImageGet(string id)
{  
  int framesPerSecond, frameStart, frameEnd;
  int numberOfFrames, numberOfFramesPerRow, numberOfFramesRows;
  CycleMode frameCycleMode;
  string path, imageID, s;
  ThemeImage* themeImage = nullptr;
  Image* image;
  const char* c;
  TiXmlElement* elementImage = nullptr;
  TiXmlElement* elementThemeImage = nullptr;
  
  elementThemeImage = this->ItemGet("theme_image",id);
  imageID = elementThemeImage->Attribute("image");
  
  if ( ! Game::GameInstance->Images->Contains(imageID) )
  {
    elementImage = this->ItemGet(_imagesElement, "image",imageID);   
    path = this->ResourceRoot + elementImage->Attribute("src");

    numberOfFrames = 1;
    elementImage->Attribute("frames",&numberOfFrames);
    
    numberOfFramesRows = -1;
    elementImage->Attribute("rows",&numberOfFramesRows);
    
    numberOfFramesPerRow = -1;
    elementImage->Attribute("frames_per_row",&numberOfFramesPerRow);
    if ( numberOfFramesPerRow == -1 && numberOfFramesRows == -1 )
    {
      numberOfFramesRows = 1;
      numberOfFramesPerRow = numberOfFrames;
    } 
    image = Game::GameInstance->Images->Load(imageID, path,numberOfFrames,numberOfFramesRows, numberOfFramesPerRow);    
  }
  else
  {
    image = Game::GameInstance->Images->Item(imageID);
  }

  framesPerSecond = 0;
  elementThemeImage->Attribute("frames_per_second",&framesPerSecond);
  
  frameStart = 1;
  elementThemeImage->Attribute("frame_start",&frameStart);

  frameEnd = 1;
  elementThemeImage->Attribute("frame_end",&frameEnd);

  frameEnd = 1;
  elementThemeImage->Attribute("frame_end",&frameEnd);

  c = elementThemeImage->Attribute("frame_cycle_mode");
  if ( ! c )
  {
    s = "";
  }
  else
  { s.assign(c); }

  
  if ( s.length() == 0 || s == "left_to_right")
  { frameCycleMode = CycleModeLeftToRight; }
  else if ( s == "back_and_forth" )
  { frameCycleMode = CycleModeBackAndForth; }
  else if ( s == "right_to_left" )
  { frameCycleMode = CycleModeRightToLeft; }
    

  themeImage = new ThemeImage( image, framesPerSecond, frameStart, frameEnd,frameCycleMode);
    
  return themeImage;
}
*/

Image* BaseGameTheme::LoadImage(string imageID)
{
  string path;
  Image* image;
  TiXmlElement* elementImage;
  int numberOfFrames, numberOfFrameRows, numberOfFramesPerRow;

  elementImage = this->ItemGet(_imagesElement,"image", imageID);   
  path = this->ResourceRoot + elementImage->Attribute("src");

  numberOfFrames = 1;
  elementImage->Attribute("frames",&numberOfFrames);
    
  numberOfFrameRows = -1;
  elementImage->Attribute("rows",&numberOfFrameRows);
    
  numberOfFramesPerRow = -1;
  elementImage->Attribute("frames_per_row",&numberOfFramesPerRow);
  if ( numberOfFramesPerRow == -1 && numberOfFrameRows == -1 )
  {
    numberOfFrameRows = 1;
    numberOfFramesPerRow = numberOfFrames;
  } 

  image = Game::GameInstance->Images->Load(imageID, path,numberOfFrames,numberOfFrameRows, numberOfFramesPerRow);    
  return image;
}

ThemeObject* BaseGameTheme::ObjectGet(string id)
{  
  TiXmlElement* objectElement;
  ThemeObject* themeObject;
  string message;

  try
  {
    objectElement = this->ItemGet(_objectsElement,"object",id);
    if ( objectElement == nullptr )
    {
      message = str(fmt::Format("<oject id=\"{0}\" ...> does not exist under: {1}") << id << Functions::XMLElementDetails(_objectsElement));
      throw new Exception( message );
    }
    themeObject = new ThemeObject(this,id, objectElement);  
    return themeObject; 
  }
  catch( Exception* ex )
  {
    throw new Exception(str(fmt::Format("Failed to find the <object id=\"{0}\" ...>") << id),ex);
  }

}

CycleMode BaseGameTheme::CycleMde(TiXmlElement* xmlElemenmt, string attributeName, CycleMode defaultValue)
{
  string s;
  
  s = Functions::XMLAttributeString(xmlElemenmt,"frame_cycle_mode","""");
  if ( s == "left_to_right")
  { return CycleModeLeftToRight; }
  else if ( s == "back_and_forth" )
  { return CycleModeBackAndForth; }
  else if ( s == "right_to_left" )
  { return CycleModeRightToLeft; }
  else
  {
    return defaultValue;
  }
}

TiXmlElement* BaseGameTheme::ItemGet(string elementName, string id)
{
  return ItemGet(this->_rootElement,elementName, id);
}

TiXmlElement* BaseGameTheme::ItemGet(TiXmlElement* elementParent, string elementName, string id)
{
  TiXmlElement* returnElement;

  returnElement = nullptr;

  for(TiXmlElement* element = elementParent->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
  {
    if ( element->Value() == elementName && (id == "" || element->Attribute("id") == id) ) 
    {
      returnElement = element;
      break;
    }
  }
  return returnElement;
}


GameFont* BaseGameTheme::LoadFont(TiXmlElement* element)
{
  string pathAndFile;
  int pointSize;
  GameFont* font;

  
  pathAndFile = this->ResourceRoot + Functions::XMLAttributeString(element, "value","");
  pointSize = Functions::XMLAttributeInt(element,"point_size",10);
  pointSize = Game::GameInstance->WindowMain->ScaleToLogicalDesignHeight(pointSize); 
  font = new GameFont(pathAndFile,pointSize);
  return font;    
}