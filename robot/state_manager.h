#pragma once
#include "framework.h"
using namespace std;

class State;

class StateManager
{
public:
  StateManager(void);
  ~StateManager(void);
  void Push(State* state);
  void Change(State* state);
  
  void Pop();
  State* Current();
  void Clear(bool noCleanUp = false);
  void Update();
  void Render();

private:
  std::vector<State*> _states;
  State* _lastState;
  void ClearLast();
  void Enter(State* state);
};

