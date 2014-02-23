#pragma once
#include "framework.h"

class SplitPath
{
public:
  SplitPath(string path);
  ~SplitPath(void);
  string Drive;
  string Directory;
  string Extension;
  string FileName;
  string Path();
private:
  /*
  char* basename(char*);
  char* dirname(char*);
  */
};

