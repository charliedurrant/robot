#pragma once
#include "headers.h"
using namespace std;


class Level
{
public:
  Level(TiXmlElement* xmlElement);
  Level(void);
  ~Level(void);
  string ID;
  string Description;
  string Name;
  int BoardSize;
  string EntryMessage;
  string ExitMessage;
  std::vector<LevelSquare*> Squares;
  POINT RobotPositon;
  Rotation RobotRotation;
  string Solution;
};

