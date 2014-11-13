#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

ErrorState::ErrorState(string message, Exception* ex) : State("error")
{
  this->_message = message;
  this->_exception = ex; 
}

ErrorState::~ErrorState(void)
{
    
}

void ErrorState::OnEnter()
{
  string text;
  Labl* label;

  text = Functions::ErrorMessageString(this->_message, this->_exception);
  text = text + NEWLINE + NEWLINE + "- Please press escape to exit - ";

  label = new Labl(text);
  label->PositionAndSize(0,0,MyGame::Instance->WindowMain->LogicalSize.Width,MyGame::Instance->WindowMain->LogicalSize.Height);
  this->Objects->Add(label);
}
    