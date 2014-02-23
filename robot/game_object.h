#pragma once

#include "framework.h"
using namespace std;


class GameObjects;
class ThemeObject;
class State;

class GameObject
{
public:
  GameObject(void);
  virtual ~GameObject();

  virtual void Render();
  virtual void Update();
  virtual void Clean();  
  virtual void RenderDebugInfo();
  bool Contains(Vector2D* position);
  bool ContainsMouse();
  RECT Rentangle();
  void PositionAndSize(float x, float y, int width, int height);
  void PositionAndSize(Vector2D* position, int width, int height) ;

  void PositionAndSize(int x, int y, int width, int height);
  void PositionAndSize(RECT r);
  virtual void Resize(int width, int height);
  void Accelerate(float value);
  void RenderFrame(ThemeImage* themeImage, int x, int y,int width, int height, int frame);
  void RenderFrame(ThemeImage* themeImage, RECT r, int frame );
  
  static void UpdateThemeObject(GameObject* gameObject,ThemeObject* themeObject);

  GameObjects* Children();
  
  int Frame();  
  ThemeObject* CurrentThemeObject;  
  Vector2D Position;  
  bool Visible;
  void OnClick(std::function<void(void*)> onClickCallBack); //void * will be the sender i.e me
  State* ParentState;
protected:  
  std::function<void(void*)> _onClickCallBack;
  SIZE Size;
  int _frame;
  Vector2D Velocity;
  Vector2D Acceleration;
  
  FlipType _flip;
  bool _flipWithHorizontalVelocity;
  bool _flipWithVerticalVelocity;  
private: 
  GameObjects* _children;
  
};

