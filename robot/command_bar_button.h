#pragma once
#include "headers.h"
using namespace std;

class CommandBarButton : public Buttn
{
public:
  CommandBarButton(ProgramCommandData command);
  ~CommandBarButton(void);
  void CommandSet(ProgramCommandData programCommand);
  ProgramCommandData CommandGet();
  void Update() override;
  CommandBar* Bar;

private:
  ProgramCommandData _command;
  Vector2D _mouseOfset;
  Vector2D PositionFromMouseOffset();
  void MouseOffsetCalculate();
};

