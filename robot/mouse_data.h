#pragma once
#include "framework.h"
using namespace std;

class GameObject;
class MouseData
{
  public:
    MouseData(void);
    ~MouseData(void);  
   
   MouseButtonState LeftButton;
   MouseButtonState MiddleButton;
   MouseButtonState RightButton;  
   GameObject* GetCapture();
   void SetCapture(GameObject* gameObject);
   Vector2D* Position;
 private:
  GameObject* _captured;

};

