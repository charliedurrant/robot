#pragma once
#include "headers.h"
using namespace std;

class CommandBarButton : public Buttn
{
public:
  CommandBarButton(ProgramCommand command);
  ~CommandBarButton(void);
  void CommandSet(ProgramCommand programCommand);
  ProgramCommand CommandGet();
  void Update() override;
  CommandBar* Bar;
private:
  ProgramCommand _command;
  Vector2D _mouseOfset;
  Vector2D PositionFromMouseOffset();
  void MouseOffsetCalculate();
};

