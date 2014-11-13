#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

BaseGameTheme::BaseGameTheme(string pathAndFile) :  BackgroundColor(nullptr), _rootElement(nullptr), _imagesElement(nullptr), _objectsElement(nullptr), _xmlDocument(nullptr)
{
  SplitPath* splitPath = nullptr;
  string resourceRoot;
  string xmlString;
  string defineSearch;
  string defineValue;
  TiXmlElement* definesElement = nullptr;

  try
  {    
    splitPath = new SplitPath(pathAndFile); 
    resourceRoot = splitPath->Drive + splitPath->Directory;
    this->ResourceRoot = Functions::FullPath( resourceRoot );

    _xmlDocument = Functions::XMLFileLoad(pathAndFile);
    _rootElement = _xmlDocument->RootElement();

    definesElement = Functions::XMLFindFirstElementByName(_rootElement, "defines");
    
    if ( definesElement != nullptr && ! definesElement->NoChildren() )
    {
      //replace defines
      xmlString = Functions::TextFileRead(pathAndFile);
      for (TiXmlElement* element = definesElement->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
      {
        defineSearch = element->Attribute("id");
        if (defineSearch.length() == 0 )
        { continue; }
        defineSearch = string("${") + defineSearch + string("}");
        defineValue = element->Attribute("value");
        Functions::StringReplace(xmlString,defineSearch, defineValue);
        
      }
      delete _xmlDocument;
      _xmlDocument = Functions::XMLStringLoad(xmlString, pathAndFile);
      _rootElement = _xmlDocument->RootElement();
    }
  
    _objectsElement = Functions::XMLFindFirstElementByName(_rootElement,"objects",true);
    _imagesElement = Functions::XMLFindFirstElementByName(_rootElement,"images", true);

    this->BackgroundColor = this->ColorGet("background");    
    this->BoardBackgroundColor = this->ColorGet("board_background");    
  }
  catch( Exception* ex )
  {
    if ( splitPath != nullptr ) { delete splitPath; splitPath = nullptr; }
    throw new Exception(string("Failed to load the theme: ") + pathAndFile , ex);
  }  
  if ( splitPath != nullptr ) { delete splitPath; splitPath = nullptr; }  
}


BaseGameTheme::~BaseGameTheme()
{
  if ( this->BackgroundColor != nullptr )
  {
    delete this->BackgroundColor;
    this->BackgroundColor = nullptr;
  }
  
  if (this->BoardBackgroundColor != nullptr)
  {
    delete this->BoardBackgroundColor;
    this->BoardBackgroundColor = nullptr;
  }


  for (auto it = this->Objects.begin(); it != this->Objects.end(); ++it)
  {
    delete it->second;
    it->second = nullptr;
  }
  this->Objects.clear();

  if (_xmlDocument != nullptr) { delete _xmlDocument; _xmlDocument = nullptr; }
  if (_rootElement != nullptr) { _rootElement = nullptr; }
  if (_imagesElement != nullptr) { _imagesElement = nullptr; }
  if (_objectsElement != nullptr) { _objectsElement = nullptr; }

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
  font = new GameFont(pathAndFile,pointSize, "");
  return font;    
}



void BaseGameTheme::ObjectAdd(ThemeObject* themeObject, string id)
{
  this->Objects[id] = themeObject;
 
}

ThemeObject* BaseGameTheme::ObjectLoad(string id, bool storeInObjects)
{
  TiXmlElement* objectElement;
  ThemeObject* themeObject;
  string message;

  try
  {
    objectElement = this->ItemGet(_objectsElement, "object", id);
    if (objectElement == nullptr)
    {
      message = str(fmt::Format("<oject id=\"{0}\" ...> does not exist under: {1}") << id << Functions::XMLElementDetails(_objectsElement));
      throw new Exception(message);
    }
    themeObject = new ThemeObject(this, id, objectElement);
    if (storeInObjects)
    {
      this->ObjectAdd(themeObject, id);
    }    
    return themeObject;
  }
  catch (Exception* ex)
  {
    throw new Exception(str(fmt::Format("Failed to find the <object id=\"{0}\" ...>") << id), ex);
  }



}
