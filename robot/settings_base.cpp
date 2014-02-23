#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

SettingsBase::SettingsBase(void) :  _document(nullptr), _rootElement(nullptr), _settingsElement(nullptr)
{
  //setup the system font for error messages
  Game::GameInstance->Fonts->Add("courier_prime",Functions::ApplicationPath() + "system/fonts/courier_prime.ttf");
  Game::GameInstance->SystemFont = Game::GameInstance->Fonts->Item("courier_prime",14);            
  Game::GameInstance->SystemFontColor = new Color("FFFFFF");            
}

SettingsBase::~SettingsBase(void)
{
    
}

void SettingsBase::Load(string pathAndFile)
{
  shared_ptr<SplitPath> splitPath;
  try
  {
    splitPath = shared_ptr<SplitPath>(new SplitPath(pathAndFile));
    this->_resourceRoot = Functions::FullPath( splitPath->Drive + splitPath->Directory );
    _document = Functions::XMLFileLoad(pathAndFile);
    _rootElement = _document->RootElement();
    _settingsElement = Functions::XMLFindFirstChildByName(_rootElement,"settings");
    Game::GameInstance->FramesPerSecond = this->Int("frames_per_second",30);
    if ( Game::GameInstance->FramesPerSecond < 0 )
    { Game::GameInstance->FramesPerSecond = 0; }
    this->LoadFontsFiles();  
  } 
  catch( Exception* ex )
  { throw new Exception("Failef in Load from the SettingsBase class", ex); }   
}

string SettingsBase::String(string name, string defaultValue, bool raiseExceptionIfNotPresent )
{
  TiXmlElement* element;

  element = this->Setting(name,raiseExceptionIfNotPresent);
  
  return Functions::XMLAttributeString(element,"value",defaultValue);
}

int SettingsBase::Int(string name, int defaultValue, bool raiseExceptionIfNotPresent)
{
  TiXmlElement* element;

  element = Functions::XMlFindFirstChildByNameAndAttribute(this->_settingsElement,"setting","name",name,raiseExceptionIfNotPresent);
  return Functions::XMLAttributeInt(element,"value",defaultValue);
}

bool SettingsBase::Bool(string name, bool defaultValue, bool raiseExceptionIfNotPresent)
{
  TiXmlElement* element;

  element = Functions::XMlFindFirstChildByNameAndAttribute(this->_settingsElement,"setting","name",name,raiseExceptionIfNotPresent);
  return Functions::XMLAttributeBool(element,"value",defaultValue);
}


TiXmlElement* SettingsBase::Setting(string name,bool raiseExceptionIfNotPresent)
{
  TiXmlElement* element;

  element = Functions::XMlFindFirstChildByNameAndAttribute(this->_settingsElement,"setting","name",name,raiseExceptionIfNotPresent);
  return element;
}
   
void SettingsBase::LoadFontsFiles()
{ 
  TiXmlElement* fontFiles;
  try
  {
    fontFiles = Functions::XMLFindFirstElementByName(this->_rootElement,"font_files",false);
    if ( fontFiles == nullptr )
    { return; }
    for(TiXmlElement* element = fontFiles->FirstChildElement(); element != NULL; element = element->NextSiblingElement())
    { this->LoadFontFile(element); }  
  }
  catch( Exception* ex )
  {
    throw new Exception("Failed to load the font_files",ex);
  }
}

void SettingsBase::LoadFontFile(TiXmlElement* fontFile)
{
  string family;
  string file;
  try
  {
    family = Functions::XMLAttributeString(fontFile, "family");
    file = Functions::XMLAttributeString(fontFile, "file");
    file = _resourceRoot + file;
    if ( ! Functions::FileExists(file) )
    { throw new Exception(str(fmt::Format("The font file '{0}' does not exist") << file)); }
    Game::GameInstance->Fonts->Add(family,file);
  }
  catch( Exception* ex )
  {
    if ( fontFile )
    { throw new Exception(str(fmt::Format("Failed to load the font_file, element: '{0}'") << Functions::XMLElementDetails(fontFile)),ex); }
    else
    { throw new Exception(str(fmt::Format("Failed to load the font_file")),ex); }

  }
}

   
void SettingsBase::LoadEnd()
{
  if ( this->_document != nullptr )
  {
    delete this->_document;
    this->_document = nullptr;
  }
}  