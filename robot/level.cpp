#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

Level::Level(TiXmlElement* xmlElement)
{
  TiXmlElement* element;
  LevelSquare* levelSquare;
  string s;
  this->ID = Functions::XMLAttributeString(xmlElement, "id","");
  if ( this->ID.length() == 0 )
  { throw new Exception("Element has no id"); }


  element = Functions::XMLFindFirstChildByName(xmlElement, "robot");
  if ( element == nullptr )
  { this->RobotPositon.Y = this->RobotPositon.X = 1; }
  else
  {
    this->RobotPositon.X = Functions::XMLAttributeInt(element,"x",1) - 1;
    this->RobotPositon.Y = Functions::XMLAttributeInt(element,"y",1) - 1;
  }

  s = Functions::XMLAttributeString(element,"face","left");
  if ( s == "right" ) { this->RobotRotation = RotationClockWise180; }
  else if ( s == "down" ) { this->RobotRotation = RotationClockWise90; }
  else if ( s == "up" ) { this->RobotRotation = RotationClockWise270; }
  else { this->RobotRotation = RotationClockWise0; }

  this->Name = Functions::XMLFindFirstChildByNameText(xmlElement, "name","");
  this->Description = Functions::XMLFindFirstChildByNameText(xmlElement, "description","");
  this->EntryMessage = Functions::XMLFindFirstChildByNameText(xmlElement, "entry_message","");
  this->ExitMessage = Functions::XMLFindFirstChildByNameText(xmlElement, "exit_message","");
  this->Solution = Functions::XMLFindFirstChildByNameText(xmlElement, "solution","");

  element = Functions::XMLFindFirstChildByName(xmlElement,"board");
  this->BoardSize = Functions::XMLAttributeInt(element,"size",8);    
  
  for(TiXmlElement* elementSquare = element->FirstChildElement(); elementSquare != NULL; elementSquare = elementSquare->NextSiblingElement())
  {
    levelSquare = new LevelSquare(elementSquare);
    if ( (levelSquare->Coordinate.X > this->BoardSize) || (levelSquare->Coordinate.Y > this->BoardSize) )
    {
      throw new Exception("The level has squares outside of the board area");
    }
    this->Squares.push_back(levelSquare);
  } 
}

Level::Level()
{
}

Level::~Level(void)
{
  size_t i;
  LevelSquare* levelSquare;

  for(i = 0; i < this->Squares.size(); i++)
  {
    levelSquare = this->Squares[i];
    delete levelSquare;
    this->Squares[i] = nullptr;    
  }
  this->Squares.clear();
}
