#pragma once
#include "framework.h"

using namespace std;

class GameObject;

class GameObjects
{
protected:
  std::vector<GameObject*> _objects;  
private:
  bool _cleared;
public:
  GameObjects(void);
  ~GameObjects(void);

  void Add(GameObject * gameObject);
  void Add( GameObject * go, int index );
  void AddAfter( GameObject * go, GameObject* after );
  void AddAtStart(GameObject * gameObject);

  void Render();
  void RenderDebugInfo();
  void Update();
  void Clear();
  size_t Size();
  GameObject* Item( size_t index);

};

