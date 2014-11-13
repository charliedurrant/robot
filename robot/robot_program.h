#pragma once
#include "headers.h"
using namespace std;

enum ProgramCommand
{
   ProgramCommandFunctionMain = 0,
   ProgramCommandFunction1 = 1,
   ProgramCommandFunction2 = 2,
   //insert functions here
   ProgramCommandCountOfFunctions = 3,
   ProgramCommandNone,
   ProgramCommandEnd,
   ProgramCommandNext,
   ProgramCommandActionsStart,
   ProgramCommandForward,
   ProgramCommandLeft,
   ProgramCommandRight,
   ProgramCommandJump,
   ProgramCommandSwitch
   
   

};


struct ProgramCommandData
{
  ProgramCommand Command;
  int LineNumber;
  ProgramCommand CommandbarID; //function main, 1, 2
  int CommandBarButtonIndex; //zero based

  ProgramCommandData() 
  { 
    this->LineNumber = 0; 
    this->Command = ProgramCommandNone; 
    CommandBarButtonIndex = -1;
    CommandbarID = ProgramCommandNone;
  }  

  ProgramCommandData(ProgramCommand command)
  {
    this->LineNumber = 0;
    this->Command = command;
  }

};

class RobotProgram
{
public:
  RobotProgram(void);
  ~RobotProgram(void);

  vector<ProgramCommandData> _main;  
  vector<ProgramCommandData> _function1;
  vector<ProgramCommandData> _function2;
  
  vector<ProgramCommandData> _stack;
  ProgramCommandData NextCommand();
  void Parse(const string& program);
  string CommandToFunctionString(ProgramCommandData command);
  void Clear();
  bool CommandIsFunction(ProgramCommandData command);
  void Compile();
private: 
  void LoadCommandsToStack(vector<ProgramCommandData>* _commands);
  vector<ProgramCommandData>* FunctionCommands(ProgramCommandData command);


 };

