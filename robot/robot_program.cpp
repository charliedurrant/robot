#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

//https://github.com/yujinwunz/SDLGUI/blob/master/SDL%20GUI/textBox.cpp
// http://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c

/*



int doSegment(char *sentence)
{
  char delims = '\n';
  std::stringstream ss(sentence);
  std::string to;

  if (sentence != NULL)
  {
    while(std::getline(ss,to,'\n')){
      cout << to <<endl;
    }
  }

return 0;
}

*/


RobotProgram::RobotProgram(void)
{
  
}


RobotProgram::~RobotProgram(void)
{
  
}
  

void RobotProgram::Clear()
{
  this->_stack.clear();
}
void RobotProgram::LoadCommandsToStack(vector<ProgramCommandData>* _commands)
{
  size_t i;

  for( i = _commands->size() - 1; i < -1; i-- )
  {
    this->_stack.push_back((*_commands)[i]); 
  }
}

vector<ProgramCommandData>* RobotProgram::FunctionCommands(ProgramCommandData command)
{
  switch( command.Command )
  {
    case ProgramCommandFunction1:
      return  &this->_function1;
    case ProgramCommandFunction2:
      return  &this->_function2;
    default:
      return nullptr;
  }
}

bool RobotProgram::CommandIsFunction(ProgramCommandData command)
{
  return command.Command < ProgramCommandCountOfFunctions;  
}

ProgramCommandData RobotProgram::NextCommand()
{
  ProgramCommandData command;
  vector<ProgramCommandData>* functionCommands;
  
  if ( this->_stack.size() == 0 )
  { command.Command =  ProgramCommandEnd; }
  else
  {
    command.Command = ProgramCommandEnd;
    while ( this->_stack.size() > 0 && this->CommandIsFunction(command = this->_stack.back()) )
    {
      this->_stack.pop_back();
      
      functionCommands = this->FunctionCommands(command);
      if ( functionCommands->size() > 0 )
      {
        if ( functionCommands->front().Command != command.Command ) //never ending check
        {
          this->LoadCommandsToStack(functionCommands);
        }
      }
    }
    if ( this->_stack.size() > 0 )
    {
      this->_stack.pop_back();
    }
    else
    {
      command.Command = ProgramCommandEnd;
    }
  }       
  return command;  
}

//TODO: naff code, need to have a bunch of classess so we can easily convert, ProgramCommandData(string functionName, ProgramCommand command)
string RobotProgram::CommandToFunctionString(ProgramCommandData command)
{
  string line;

  switch( command.Command )
  {
    case ProgramCommandFunction1: //TODO const for the commands and have an in out function, command to text, text to command with bool param to decide in or out
      line = "function1()";
      break;
    case ProgramCommandFunction2:
      line = "function2()";
      break;
    case ProgramCommandForward:
      line = "forward()";
      break;
    case ProgramCommandLeft:
      line = "left()";
      break;
    case ProgramCommandRight:
      line = "right()";
      break;
    case ProgramCommandJump:
      line = "jump()";
      break;
    case ProgramCommandSwitch:
      line = "switch()";
      break;
    default:
      line = "";
      break;          
  }
  return line;
}

//very simple python parser, we just look for def main,function1,function2: and then load the commands into each vector
void RobotProgram::Parse(const string& program)
{
  size_t p0;
  int lineNumber = 0;
  std::stringstream strengStreamProgram(program);
  std::string line;
  vector<ProgramCommandData>* function;
  ProgramCommand command;
  _main.clear();
  _function1.clear();
  _function2.clear();
  ProgramCommandData programCommandData;
  function = & _main;
  while(std::getline(strengStreamProgram,line,'\n'))
  {
    lineNumber++;
    line = Functions::Trim(line);
    if ( line.length() == 0 )
    { continue; }
    if ( line[0] == '#' )
    { continue; }
    p0 =  Functions::StrPos(line,"#");
    if ( p0 != string::npos )
    {
      //remove the text after the comment
      line = line.substr(0,p0);
      line = Functions::Trim(line);
    }
    
    if ( line == "def main():" )
    { function = &_main;  }
    else if ( line == "def function1():" )
    { function = &_function1;  }
    else if ( line == "def function2():" )
    { function = &_function2;  }
    else
    {      
       if ( line == "forward()")
       { command = ProgramCommandForward; }
       else if ( line == "right()" )
       { command = ProgramCommandRight; }
       else if ( line == "left()" )
       { command = ProgramCommandLeft; }
       else if ( line == "jump()" )
       { command = ProgramCommandJump; }
       else if ( line == "switch()" )
       { command = ProgramCommandSwitch; }
       else if ( line == "function1()" )
       { command = ProgramCommandFunction1; }
       else if ( line == "function2()" )
       { command = ProgramCommandFunction2; }
       else
       { continue; }
       programCommandData.Command = command;
       programCommandData.LineNumber = lineNumber;
       function->push_back(programCommandData);
    }
  }

  
}

void RobotProgram::Compile()
{
  this->Clear();
  this->LoadCommandsToStack(&_main);
}

