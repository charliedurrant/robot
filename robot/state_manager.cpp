#pragma once
#include "stdafx.h"

#include "framework.h"
using namespace std;


StateManager::StateManager(void) : _lastState(nullptr)
{

}

StateManager::~StateManager(void)
{
  this->ClearLast();

  for(std::vector<int>::size_type i = 0; i != _states.size(); i++) 
  {
    if ( _states[i] )
    {
      delete _states[i];  
      _states[i] = nullptr;  
    }
  }
  _states.clear();
} 

void StateManager::Push( State* state )
{
  State* stateCurrent;

  stateCurrent = this->Current();
  if (stateCurrent != nullptr)
  {
    stateCurrent->Pause();
  }  
  _states.push_back(state);
  this->Enter(state);
  
}

void StateManager::Pop()
{
  State* state;
  
  this->ClearLast();

  state = this->Current();
  
  if ( state != nullptr )
  {
    state->OnExit();
    _states.pop_back();
    _lastState = state;

    state = this->Current();
    if (state != nullptr)
    { state->Play(); }
  }
  
}

State* StateManager::Current()
{
  if ( _states.empty() )
  { return nullptr; }
  return _states.back();  
}


void StateManager::ClearLast()
{
  if ( _lastState != nullptr )
  {
    _lastState->OnExit();
    delete _lastState;
    _lastState = nullptr;
  }
  
}
void StateManager::Change( State* state )
{
  State* currentState;

  

  currentState = this->Current();
  if(currentState != nullptr )
  {
    if (currentState->ID != state->ID)
    {
      
      this->ClearLast();
      _states.pop_back();    
      _lastState = currentState;
      _states.push_back(state);
      this->Enter(state);
      
    }    
  }
  else
  {
    _states.push_back(state);
    this->Enter(state);
    
  }    
}


void StateManager::Enter(State* state)
{
  state->OnEnter();
  state->Update();
}

void StateManager::Update()
{
  State* state;

  state = this->Current();
  if ( state != nullptr )
  {
    state->Update();
  }
  this->ClearLast();
}

void StateManager::Render()
{
  State* state;

  state = this->Current();
  if ( state != nullptr )
  {    
    state->Render();
    if ( Game::GameInstance->DebugInfo )
    {
      state->RenderDebugInfo();
    }
  }
}

