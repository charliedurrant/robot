#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

CommandBar::CommandBar(int columns, int buttonMargin, int buttonSize) : ButtonBar(columns, buttonMargin,buttonSize,buttonSize) , 
  CanReceiveCommands(true), DragButton(nullptr), DragButtonSource(nullptr),_onCommandDragDrop(nullptr)
{
  ;  
}


void CommandBar::AddButtons(int count, ProgramCommand command)
{
  int i;

  for( i = 0; i < count; i++ )
  {
    this->AddButton(command);
  }
}


CommandBar::~CommandBar(void)
{
  
}

CommandBarButton* CommandBar::ButtonAt(POINT pt)
{
  size_t i;
  CommandBarButton* button;
  if ( ! this->Rentangle().Contains(pt) )
  { return nullptr; }
  
  for( i = 0; i < this->Children()->Size(); i++ )
  {
    button = (CommandBarButton*)this->Children()->Item(i);
    if ( button == nullptr )
    { continue; }
    if ( button->Rentangle().Contains(pt) )
    {
      return button;
    }
  }
  return nullptr;
}

CommandBarButton* CommandBar::AddButton(ProgramCommand command)
{
  CommandBarButton* button;

  button = new CommandBarButton(command);
  button->Bar = this;
  this->Children()->Add(button);
  return button;
}
  
void CommandBar::Clear()
{
  size_t i;
  CommandBarButton* button;
  for( i = 0; i < this->Children()->Size(); i++ )
  {
    button = (CommandBarButton*)this->Children()->Item(i);
    if ( button == nullptr )
    { continue; }
    button->CommandSet(ProgramCommandNone);    
  }
  
}

//see http://stackoverflow.com/questions/14189440/c-class-member-callback-simple-examples
void CommandBar::OnCommandDragDrop(std::function<void(CommandBarButton* commandBarButton)> onCommandDragDropCallBack)
{  
  this->_onCommandDragDrop = onCommandDragDropCallBack;
}

void CommandBar::RaiseCommandDragDrop(CommandBarButton* commandBarButton)
{
  if ( this->_onCommandDragDrop != nullptr )
  {
    this->_onCommandDragDrop(commandBarButton);
  }
}
