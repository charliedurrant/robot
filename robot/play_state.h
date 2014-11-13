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
  CommandBarButton* FunctionButtonAt(POINT_FRAMEWORK pt);
  string ProgramTextGet();
  
  RobotProgram* Program;
  Board* GameBoard;
  ProgramText* ProgText;
  
  CommandBar* Commands;
  CommandBar* CommandsMain;
  CommandBar* CommandsFunction1;
  CommandBar* CommandsFunction2;
  Buttn* CommandBarProgramCommandHighlight;
  void CommandDragDrop(CommandBarButton* sender);       
  void BoardRotationArrowClick(void* sender);       
  void ProgramStopClick(void* sender);       
  void ProgramRunClick(void* sender);       
  void ProgramResetClick(void* sender);
  void Update() override;
private:
  string ProgramTextGetFromFunctionCommandBar(CommandBar* commandBar, string functionName);
  void MapCommandBarsIndexesFromProgram();
  void MapCommandBarIndexesFromProgramFunction(CommandBar* commandBar, vector<ProgramCommandData>* function, ProgramCommand commandBarID);
  CommandBarButton* ProgramCurrentCommandButton();
  CommandBarButton* _lastProgramCommandButton;
  ProgramCommandData _lastProgramCommandButtonCommand;
};

