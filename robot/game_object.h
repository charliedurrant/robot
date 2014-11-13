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
  void RenderDebugInfo(const string& text);
  bool Contains(Vector2D* position);
  bool ContainsMouse();
  RECT_FRAMEWORK Rentangle();
  void PositionAndSize(float x, float y, int width, int height);
  void PositionAndSize(Vector2D* position, int width, int height) ;

  void PositionAndSize(int x, int y, int width, int height);
  void PositionAndSize(RECT_FRAMEWORK r);
  virtual void Resize(int width, int height);
  void Accelerate(float value);
  void RenderBackground();
  TextAlign DebugInfoTextAlign;
  static void UpdateThemeObject(GameObject* gameObject,ThemeObject* themeObject);
  GameObjects* Children();
  PADDING Padding;
  ThemeObject* CurrentThemeObject;  
  Vector2D Position;  
  bool Visible;
  bool LeftMousebuttonDown();
  bool LeftMousebuttonClicked();
  virtual void Click(void* sender); //when clicked will be called
  void OnClick(std::function<void(void*)> onClickCallBack); //void * will be the sender i.e me
  State* ParentState;
  RECT_FRAMEWORK RectangleLessPadding();
  ThemeObject* BackgorundImage;
protected:  
  std::function<void(void*)> _onClickCallBack;
  SIZE_FRAMEWORK Size;
  Vector2D Velocity;
  Vector2D Acceleration;
  FlipType _flip;
  bool _flipWithHorizontalVelocity;
  bool _flipWithVerticalVelocity;  
private: 
  GameObjects* _children;
  
};

