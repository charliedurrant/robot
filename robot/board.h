#pragma once
#include "headers.h"
using namespace std;

class PlayState;
class BoardSquare;

class Board : public GameObject
{
public:
  bool Dirty;
  Board(PlayState* playState);
  virtual ~Board(void);
  void Update() override;
  void Render() override;
  void RenderDebugInfo() override;
  int BoardSizeGet();
  void BoardSizeSet(int size);
  void Resize(int width, int height) override;
  bool ContainsCoordinate(POINT coordinate);
  /*
   This is used to determine the area of the board, if we didn't use this for a board less than standard the tiles would get larger
   If the board is more than standard we shrink the board, basically if either TilesInX or TilesinY is greater then we are shrinking the tiles
  */
  
  RECT BoardRectangle();
  RECT SquareStart();
  BoardSquare* RobotRenderSquare(POINT coordinate, bool coordinateIsTransformed = false);
  BoardSquare* Square(POINT coordinate);
  BoardSquare* Square(POINT coordinate, bool render, bool coordinateAlreadyTranformed = false);
  POINT TransForm(POINT coordinate, bool inverse = false);
  POINTF TransForm(POINTF point, bool inverse = false);
  Vector2D VectorOneSuqareInY;
  Vector2D VectorOneSuqareInX;
  //height reduced to square the rect
  BRICKDATA BrickData;
  //same as brick data but not scaled, for a brick the width is as per the image but the height is reduced
  BRICKDATA BrickDataUnscaled;
  
  void Rotate(bool clockWise);
  void ResizeSquares();
  SIZE _boardSize; //TODO: make friend
  void LoadLevel(Level* level);  
  void LoadRobotStartPosition(Level* level);
  vector<Image*> _towerBlocks;
  Robot* RoBot;    
  void LightStateSwitch(POINT coordinate);  
private:  
  PlayState* _playState;
  Image* _boardRenderInOneGoImage;
  void DeleteLocalImages();
  SIZE _standardBoardSize;
  vector<BoardSquare*> _squares;
  vector<BoardSquare*> _squaresRender;  
  SIZE TileSize();
  SIZE TileSize(int tilesInX, int tilesInY);
  bool CanRender();
  void CalculateBrickData();
  void CreateTowerBlocks();
  void CreateBoardRenderInOneGo();
  void PositionSquares();
  void TransformSquares();
  void RenderSquare(POINT transformed);
  void RenderSquaresWithRobotInDiamondPattern(POINT offset, int maxDiagonal);
  void RenderSquares();
  void ResizeSquareStorage();
  void UpdateMovementVectors(Rotation boardRotation);
  void UpdateMovementVectors();
  inline int CoordinateToArrayIndex(POINT coordinate);  
  Rotation _boardRotation;
  int _squareRenderOrder;
  
};

