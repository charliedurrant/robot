#pragma once
#include "stdafx.h"

#include "headers.h"
using namespace std;



Board::Board(PlayState* playState) : GameObject(), _standardBoardSize(8,8), _boardRotation(RotationClockWise0), RoBot(nullptr), Dirty(true), _boardRenderInOneGoImage(nullptr),
 _squareRenderOrder(0)
{
  try
  {  
    this->_playState = playState;
    this->_boardSize = _standardBoardSize;
    this->ResizeSquareStorage();
    this->RoBot = new Robot(playState);    

  }
  catch (Exception* ex)
  {
    throw new Exception(string("Failed to create the board"),ex);
  }
}

Board::~Board(void)
{
  size_t i;
  BoardSquare* boardSquare;
  if (this->RoBot)
  {
    delete this->RoBot;
    this->RoBot = nullptr;
  }
  this->DeleteLocalImages();
  if ( _squares.size() > 0)
  {
    for (i = 0; i < _squares.size(); i++)
    {
      boardSquare = _squares[i];
      delete boardSquare; 
      _squares[i] = nullptr;
    }
  }
}

void Board::DeleteLocalImages()
{
  size_t i;
  for( i = 0; i < _towerBlocks.size(); i++ )
  {
    if ( _towerBlocks[i] != nullptr )
    {
      delete _towerBlocks[i];
      _towerBlocks[i] = nullptr;
    }
  }
  if ( _boardRenderInOneGoImage != nullptr )
  {
    delete _boardRenderInOneGoImage;
    _boardRenderInOneGoImage = nullptr;
  }
}

//only supporting square boards at the momeny, rotation is the problem
int Board::BoardSizeGet()
{
  return _boardSize.Width;
}

void Board::BoardSizeSet(int size)
{
  _boardSize.Width = _boardSize.Height = size;
  this->Dirty = true;
  this->ResizeSquareStorage();  
}


SIZE Board::TileSize(int tilesInX, int tilesInY)
{
  SIZE tileSize;

  //always roound down so use (int)
  tileSize.Width = (int) (((float)this->Size.Width * 2.0f) / (float)(tilesInX + tilesInY ));
  tileSize.Height = (int) (((float)this->Size.Height * 2.0f) / (float)(tilesInX + tilesInY ));
  return tileSize;
}

SIZE Board::TileSize()
{
  SIZE tileSize;
  if (this->_boardSize.Area() > this->_standardBoardSize.Area() )
  {
    tileSize = this->TileSize(this->_boardSize.Width, this->_boardSize.Height);
  }
  else
  {
    tileSize = this->TileSize(this->_standardBoardSize.Width, this->_standardBoardSize.Height);
  }

  return tileSize;
}

RECT Board::BoardRectangle()
{
  SIZE tileSize;
  RECT boardRect;

  tileSize = this->TileSize();
  //calcualte the rect of the floor, this may need to be centered insize the game object rect
  
  boardRect.Height = (int)ceil((tileSize.Height / 2.0f) * (float)(this->_boardSize.Width + this->_boardSize.Height));
  boardRect.Width = (int)ceil((tileSize.Width / 2.0f) * (float)(this->_boardSize.Width + this->_boardSize.Height));
  //would be width * height but we need to center it in the the object size if required
  boardRect.X = (int)this->Position.X + ((this->Size.Width - boardRect.Width) / 2);
  boardRect.Y = (int)this->Position.Y + ((this->Size.Height - boardRect.Height) / 2);
  return boardRect;
}

//this is the square at 0,0 with no board rotation, from the screen view it is the one on the far left 
RECT Board::SquareStart()
{
  RECT boardRect;
  SIZE tileSize;
  RECT squareStart;
  
  tileSize = this->TileSize();
  boardRect = this->BoardRectangle();

  squareStart.Height = (int)tileSize.Height;
  squareStart.Width = (int)tileSize.Width;
  squareStart.X = boardRect.X + (int)((Functions::Round(((float)boardRect.Width / 2.0f)) - Functions::Round((float)tileSize.Width / 2.0f)));
  squareStart.Y = boardRect.Y;

  return squareStart;
}


BoardSquare* Board::Square(POINT coordinate)
{
  return this->Square(coordinate, false);
}

BoardSquare* Board::Square(POINT coordinate, bool render, bool coordinateAlreadyTranformed)
{
  int index;

  if (!coordinateAlreadyTranformed && render)
  {
    coordinate = this->TransForm(coordinate);
  }

  index = this->CoordinateToArrayIndex(coordinate);
  if (render)
  {
    return _squaresRender[index];
  }
  else
  {
    return _squares[index];
  }
}

bool Board::ContainsCoordinate(POINT coordinate)
{
  return coordinate.X > -1 && coordinate.X < _boardSize.Width && coordinate.Y > -1 && coordinate.Y < _boardSize.Width;
}


void Board::ResizeSquareStorage()
{
  int size, squareCount;
  
  int i;
  size = _squares.size();
  squareCount = this->_boardSize.Area();
  if (squareCount > size)
  {
    _squares.resize(squareCount);
    _squaresRender.resize(squareCount);

    _squares.resize(squareCount,nullptr);
    for (i = size; i < squareCount ; i++)
    {
      _squares[i] = new BoardSquare(this);
    }
    _squaresRender.resize(squareCount, nullptr);
  }    
}

void Board::PositionSquares()
{
  //create the tiles array
  RECT squareStartRect, squareRect;
  POINT coordinate;
  BoardSquare* square;
  Vector2D vectorStart;
  Vector2D vectorPosition;

  squareStartRect = this->SquareStart();
  this->UpdateMovementVectors(RotationClockWise0); //get the movement vector with zero rotation
  vectorStart.X = (float)squareStartRect.X;
  vectorStart.Y = (float)squareStartRect.Y;

  for( coordinate.X = 0; coordinate.X < _boardSize.Width; coordinate.X++ )
  {
    for( coordinate.Y = 0; coordinate.Y < _boardSize.Height; coordinate.Y++ )
    {
      vectorPosition = vectorStart + (this->VectorOneSuqareInX * (float)coordinate.X ) + (this->VectorOneSuqareInY * (float)coordinate.Y );
      squareRect.X = (int)Functions::Round(vectorPosition.X);
      squareRect.Y = (int)Functions::Round(vectorPosition.Y);
      squareRect.Width = squareStartRect.Width;
      squareRect.Height = squareStartRect.Height;
      
      square = this->Square(coordinate);
      square->RectangleBase = squareRect;     
    }
  } 
}

void Board::TransformSquares()
{
  POINT coordinate, transformed;
  int arrayIndex, arrayIndexTransformed;
  BoardSquare* squareTransformed;
 
  for (coordinate.Y = this->_boardSize.Height - 1; coordinate.Y > -1; coordinate.Y--)
  {
    for (coordinate.X = 0; coordinate.X < this->_boardSize.Width; coordinate.X++)
    {
      transformed = this->TransForm(coordinate);

      arrayIndex = this->CoordinateToArrayIndex(coordinate);
      arrayIndexTransformed = this->CoordinateToArrayIndex(transformed);

      squareTransformed = _squaresRender[arrayIndexTransformed] = _squares[arrayIndex];
      squareTransformed->Coordinate = coordinate;
      squareTransformed->CoordinateRender = transformed;
      //take the rectangle from the transformed index from the source to the new location
      squareTransformed->RectangleRenderBase = &_squares[arrayIndexTransformed]->RectangleBase;

      /*
       Note we are not using the standard game object positions as per squareTransformed->PositionAndSize(*squareTransformed->RectangleRenderBase).
       We use our own rects instead as it is easier to manage
      */
      
      //get the top rect if there are bricks
      squareTransformed->RectangleRenderTop = *squareTransformed->RectangleRenderBase;
      if (squareTransformed->BrickCount > 0)
      {
        squareTransformed->RectangleRenderTop.Y -= this->BrickData.VerticalDrawOffset * squareTransformed->BrickCount;
      }
    }
  }
}

void Board::Resize(int width, int height) 
{
  //delete all the tower blocks
  this->DeleteLocalImages();
  this->Dirty = true;
  GameObject::Resize(width, height);
}

void Board::Update()
{
  int i;
  if (this->Dirty)
  {
    this->ResizeSquareStorage();
    this->PositionSquares();
    
    //transform the squares to their render positions depending on the board rotation
    this->CalculateBrickData();
    this->TransformSquares();
    this->CreateTowerBlocks();
    this->CreateBoardRenderInOneGo();  
    this->UpdateMovementVectors(this->_boardRotation);
    this->Dirty = false;
  }  
  

  //we update in here to sync the board square tiles, it we do individual updates then fading images may get out of sync, this means we can't have separate images for tiles
  this->UpdateThemeObject(nullptr, MyGame::Instance->Theme->Tile2);
  this->UpdateThemeObject(nullptr, MyGame::Instance->Theme->TileOn2);
  this->UpdateThemeObject(nullptr, MyGame::Instance->Theme->TileOff2);

  //update squares

  for ( i = 0; i < this->_boardSize.Area(); i++ )
  {
    _squares[i]->Update();
  }
  this->RoBot->Update();
  GameObject::Update();
}

void Board::Rotate(bool clockWise)
{
  this->_boardRotation = MyGame::Instance->Rotate90Degrees(this->_boardRotation,clockWise);
  this->Dirty = true;
}

void Board::CreateBoardRenderInOneGo()
{
  SIZE szMoveBy;
  POINT pt;
  BoardSquare* boardSquare;

  if ( MyGame::Instance->Settngs->RenderBoardInOneGo && _boardRenderInOneGoImage == nullptr)
  {
    _boardRenderInOneGoImage = new Image("board_render_in_one_go",MyGame::Instance->Theme->Brick->FirstImage()->Img,&this->Size);
    szMoveBy.Width = (int)Functions::Round(this->Position.X *  -1.0f); 
    szMoveBy.Height = (int)Functions::Round(this->Position.Y *  -1.0f); 
    SDL_SetRenderTarget(MyGame::GameInstance->WindowMain->Renderer, _boardRenderInOneGoImage->Texture);

    for (pt.X = 0; pt.X < this->_boardSize.Width; pt.X++)
    {
      for (pt.Y = 0; pt.Y < this->_boardSize.Height; pt.Y++)
      {
        boardSquare = this->Square(pt,true,false);
        boardSquare->RenderFloorTileOnly(szMoveBy);
      }
    }

    SDL_SetRenderTarget(MyGame::GameInstance->WindowMain->Renderer, NULL);
  }
}

void Board::CreateTowerBlocks()
{
  BoardSquare* square;
  Image* image;
  Image* imageBrick = nullptr;
  Image* imageTowerBlock = nullptr;
  size_t  brickNumber;
  size_t i;
  SIZE sz;
  RECT rectDest;
  BRICKDATA brickData;

  if (!MyGame::Instance->Settngs->RenderBricksAsTowerBlocks)
  { return; }

  for (i = 0; i < _squares.size(); i++)
  {
    square = _squares[i];

    if (square->BrickCount > this->_towerBlocks.size())
    { this->_towerBlocks.resize(square->BrickCount, nullptr); }

    if (square->BrickCount > 1)
    {      
      if ((image = this->_towerBlocks[square->BrickCount - 1]) == nullptr)
      {
        brickData = this->BrickData;  
        if (imageBrick == nullptr)
        {
          imageBrick = MyGame::Instance->Theme->Brick->FirstImage()->Img;
          sz.Width = brickData.Size.Width;          
        }
          
        sz.Height = brickData.Size.Height + ((square->BrickCount - 1) * brickData.VerticalDrawOffset);
        sz.Width = brickData.Size.Width;

        imageTowerBlock = new Image(str( fmt::Format("tower_block_{0}") << square->BrickCount), imageBrick,&sz);
        
        SDL_SetRenderTarget(MyGame::GameInstance->WindowMain->Renderer, imageTowerBlock->Texture);

        rectDest.X = 0;
        rectDest.Y = sz.Height - (brickData.Size.Height - brickData.VerticalDrawOffset);
        rectDest.Width = brickData.Size.Width;        
        rectDest.Height = brickData.Size.Height;
        for (brickNumber = 0; brickNumber < square->BrickCount; brickNumber++)
        {
          if ( i > 0 )
          { rectDest.Y -= brickData.VerticalDrawOffset; }
          if (SDL_RenderCopy(MyGame::GameInstance->WindowMain->Renderer, imageBrick->Texture, NULL, (SDL_Rect*)&rectDest))
          { throw new ExceptionSDL("RenderCopy failed when copying the brick for a tower"); }
        }        

        SDL_SetRenderTarget(MyGame::GameInstance->WindowMain->Renderer, NULL);
        this->_towerBlocks[square->BrickCount - 1] = imageTowerBlock;
      }
    }  
  }
  
}


void Board::UpdateMovementVectors()
{ 
  this->UpdateMovementVectors(this->_boardRotation);
}


//TODO replace with matrix??
void Board::UpdateMovementVectors(Rotation boardRotation)
{
  SIZEF sz;
  SIZE tileSize;

  tileSize = this->TileSize();
  sz.Width = (float)tileSize.Width / 2.0f;
  sz.Height = (float)tileSize.Height / 2.0f;
  
  switch (boardRotation)
  {
    case RotationClockWise0:
      this->VectorOneSuqareInX.X = sz.Width;
      this->VectorOneSuqareInX.Y = sz.Height;

      this->VectorOneSuqareInY.X = -sz.Width;
      this->VectorOneSuqareInY.Y = +sz.Height;
      break; 
    case RotationClockWise90:
      this->VectorOneSuqareInX.X = -sz.Width;
      this->VectorOneSuqareInX.Y = sz.Height;

      this->VectorOneSuqareInY.X = -sz.Width;
      this->VectorOneSuqareInY.Y = -sz.Height;
      break;
    case RotationClockWise180:
      this->VectorOneSuqareInX.X = -sz.Width;
      this->VectorOneSuqareInX.Y = -sz.Height;

      this->VectorOneSuqareInY.X = sz.Width;
      this->VectorOneSuqareInY.Y = -sz.Height;
      break;
    case RotationClockWise270:
      this->VectorOneSuqareInX.X = sz.Width;
      this->VectorOneSuqareInX.Y = -sz.Height;

      this->VectorOneSuqareInY.X = sz.Width;
      this->VectorOneSuqareInY.Y = sz.Height;
      break;
  }

}

void Board::Render()
{
  RECT r;
  if (!this->CanRender())
  { return; }
  
  if ( MyGame::Instance->Settngs->RenderBoardInOneGo )
  {
    r = this->Rentangle();
    MyGame::Instance->Images->Render(_boardRenderInOneGoImage,nullptr,&r,SDL_ALPHA_OPAQUE,FlipTypeNone);
  }
  this->RenderSquares();
}

void Board::CalculateBrickData()
{
  Image* imageBrick;
  Image* imageTile;
  SIZEF szF;
  BoardSquare* square;
  float scale;
  float offset;

  imageBrick = MyGame::Instance->Theme->Brick->FirstImage()->Img;
  imageTile = MyGame::Instance->Theme->Tile2->FirstImage()->Img;
  square = this->_squares[0];  
  
  scale = (float)imageBrick->FrameSize.Height / (float)imageTile->FrameSize.Height;

  szF.Height = scale * (float)square->RectangleBase.Height;
  szF.Width = (float)square->RectangleBase.Width;
  this->BrickData.Size.Height =  (int)Functions::Round( szF.Height );
  this->BrickData.Size.Width = (int)Functions::Round(szF.Width);
  offset = szF.Height - (float)square->RectangleBase.Height;
  this->BrickData.VerticalDrawOffset = (int)Functions::Round(offset);

  scale = (float)imageBrick->FrameSize.Width / szF.Width;
  
  this->BrickDataUnscaled.Size.Height = (int)Functions::Round(szF.Height * scale);
  this->BrickDataUnscaled.Size.Width = (int)Functions::Round(szF.Width * scale);
  this->BrickDataUnscaled.VerticalDrawOffset = (int)Functions::Round(offset * scale);
}

bool Board::CanRender()
{ return _squares.size() > 0; }



POINT Board::TransForm(POINT point, bool inverse)
{
  POINT transformed;

  switch (this->_boardRotation)
  {
    case RotationClockWise0:
      transformed = point;
      break;
    case RotationClockWise90:
      //x,y => y, xmax + 1-x
      if (!inverse)
      {
        transformed.X = (this->_boardSize.Width - 1) - point.Y;
        transformed.Y = point.X;
      }
      else
      {
        transformed.X = point.Y;
        transformed.Y = (this->_boardSize.Width - 1) - point.X;
      }      
      break;
    case RotationClockWise270:
      //x,y => ymax + 1 - y, x
      if (!inverse)
      {
        transformed.Y = (this->_boardSize.Height - 1) - point.X;
        transformed.X = point.Y;
      }
      else
      {        
        transformed.Y = point.X;
        transformed.X = (this->_boardSize.Height - 1) - point.Y;      
      }
      break;
    case RotationClockWise180:
      //x,y => ymax - x, ymax + 1 - y
      transformed.X = this->_boardSize.Width - 1 - point.X;
      transformed.Y = this->_boardSize.Height - 1 - point.Y;
      break;
    default:
      throw new Exception(str(fmt::Format("Invalid perspective: '{0}'") << this->_boardRotation));      
  }
  
  if ( ((transformed.Y < 0 || transformed.Y > this->_boardSize.Height - 1)) || ((transformed.X < 0 || transformed.X > this->_boardSize.Width - 1)))
  {
    throw new Exception("Transform out of range");
  }
  return transformed;
}

POINTF Board::TransForm(POINTF point, bool inverse)
{
  POINTF transformed;

  switch (this->_boardRotation)
  {
    case RotationClockWise0:
      transformed = point;
      break;
    case RotationClockWise90:
      //x,y => y, xmax + 1-x
      if (!inverse)
      {
        transformed.X = (float)(this->_boardSize.Width - 1) - point.Y;
        transformed.Y = point.X;
      }
      else
      {
        transformed.X = point.Y;
        transformed.Y = (float)(this->_boardSize.Width - 1) - point.X;

      }      
      break;
    case RotationClockWise270:
      //x,y => ymax + 1 - y, x
      if (!inverse)
      {
        transformed.Y = (float)(this->_boardSize.Height - 1) - point.X;
        transformed.X = point.Y;

      }
      else
      {
        transformed.Y = point.X;
        transformed.X = (float)(this->_boardSize.Height - 1) - point.Y;      

      }
      break;
    case RotationClockWise180:
      //x,y => ymax - x, ymax + 1 - y
      transformed.X = (float)(this->_boardSize.Width - 1) - point.X;
      transformed.Y = (float)(this->_boardSize.Height - 1) - point.Y;
      break;
    default:
      throw new Exception(str(fmt::Format("Invalid perspective: '{0}'") << this->_boardRotation));      
  }
  
  if ( ((transformed.Y < 0 || transformed.Y > (float)(this->_boardSize.Height - 1))) || ((transformed.X < 0 || transformed.X > (float)(this->_boardSize.Width - 1))))
  {
    throw new Exception("Transform out of range");
  }
  return transformed;
}


void Board::LightStateSwitch(POINT coordinate)
{
  BoardSquare* square;
  square = this->Square(coordinate);
  square->LightStateSwitch();  
}

void Board::RenderSquare(POINT transformed)
{
  BoardSquare* square;
  POINT position;
  
  
  square = this->Square(transformed,true,true);
  if ( square->Rendered )
  { return; }

  this->_squareRenderOrder++;
  square->RenderOrder = this->_squareRenderOrder;
  square->Render();
  //now draw the robot 
  //position = this->TransForm(transformed,  true); //TODO: remove
  if ( transformed == this->RoBot->BoardPositionRenderWith )
  {
    this->RoBot->Render();
  }  
}

void Board::RenderDebugInfo()
{
  POINT coordinate;
  BoardSquare* square;
  for( coordinate.X = 0; coordinate.X < this->_boardSize.Width; coordinate.X++ )
  {
    for( coordinate.Y = 0; coordinate.Y < this->_boardSize.Height; coordinate.Y++ )
    {
      square = this->Square(coordinate,true,false);
      square->RenderDebugInfo();
    }
  }
  this->RoBot->RenderDebugInfo();  
}

BoardSquare* Board::RobotRenderSquare(POINT coordinate, bool coordinateIsTransformed)
{
  BoardSquare* square;
  int index;
  POINT transformed;

  if ( ! coordinateIsTransformed)
  { transformed = this->TransForm(coordinate); }
  else
  { transformed = coordinate; }
  
  index = this->CoordinateToArrayIndex(transformed);
  square = _squaresRender[index];
  return square;
}

void Board::RenderSquares()
{
  POINT coordinate, coordinate2;
  size_t i;
  const int DIMAOND_PATTERN_SIZE = 2;
  bool renderedSquaresAroundRobot;
  this->_squareRenderOrder = 0;

  for( i = 0 ; i < _squares.size() ; i++ )
  { _squares[i]->Rendered = false; }
      
  renderedSquaresAroundRobot = false;

  for (coordinate.X = 0; coordinate.X < this->_boardSize.Width; coordinate.X++)
  {
    for (coordinate.Y = 0; coordinate.Y < this->_boardSize.Width; coordinate.Y++)
    {
      if ( ! renderedSquaresAroundRobot && coordinate == this->RoBot->BoardPositionDiamondStart)
      {        
        for (coordinate2.X = 0; coordinate2.X < this->RoBot->BoardPositionDiamondStart.X + DIMAOND_PATTERN_SIZE; coordinate2.X++)
        {
          for (coordinate2.Y = 0; coordinate2.Y < this->_boardSize.Width; coordinate2.Y++)
          {
            if ( coordinate2.Y <  this->RoBot->BoardPositionDiamondStart.Y  )
            { this->RenderSquare(coordinate2); }
          }
        }  

        this->RenderSquaresWithRobotInDiamondPattern(coordinate,DIMAOND_PATTERN_SIZE);
        for (coordinate2.X = 0; coordinate2.X < this->RoBot->BoardPositionDiamondStart.X + DIMAOND_PATTERN_SIZE; coordinate2.X++)
        {
          for (coordinate2.Y = 0; coordinate2.Y < this->_boardSize.Width; coordinate2.Y++)
          {
            if ( coordinate2.Y > this->RoBot->BoardPositionDiamondStart.Y + 1  )
            { this->RenderSquare(coordinate2); }
          }
        }  
        renderedSquaresAroundRobot = true;         
      }
      else
      { this->RenderSquare(coordinate); }
    }
  }  
}


//    1
//  2   3
//5   4   7
//  6   8
//    9 
//start is the offset, maxDiagonal in the above case would be 3 i.e. 1,4 & 9
void Board::RenderSquaresWithRobotInDiamondPattern(POINT start, int maxDiagonal)
{
  POINT coordinate;
  int diagonal;

  for (diagonal = 0; diagonal < maxDiagonal; diagonal++)
  {
    if ( this->RoBot->BoardPositionRenderWith.X < start.X || this->RoBot->BoardPositionRenderWith.Y > start.Y )
    {
      coordinate.Y = start.Y + diagonal;
      for (coordinate.X = start.X; coordinate.X < start.X + diagonal ; coordinate.X++)
      { this->RenderSquare(coordinate); }
      coordinate.X = start.X + diagonal;
      for (coordinate.Y = start.Y; coordinate.Y < start.Y + diagonal ; coordinate.Y++)
      { this->RenderSquare(coordinate); }
    }
    else
    {
      coordinate.X = start.X + diagonal;
      for (coordinate.Y = start.Y; coordinate.Y < start.Y + diagonal ; coordinate.Y++)
      { this->RenderSquare(coordinate); }
      coordinate.Y = start.Y + diagonal;
      for (coordinate.X = start.X; coordinate.X < start.X + diagonal ; coordinate.X++)
      { this->RenderSquare(coordinate); }      
    }        
    coordinate.X = start.X + diagonal;
    coordinate.Y = start.Y +  diagonal;    
    this->RenderSquare(coordinate);                  
  }
}


int Board::CoordinateToArrayIndex(POINT coordinate)
{
  int arrayIndex;
  arrayIndex = (coordinate.Y * this->_boardSize.Width) + coordinate.X;
  return arrayIndex;
}

void Board::LoadRobotStartPosition(Level* level)
{
  BoardSquare* boardSquare;;

  this->RoBot->BoardPosition.X = (float)level->RobotPositon.X;
  this->RoBot->BoardPosition.Y = (float)level->RobotPositon.Y;
  boardSquare = this->Square(this->RoBot->BoardPosition.Point());
  this->RoBot->BoardPosition.Z = (float)boardSquare->BrickCount;
  this->RoBot->CurrentRotation = level->RobotRotation;
  this->RoBot->CommandSet(ProgramCommandEnd);
  this->Dirty = true;
}

void Board::LoadLevel(Level* level)
{
  LevelSquare* levelSquare;
  BoardSquare* boardSquare;

  this->BoardSizeSet(level->BoardSize);

  for( size_t i = 0; i < level->Squares.size(); i++ )
  {
    levelSquare = level->Squares[i];
    boardSquare = this->Square(levelSquare->Coordinate);
    boardSquare->BrickCount = levelSquare->BrickCount;
    boardSquare->LightStateSet(levelSquare->Light);         
  }
  this->LoadRobotStartPosition(level);
  
  //this->Dirty = true;
  //this->_playState->Program->Parse(level->Solution);  
}
