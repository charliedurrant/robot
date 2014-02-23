#pragma once
#include "headers.h"
using namespace std;

enum ProgramCommand
{
   ProgramCommandFunction1 = 0,
   ProgramCommandFunction2 = 1,
   //insert functions here
   ProgramCommandCountOfFunctions = 2,
   ProgramCommandMoveForward,
   ProgramCommandTurnLeft90Degrees,
   ProgramCommandTurnRight90Degrees,
   ProgramCommandJump,
   ProgramCommandSwitchLightSwitch,
   ProgramCommandEnd,
   ProgramCommandNext,
   ProgramCommandNone

};

class RobotProgram
{
public:
  RobotProgram(void);
  ~RobotProgram(void);

  vector<ProgramCommand> _main;
  
  vector<ProgramCommand> _function1;
  vector<ProgramCommand> _function2;
  
  vector<ProgramCommand> _stack;
  ProgramCommand NextCommand();
  void Parse(string program);
  string CommandToFunctionString(ProgramCommand command);
  void Clear();
private: 
  void LoadCommandsToStack(vector<ProgramCommand>* _commands);
  vector<ProgramCommand>* FunctionCommands(ProgramCommand command);
  bool CommandIsFunction(ProgramCommand command);

 };

