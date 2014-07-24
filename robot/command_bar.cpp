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


//if the coord is in the bar space it will find the nearest one
CommandBarButton* CommandBar::ButtonAt(POINT_FRAMEWORK pt)
{
  size_t i;
  int distanceFromSquared = 9999999;
  int distanceFromSquareTemp;
  CommandBarButton* button;
  CommandBarButton* buttonNearest = nullptr;
  RECT_FRAMEWORK rectangle;
  
  if ( ! this->Rentangle().Contains(pt) )
  { return nullptr; }
  
  for( i = 0; i < this->Children()->Size(); i++ )
  {
    button = (CommandBarButton*)this->Children()->Item(i);
    if ( button == nullptr )
    { continue; }
    rectangle = button->Rentangle();
    if (rectangle.Contains(pt))
    { return button; }
    else
    {
      distanceFromSquareTemp = rectangle.DistanceBetweenSquared(pt);
      if (distanceFromSquareTemp < distanceFromSquared)
      {
        buttonNearest = button;
        distanceFromSquared = distanceFromSquareTemp;
      }
    }
  }
  
  return buttonNearest;
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
