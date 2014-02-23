#pragma once
#include "headers.h"
using namespace std;

class Settings : public SettingsBase
{
public:
  Settings();
  ~Settings(void);
  void Load(string pathAndFile) override;
  bool RenderBricksAsTowerBlocks;
  bool RenderBoardInOneGo;    
private:
 
};

