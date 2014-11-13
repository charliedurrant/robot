#pragma once
#include "headers.h"
using namespace std;

class PlayState;
class Robot;

class ProgramText : public GameObject
{  
public:
  ProgramText(PlayState* playState);
  ~ProgramText();
  void TextSet(string text);  
  void Update() override;
  void Render() override;
private:   
  PlayState* _playState;
  string _text;
  int _currentLineNumber;
  Labl* _labelProgram;
  void DeleteTextImage();
  Image* _imageProgramText;
  Image* _imageProgramPointer;
  FontData* _fontData;
  
};

