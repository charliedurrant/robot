#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

CommandBarButton::CommandBarButton(ProgramCommand command) : Buttn(nullptr), Bar(false)
{
  this->CommandSet(command); 
}

void CommandBarButton::CommandSet(ProgramCommand programCommand)
{
  ThemeObject* themeObject;
  this->_command = programCommand;
  
  switch( this->_command )
  {
    case ProgramCommandMoveForward:
      themeObject = MyGame::Instance->Theme->CommandBarButtonMoveForward;
      break; 
    case ProgramCommandTurnLeft90Degrees:
      themeObject = MyGame::Instance->Theme->CommandBarButtonTurnLeft90Degrees;
      break; 
    case ProgramCommandTurnRight90Degrees:
      themeObject = MyGame::Instance->Theme->CommandBarButtonTurnRight90Degrees;
      break; 
    case ProgramCommandJump:
      themeObject = MyGame::Instance->Theme->CommandBarButtonJump;
      break; 
    case ProgramCommandSwitchLightSwitch:
      themeObject = MyGame::Instance->Theme->CommandBarButtonSwitchLightSwitch;
      break; 
    case ProgramCommandFunction1:
      themeObject = MyGame::Instance->Theme->CommandBarButtonFunction1;
      break; 
    case ProgramCommandFunction2:
      themeObject = MyGame::Instance->Theme->CommandBarButtonFunction2;
      break; 
    default:
      themeObject = MyGame::Instance->Theme->CommandBarButtonNone;
      break; 
  }
  if ( this->CurrentThemeObject != nullptr )
  {
    delete this->CurrentThemeObject;
    this->CurrentThemeObject = nullptr;
  }
  this->CurrentThemeObject = new ThemeObject(themeObject);
}

ProgramCommand CommandBarButton::CommandGet()
{
  return this->_command;
}

Vector2D CommandBarButton::PositionFromMouseOffset()
{
  Vector2D v;
  v = this->_mouseOfset + *MyGame::Instance->Input->Mouse->Position;
  return v;
}

void CommandBarButton::MouseOffsetCalculate()
{
  this->_mouseOfset =  (this->Position - *MyGame::Instance->Input->Mouse->Position);      
}

void CommandBarButton::Update()
{
  static int x = 0;

  if ( this->_command == ProgramCommandNone )
  { return; }

  if ( MyGame::Instance->Input->Mouse->GetCapture() == this )
  {
    this->PositionAndSize(&this->PositionFromMouseOffset(),this->Size.Width,this->Size.Height);          
    if ( MyGame::Instance->Input->Mouse->LeftButton == MouseButtonDown  )
    {
      ;
    }
    else if ( MyGame::Instance->Input->Mouse->LeftButton == MouseButtonUp )
    {
      MyGame::Instance->Input->Mouse->SetCapture(nullptr);  
      this->Bar->RaiseCommandDragDrop(this);
      this->Visible = false;          
    }
  }
  else
  {
    if ( this->ContainsMouse()  )
    {
      if ( MyGame::Instance->Input->Mouse->LeftButton == MouseButtonDown && MyGame::Instance->Input->Mouse->GetCapture() == nullptr )
      {
        if ( this->Bar->DragButton == nullptr )
        {
          this->Bar->DragButton = new CommandBarButton(this->CommandGet());
          this->Bar->DragButton->Bar = this->Bar;
          MyGame::Instance->States->Current()->Objects->Add(this->Bar->DragButton);     
        }
        else
        {
          this->Bar->DragButton->CommandSet(this->CommandGet());
          this->Bar->DragButton->Visible = true;
        }
        this->Bar->DragButtonSource = this;
        if ( this->Bar->CanReceiveCommands )
        { this->CommandSet(ProgramCommandNone); }
        this->Bar->DragButton->Position = this->Position;
        this->Bar->DragButton->MouseOffsetCalculate();
          
        MyGame::Instance->Input->Mouse->SetCapture(this->Bar->DragButton);
        this->Bar->DragButton->PositionAndSize(&this->Position,this->Size.Width,this->Size.Height);          
      }
    }    
  }
  Buttn::Update();
}

CommandBarButton::~CommandBarButton(void)
{
  ;
}
  