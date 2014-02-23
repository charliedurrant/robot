#pragma once
#include "headers.h"
using namespace std;

class LevelPack
{
public:
  LevelPack(string pathAndFile);
  ~LevelPack(void);
  string Name;
  string Description;
  std::vector<Level*> Levels;
private:
  
};

