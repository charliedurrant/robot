#pragma once
#include "headers.h"
using namespace std;

// this is mapping class to stop loads of repeated switch functions
class ProgramFunctionCommandBar
{
public:
  ProgramFunctionCommandBar();
  ~ProgramFunctionCommandBar();
  CommandBar* CmdBar;

};

