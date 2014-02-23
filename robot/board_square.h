#pragma once
#include "headers.h"
using namespace std;


class BoardSquare : public GameObject
{

public:
  BoardSquare(Board* board);
  virtual ~BoardSquare(void);
  POINT Coordinate; //this is the coordinate (not transformed)
  POINT CoordinateRender; //this is the transformed coordinate  
  RECT RectangleBase;
  RECT* RectangleRenderBase;
  RECT RectangleRenderTop;
  int RenderOrder;
  bool Rendered;
  void Render() override;  
  void Update() override;
  void RenderDebugInfo() override;
  void LightStateSet(LightState lightState);  
  LightState LightStateGet();  
  size_t BrickCount;  
  void RenderFloorTileOnly(SIZE moveBy);
  void LightStateSwitch();
private:
  LightState _lightState;
  Board* _board;  
  void RenderTile();
};

