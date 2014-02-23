#pragma once
#include "framework.h"

class ThemeImage;
class ThemeObject; 

class SettingsBase
{
public:
  SettingsBase(void);
  ~SettingsBase(void);  
  virtual void Load(string pathAndFile);
  
  string String(string name, string defaultValue, bool raiseExceptionIfNotPresent = false);
  int Int(string name, int defaultValue, bool raiseExceptionIfNotPresent = false);
  bool Bool(string name, bool defaultValue, bool raiseExceptionIfNotPresent = false);
  TiXmlElement* Setting(string name,bool raiseExceptionIfNotPresent = false);
protected:
  void LoadEnd();
  string _resourceRoot;
  TiXmlElement* _rootElement;
  TiXmlDocument* _document;
  TiXmlElement* _settingsElement;
private:
  void LoadFontsFiles();
  void LoadFontFile(TiXmlElement* fontFile);
  
};

