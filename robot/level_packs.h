#pragma once
#include "headers.h"
using namespace std;
class LevelPacks
{
public:
  LevelPacks(string pathAndFile);  
  ~LevelPacks(void);
  LevelPack* CurrentPack();
  Level* CurrentLevel();
  std::vector<LevelPack*> Packs;
private:
  int _packIndex;
  int _levelIndex;
     
};

