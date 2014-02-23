#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;

State::State( string id ) : _paused(false)
{
  this->ID = id;
  this->Objects = new GameObjects();  
}

State::~State( void )
{
  if ( this->Objects )
  {
    delete this->Objects;
    this->Objects = nullptr;
  }    
}

void State::Render()
{
  this->Objects->Render();   
}

void State::RenderDebugInfo()
{
  this->Objects->RenderDebugInfo();   
}

void State::Update()
{
  if (  _paused )
  { return; }
  this->Objects->Update();    
}

void State::OnExit()
{
  this->Objects->Clear();  
}

void State::Pause()
{
  _paused = true;
}

void State::Play()
{
  _paused = false;
}