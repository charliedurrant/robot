//Using SDL and standard IO
#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

int main( int argc, char* args[] )
{
	
  MyGame* game;
  int ret;
  try
  {  
    game = new MyGame();    
    Functions::Init(args[0]);
    Game::GameInstance->Run();    
    ret = 0;
  }
  catch( Exception* ex )
  {    
    Functions::ErrorMessageConsole(string("An exception occured in the application: "),ex);
    ret = 1;
  }

  if ( Game::GameInstance != nullptr ) { delete Game::GameInstance; Game::GameInstance = nullptr; }

  return ret;  
}