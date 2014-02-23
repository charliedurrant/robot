#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

LevelPacks::LevelPacks(string pathAndFile) : _packIndex(-1), _levelIndex(-1)
{
  TiXmlDocument* xmlDocument = nullptr;
  TiXmlElement* element;
  LevelPack* levelPack;
  string levelPackPathAndFile;
  SplitPath parentPath(pathAndFile);
  try
  {
    xmlDocument = Functions::XMLFileLoad(pathAndFile);
    element = xmlDocument->RootElement()->FirstChildElement();
    while ( element )
    {
      if ( ! Functions::XMLAttributeBool(element,"enabled",true) )
      { continue; }
      levelPackPathAndFile = Functions::XMLAttributeString(element,"name","");
      levelPackPathAndFile = parentPath.Path() + levelPackPathAndFile;
      levelPackPathAndFile = Functions::FullPath(levelPackPathAndFile) + "level_pack.xml";
      levelPack = new LevelPack(levelPackPathAndFile);
      this->Packs.push_back(levelPack);
      element = element->NextSiblingElement();
    }
  }
  catch( Exception* ex )
  {
    if ( xmlDocument != nullptr )
    {
      delete xmlDocument;
      xmlDocument = nullptr;
    }
    throw new Exception("Failed to load the level packs from:" + pathAndFile,ex); 
  } 
  if ( xmlDocument != nullptr )
  {
    delete xmlDocument;
    xmlDocument = nullptr;
  }
}

LevelPacks::~LevelPacks(void)
{
  size_t i;
  LevelPack* levelPack;
  for( i = 0; i < this->Packs.size(); i++ )
  {
    levelPack = this->Packs[i];
    delete levelPack;
    this->Packs[i] = nullptr;
  }
  this->Packs.clear();
}

Level* LevelPacks::CurrentLevel()
{
  if ( _packIndex == -1 )
  {
    if ( this->Packs.size() == 0 )
    { throw new Exception("Requested the current level but no packs loaded"); }
    _packIndex = 0;
  }

  if ( _levelIndex == -1 )
  {    
    if ( this->Packs[_packIndex]->Levels.size() == 0 )
    { throw new Exception("Requested the current level but no levels loaded in the current pack"); }
    _levelIndex = 0;
  }

  return this->Packs[_packIndex]->Levels[_levelIndex];
}