#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

SplitPath::SplitPath(string path)
{
  
  #if defined(_MSC_VER)
    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char ext[_MAX_EXT];
    char fname[_MAX_FNAME];
  
   _splitpath(path.c_str(),&drive[0], &dir[0], &fname[0], &ext[0]);

    this->Drive = string(&drive[0]);
    this->Directory = Functions::FullPath(string(&dir[0]));
    this->FileName = string(&fname[0]);
    this->Extension = string(&ext[0]);    
  #else   
   char* buffer = new char[path.size() + 1];
   path.copy(&buffer[0],path.size(),0);
   buffer[path.size()] = '\0';
   this->FileName = string(basename(&buffer[0]));
   
   this->Directory = Functions::FullPath(string(dirname(&buffer[0])));
   this->Extension = string("");
   this->Drive = string("");
   delete buffer; 

  #endif   
  
}

SplitPath::~SplitPath()
{
  ;
}


string SplitPath::Path()
{
  return this->Drive + this->Directory;
}
