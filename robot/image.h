#pragma once
#include "framework.h"
using namespace std;

class Image
{
  private:
    void Construct(string& id,SDL_Texture* texture, SIZE_FRAMEWORK* size,int numberOfFrames,int intNumberOfFrameRows, int numberOfFramesPerRow);    
  public:
    Image(string id,Image* imageAttributes, SIZE_FRAMEWORK* size);
    Image(string id, SDL_Texture* texture, SIZE_FRAMEWORK* size);
    Image( string id, SDL_Texture* texture, SIZE_FRAMEWORK* size,int numberOfFrames, int numberOfFrameRows, int numberOfFramesPerRow );
    ~Image(void); 
    SDL_Texture* Texture;
    SIZE_FRAMEWORK Size;
    SIZE_FRAMEWORK FrameSize;
    void AlphaSet();
    string ID;
    int NumberOfFrameRows;
    int NumberOfFramesPerRow;
    int NumberOfFrames;
    void AlphaSet(Uint8 alpha);
    RECT_FRAMEWORK FrameRectangle(int frame);
    int FrameCalculate(int framesPerSecond )
    { 
      return this->FrameCalculate(framesPerSecond, this->NumberOfFrames);      
    }
    int FrameCalculate(int framesPerSecond, int numberOfFrames )
    { 
      return int(((SDL_GetTicks() / (1000 / framesPerSecond)) % numberOfFrames)); 
    }

};

