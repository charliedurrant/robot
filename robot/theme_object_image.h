#pragma once
#include "framework.h"
using namespace std;

class GameTheme;

class ThemeObjectImage
{
public:
  ThemeObjectImage (BaseGameTheme* theme, TiXmlElement* xmlElement);
  ThemeObjectImage(
    Image* image,
    int framesPerSecond,
    int frameStart,
    int frameEnd,
    CycleMode frameCycleMode, 
    int alphaPerSecond,
    int alphaStart,
    int alphaEnd,
    int alphaStep,
    CycleMode alphaCycleMode
  );
  ~ThemeObjectImage(void);
  FRAME_DATA FrameData;
  FRAME_DATA AlphaData;
  
  bool MouseDown;
  bool MouseOver;
  bool MouseOut;
  bool AutomaticallyCalculateFrame;
  bool Render;
  FlipType Flip;
  bool Tile;
  Image* Img;
  //int FrameCalculate(int* frameIncrement);
  void FrameCalculate(FRAME_DATA* frameData);
  int FrameCalculateByPercentage(float percentage);
};

