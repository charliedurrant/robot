#pragma once
#include "framework.h"

class ThemeImage;
class ThemeObject; 

class BaseGameTheme
{
  public:
    BaseGameTheme(string pathAndFile);
    ~BaseGameTheme();
    Color* BackgroundColor;
    ThemeImage* ImageGet(string id);   
    Image* ImageGet2(string id);
    Color* ColorGet(string id, string defaultValue);
    Color* ColorGet(string id);
    string ResourceRoot;
    static CycleMode CycleMde(TiXmlElement* xmlElemenmt, string attributeName, CycleMode defaultValue);
    void ConstructorEnd();
    GameFont* LoadFont(TiXmlElement* element);
    Color* DebugTextColor;
  private:
    void ProcessColors(TiXmlElement* element);
    
    TiXmlElement* _imagesElement;  
    TiXmlElement* _objectsElement;  
    TiXmlDocument* _xmlDocument;
    string _pathAndFile;  
  protected:
    TiXmlElement* _rootElement;  
    TiXmlElement* ItemGet(string elementName, string id);
    TiXmlElement* ItemGet(TiXmlElement* elementParent, string elementName, string id);
    Image* LoadImage(string imageID);
    ThemeObject* ObjectGet(string id);
   
    
};