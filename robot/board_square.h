#pragma once
#include "headers.h"
using namespace std;


class BoardSquare : public GameObject
{

public:
  BoardSquare(Board* board);
  virtual ~BoardSquare(void);
  POINT_FRAMEWORK Coordinate; //this is the coordinate (not transformed)
  POINT_FRAMEWORK CoordinateRender; //this is the transformed coordinate  
  RECT_FRAMEWORK RectangleBase;
  RECT_FRAMEWORK* RectangleRenderBase;
  RECT_FRAMEWORK RectangleRenderTop;
  int RenderOrder;
  bool Rendered;
  void Render() override;  
  void Update() override;
  void RenderDebugInfo() override;
  void LightStateSet(LightState lightState);  
  LightState LightStateGet();  
  size_t BrickCount;  
  void RenderFloorTileOnly(SIZE_FRAMEWORK moveBy);
  void LightStateSwitch();
private:
  LightState _lightState;
  Board* _board;  
  void RenderTile();
};

