#pragma once
#include "headers.h"

enum CollisionType
{
  CollisionTypeNone = 0,
  CollisionTypeX = 1,
  CollisionTypeY = 2
};

class Board;
class BoardSquare;
class PlayState;

class Robot : public GameObject
{
public:
  Robot(PlayState* board);
  virtual ~Robot(void);
  void Render() override;
  void RenderDebugInfo() override;
  void Update() override;
  bool Rendered;
  POINT_FRAMEWORK BoardPositionRenderWith; //this is transformed
  POINT_FRAMEWORK BoardPositionDiamondStart; //this is transformed
  POINTF3D BoardPosition;  
  float TilesPerSecond;
  Rotation CurrentRotation;
  RECTF TileRectTransformed();
  RECTF RenderTile();
  RECTF RenderSquare(bool tile = false);
  void ProgramRun();
  void CommandSet(ProgramCommand programCommand);
private:
  PlayState* _playState;
  void PositionToVector(POINT_FRAMEWORK position, Vector2D vector);
  void CoordinateToPosition(POINT_FRAMEWORK coordinate, Vector2D vector);
  bool CrossesSquareAt(RECTF rectRobot, POINT_FRAMEWORK squareCoordinate);
  void ConvertTileRectTo3dPolygon(RECTF rect, POINTF polygon4Points[]);
 
  RECTF TileRect2();
  void UpdateScanXY(float moveMentIncrement, float xStep, float yStep);
  
  
  void UpdateSetWorldPosition();
  void UpdateForCollision();
  int CommandDestinationZAxisChange();
  int CommandDestinationZAxisChange(int* sourceBrickCount,int* destinationBrickCount );
  bool _robotIsBrick;
  bool _scanXYInit;
  int _scanXYlastSecond;
  bool _scanXYScanningInX ;
  void UpdateFrame();
  ProgramCommand _currentCommand;
  ProgramCommand _previousCommand;
  
  
  POINTF3D _commandDestinatonCoordinate;
  POINTF3D _commandDestinatonImageFrame;
  POINTF3D _commandStartCoordinate;
  POINTF3D _boardPositionFImageFrame;
  void UpdateFromCommandForward(int timeDifferenceInMilliseconds);
  void UpdateCommand();
  void UpdateFromCurrentCommand();
  void UpdateDestinationImageFrameMoveForward();
  int _commandTotalMilliseconds;
  
  float FrameFloat();
  float _bounceZTo;
  float _jumpHeight;
};
