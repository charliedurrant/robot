#pragma once
#include "framework.h"

using namespace std;

class Window;
class Image;

class ImageManager
{
  private:
    Window *_window;
    std::map<std::string, Image*> _imageMap;
  public:
    ImageManager(Window *window);
    ~ImageManager(void);
    Image* Load(string key, string resourcePath);
    Image* Load(string key, string resourcePath, int numberOfFrames, int numberOfFramesRows, int numberOfFramesPerRow);
    Image* Load(string key, string& resourceRoot, TiXmlElement* xmlElement);    
    bool Contains(string& key);
    Image* Item(string& key);
    void Render( Image* image,RECT_FRAMEWORK* rectangleSource, RECT_FRAMEWORK* rectangleDestination, Uint8 alpha, FlipType flip  );
    void RenderFrame( Image* image,int frame, RECT_FRAMEWORK* rectangleDestination, Uint8 alpha, FlipType flip  );
    void RenderWholeImage( Image* image,RECT_FRAMEWORK* rectangleDestination, Uint8 alpha, FlipType flip  );
    void RenderTile( Image* image,RECT_FRAMEWORK* rectDestination, Uint8 alpha, FlipType flip  );
    size_t RenderCounter;
};