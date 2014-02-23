#pragma once
#include "headers.h"
using namespace std;

class ErrorState : public State
{
public:
  ErrorState(string messsage, Exception* ex);
  ~ErrorState(void);
  void OnEnter() override;
private: 
  string _message;
  Exception* _exception;
};

