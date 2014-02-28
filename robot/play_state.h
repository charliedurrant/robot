#pragma once
#include "stdafx.h"
#include "framework.h"

using namespace std;

class PlayState : public State
{
public:
  PlayState(void);
  virtual ~PlayState(void);
  void OnEnter() override;
  CommandBarButton* FunctionButtonAt(POINT pt);
  string ProgramTextGet();
  
  RobotProgram* Program;
  Board* GameBoard;
  
  CommandBar* Commands;
  CommandBar* CommandsMain;
  CommandBar* CommandsFunction1;
  CommandBar* CommandsFunction2;
  void CommandDragDrop(CommandBarButton* sender);       
  void BoardRotationArrowClick(void* sender);       
  void ProgramStopClick(void* sender);       
  void ProgramRunClick(void* sender);       
  void ProgramResetClick(void* sender);
private:
  string ProgramTextGetFromFunctionCommandBar(CommandBar* commandBar, string functionName);
  
};

