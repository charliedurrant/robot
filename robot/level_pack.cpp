#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;


LevelPack::LevelPack(string fileAndPath)
{
  TiXmlDocument* xmlDocument = nullptr;
  TiXmlElement* elementRoot;
  TiXmlElement* element;
  try
  {
    xmlDocument = Functions::XMLFileLoad(fileAndPath);
    elementRoot = xmlDocument->RootElement();
    this->Name = Functions::XMLFindFirstChildByNameText(elementRoot,"name","");
    this->Description = Functions::XMLFindFirstChildByNameText(elementRoot,"description","");
    element = Functions::XMLFindFirstChildByName(elementRoot,"levels");
    if ( element )
    {
      element = element->FirstChildElement();
      while ( element )
      {
        this->Levels.push_back(new Level(element));
        element = element->NextSiblingElement();
      }
    }        
  }
  catch( Exception* ex )
  {
    if ( xmlDocument )
    {
      delete xmlDocument;
      xmlDocument = nullptr;
    }
    throw new Exception("Failed to load a level pack from:" + fileAndPath,ex);
  } 
  if ( xmlDocument )
  {
    delete xmlDocument;
    xmlDocument = nullptr;
  }
}


LevelPack::~LevelPack(void)
{
  size_t i;
  Level* level;
  for( i = 0; i < this->Levels.size(); i++ )
  {
    level = this->Levels[i];
    delete level;
    this->Levels[i] = nullptr;
  }
  this->Levels.clear();
}
