/*-
see http://www.metanetsoftware.com/technique/diagrams/tutA_demo.Heighttml
for bounce and gravity
*/
#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;

class Board;

Robot::Robot(PlayState* playState) : GameObject(), 
    _robotIsBrick(false), _currentCommand(ProgramCommandNext), TilesPerSecond(2.5f), _commandTotalMilliseconds(0),
    CurrentRotation(RotationClockWise0), Rendered(false)
{  
  _playState = playState;
  _flipWithHorizontalVelocity = false;
  this->BoardPosition.Z = this->BoardPosition.Y = this->BoardPosition.X = 0.0;
  this->BoardPositionDiamondStart.X = this->BoardPositionDiamondStart.Y = this->BoardPositionRenderWith.Y = this->BoardPositionRenderWith.X = 0; 
  this->CurrentThemeObject = MyGame::Instance->Theme->Robot;
}

RECTF Robot::RenderTile()
{
  return this->RenderSquare(true);
}

RECTF Robot::RenderSquare(bool tile)//int brickCount)
{
  Vector2D zeroPoint;
  Vector2D* vectorOneSquareX;
  Vector2D* vectorOneSquareY;
  Vector2D vectordDrawAtBase;
  Vector2D vectordBoardPosition;
  Vector2D vectordOffsetInSquareForZeroPoint;
  BoardSquare* squareZeroZero;
  Image* image;
  POINT pt;
  SIZEF sz;
  RECTF rectDraw;
  
  pt.X = pt.Y = 0;
  squareZeroZero = this->_playState->GameBoard->Square(pt,true,false);
  
  //postiion a base rect scaled to the ScaleToParent inside the 0,0 square's base rectangle
  rectDraw.X = rectDraw.Y = 0.0f;
  rectDraw.Width = Functions::Round((float)(squareZeroZero->RectangleRenderBase->Width) * this->CurrentThemeObject->ScaleToParent);
  rectDraw.Height = Functions::Round((float)(squareZeroZero->RectangleRenderBase->Height) * this->CurrentThemeObject->ScaleToParent);
  Functions::CenterRectInRect(&rectDraw,squareZeroZero->RectangleRenderBase);
   
  //now our height is different from a flat tile so we need to proporionally increase it by the ratio of widths;
  image = MyGame::Instance->Theme->Robot->ObjectImages[0]->Img;
  if ( ! tile )
  {
    sz = Functions::ScaleToWidth(image->FrameSize, rectDraw.Width);
  }
  else
  {
    sz = Functions::ScaleToWidth(this->_playState->GameBoard->BrickDataUnscaled.Size, rectDraw.Width);    
  }
  //calculate the y shift  
  rectDraw.Y -= (sz.Height - rectDraw.Height);
  rectDraw.Height = sz.Height;
    
  vectorOneSquareY = &this->_playState->GameBoard->VectorOneSuqareInY;
  vectorOneSquareX = &this->_playState->GameBoard->VectorOneSuqareInX;

  vectordOffsetInSquareForZeroPoint.X = (float)rectDraw.X;
  vectordOffsetInSquareForZeroPoint.Y = (float)rectDraw.Y;
  
  zeroPoint = vectordOffsetInSquareForZeroPoint;
  /*
  we runnign with standard x,y which we need to convert to screen coords
  x is the same, but wheatever Y value we get we take the difference and subract it. 

  For now we work in standard cordinmates
  */
  vectordDrawAtBase = zeroPoint + (*vectorOneSquareX * this->BoardPosition.X) + (*vectorOneSquareY * this->BoardPosition.Y);

  rectDraw.X = vectordDrawAtBase.X;
  rectDraw.Y = vectordDrawAtBase.Y;
  rectDraw.Y -= (float)(this->BoardPosition.Z * (float)this->_playState->GameBoard->BrickData.VerticalDrawOffset);
  return rectDraw;

}


Robot::~Robot(void)
{
  
}

void Robot::Render()
{
  GameObject::Render();   
}

void Robot::RenderDebugInfo()
{
  string s;
  RECT r;
  POINTF coordinateRender;

  //TODO: what a mess back and forth, coordinateRender should be calculated
  /* COORDINATE DATA */
  /*
  coordinateRender = this->_playState->GameBoard->TransForm(this->BoardPosition.PointF(),false);

  s = str(fmt::Format("Coordinate: {0}\nCoord transformed: {1}\nCoord transformed render with: {2}\nDestnation: {3}\nDestination IMG: {4}\nFrame IMG frame: {5}") 
              << this->BoardPosition.ToString() 
              << coordinateRender.ToString() 
              << this->BoardPositionRenderWith.ToString() 
              << this->_commandDestinatonCoordinate.ToString() 
              << this->_commandDestinatonImageFrame.ToString()
              << this->_boardPositionFImageFrame.ToString()
              );
  */
  /* COORDINATE DATA */
  /* CURRENT_COMMAND */
  
  s = str(fmt::Format("{0}") 
              << this->_playState->Program->CommandToFunctionString(this->_currentCommand)
              );
  
  /* END CURRENT_COMMAND */

  r = this->Rentangle();
  r.Height = 200;
  r.Width = 400;
  Game::GameInstance->WindowMain->RenderText(s,Game::GameInstance->SystemFont,Game::GameInstance->SystemFontColor,&r);
}

int Robot::CommandDestinationZAxisChange(int* sourceBrickCount,int* destinationBrickCount )
{
  BoardSquare* squareStart;
  BoardSquare* squareDestination;
  int brickCount;
  int boardSize;
  
  *sourceBrickCount = 0;
  *destinationBrickCount = 0;
  
  if ( (! (this->_commandDestinatonCoordinate == this->_commandStartCoordinate)) && this->_playState->GameBoard->ContainsCoordinate(_commandDestinatonCoordinate.Point()) )
  {
    squareStart =  this->_playState->GameBoard->Square(_commandStartCoordinate.Point(),false,false);
    boardSize = this->_playState->GameBoard->BoardSizeGet() - 1;
    if ( _commandDestinatonCoordinate.X > boardSize || _commandDestinatonCoordinate.Y > boardSize )
    { brickCount = 0; }
    else
    {
      squareDestination =  this->_playState->GameBoard->Square(_commandDestinatonCoordinate.Point(),false,false);
      brickCount = squareDestination->BrickCount;
    }    
    *sourceBrickCount = squareStart->BrickCount;
    *destinationBrickCount = brickCount;
    return brickCount - squareStart->BrickCount;    
  }
  return 0;
}

int Robot::CommandDestinationZAxisChange()
{
  int i, j;
  return this->CommandDestinationZAxisChange(&i, &j);
}

void Robot::CommandSet(ProgramCommand programCommand)
{
  _previousCommand = _currentCommand;
  _currentCommand = programCommand;
}


void Robot::UpdateForCollision()
{

  /*
  if ( this->_currentCommand == ProgramCommandNext && this->_previousCommand != ProgramCommandNext )
  { return; }
  */
  /*
  zAxisChange = this->CommandDestinationZAxisChange(&zAxisSource, &intzAxisDestination);
  if ( zAxisChange > 1 )
  {
    if ( this->_currentCommand == ProgramCommandNext && this->_previousCommand == ProgramCommandJump  ) //finished fake jump
    {
      this->BoardPosition = this->_commandStartCoordinate;            
    }  
    else if ( this->_currentCommand == ProgramCommandJump )
    {
      this->BoardPosition.X = this->_commandStartCoordinate.X;            
      this->BoardPosition.Y = this->_commandStartCoordinate.Y;                  
    }
  }
  
   
  boardSize = (float)(this->_playState->GameBoard->BoardSizeGet() - 1);

  
  if ( this->BoardPosition.X > boardSize )
  { 
    this->BoardPosition.X = boardSize;     
  }
  else if ( this->BoardPosition.X < 0.0f )
  { this->BoardPosition.X = 0.0f; }

  if ( this->BoardPosition.Y > boardSize )
  { this->BoardPosition.Y = boardSize; }
  else if ( this->BoardPosition.Y < 0.0f )
  { this->BoardPosition.Y = 0.0f; }

  */
}

bool Robot::CrossesSquareAt(RECTF rectRobot, POINT squareCoordinate)
{
  POINTF square[4];
  POINTF squareRobot[4];

  
  squareRobot[0].X = rectRobot.X;
  squareRobot[0].Y = rectRobot.Y;

  squareRobot[1].X = rectRobot.X + rectRobot.Width;
  squareRobot[1].Y = rectRobot.Y;

  squareRobot[2].X = rectRobot.X + rectRobot.Width;
  squareRobot[2].Y = rectRobot.Y + rectRobot.Height;

  squareRobot[3].X = rectRobot.X;
  squareRobot[3].Y = rectRobot.Y + rectRobot.Height;

  square[0].X = (float)squareCoordinate.X;
  square[0].Y = (float)squareCoordinate.Y;

  square[1].X = (float)squareCoordinate.X + 1.0f;
  square[1].Y = (float)squareCoordinate.Y;

  square[2].X = (float)squareCoordinate.X + 1.0f;
  square[2].Y = (float)squareCoordinate.Y + 1.0f;

  square[3].X = (float)squareCoordinate.X;
  square[3].Y = (float)squareCoordinate.Y + 1.0f;


  //return Functions::PolygonInsidePolygon(&squareRobot[0],1,&square[0],4);
  return Functions::ConvexPolygonsOverlap(&squareRobot[0], 4, &square[0], 4);
  
}

void Robot::UpdateScanXY(float moveMentIncrement, float xStep, float yStep)
{
  int second;

  if (_scanXYInit)
  {
    this->BoardPosition.X = this->BoardPosition.Y = 0.0f;
    _scanXYInit = false;
  }
  else
  {
    second = SDL_GetTicks() / 35;
    if (second % 1 == 0 && second != _scanXYlastSecond)
    {
      _scanXYlastSecond = second;

      if (_scanXYScanningInX)
      {
        this->BoardPosition.X += moveMentIncrement;

        if ((int)this->BoardPosition.X > this->_playState->GameBoard->_boardSize.Width - 1)
        {
          this->BoardPosition.X = 0.0f;
          this->BoardPosition.Y += yStep;
          if ((int)this->BoardPosition.Y > this->_playState->GameBoard->_boardSize.Height - 1)
          {
            this->BoardPosition.Y = 0.0f;
            this->BoardPosition.Y = 0.0f;
            _scanXYScanningInX = false;

          }
        }
      }
      else
      {
        this->BoardPosition.Y += moveMentIncrement;

        if ((int)this->BoardPosition.Y > this->_playState->GameBoard->_boardSize.Height - 1)
        {
          this->BoardPosition.Y = 0;
          this->BoardPosition.X += xStep;
          if ((int)this->BoardPosition.X > this->_playState->GameBoard->_boardSize.Width - 1)
          {
            this->BoardPosition.X = 0;
            this->BoardPosition.X = 0;
            _scanXYScanningInX = true;

          }
        }
      }


    }
  }


}


float Robot::FrameFloat()
{
  float f = 0.0f;
  if ( this->_currentCommand == ProgramCommandJump )
  {
    f = this->BoardPosition.Z;
  }
  else
  {
    switch( this->CurrentRotation )
    {
      case RotationClockWise0:
      case RotationClockWise180:
        f = abs(this->_boardPositionFImageFrame.X);
        break;
      case RotationClockWise90:
      case RotationClockWise270:
        f = abs(this->_boardPositionFImageFrame.Y);
        break;      
    }
  }
  return f;
}

void Robot::UpdateFrame()
{
  float percentage, f;
  
  //get the frame nearest based on the distance between two squares;
  ThemeObjectImage* themeObjectImage;
  
  themeObjectImage = this->CurrentThemeObject->FirstImage();

  //percentage = floor(this->_boardPositionFImageFrame.X);
  f = this->FrameFloat();
  percentage = modf (f, &f);  
  themeObjectImage->FrameData.Current = themeObjectImage->FrameCalculateByPercentage(percentage);;
}


//find my grid position and convert it to the world position and set coord so the board knows when to draw me
//this ia all a little backwards, there will be a better way!
void Robot::UpdateSetWorldPosition()
{
  POINT coordinateRobot, coordinate;
  RECTF robotTileRect;
  RECTF rectRender;
  BoardSquare* square1 = nullptr;
  BoardSquare* square2 = nullptr;
  BoardSquare* squareTemp = nullptr;
  
  robotTileRect = this->TileRectTransformed();  
  this->BoardPositionDiamondStart.Y = this->BoardPositionDiamondStart.X = -1;
  coordinate = this->BoardPosition.Point();

  //TODO: XXXX SORT OUT SO WE DO LESS COMPARISONS and POINT IN POLY CAN BE RECTS OVERLAP, RECTS overlap functions can change
  for( coordinate.X = 0; coordinate.X < this->_playState->GameBoard->BoardSizeGet(); coordinate.X++ )
  {
    for( coordinate.Y = 0; coordinate.Y < this->_playState->GameBoard->BoardSizeGet(); coordinate.Y++ )
    {
      if ( this->CrossesSquareAt(robotTileRect,coordinate ) )
      {
        if ( square1 == nullptr )
        { square1 = this->_playState->GameBoard->Square(coordinate,true,true); }
        else
        { square2 = this->_playState->GameBoard->Square(coordinate,true,true); }        
      }
    }
  }

  if ( square2 != nullptr && square1 != nullptr )
  {   
    if ( square1->CoordinateRender.X > square2->CoordinateRender.X || square1->CoordinateRender.Y > square2->CoordinateRender.Y )
    {
      squareTemp = square1;
      square1 = square2;
      square2 = squareTemp;

    }
    
    this->BoardPositionDiamondStart = square2->CoordinateRender;
    if ( this->BoardPositionDiamondStart.X > 0 )
    { this->BoardPositionDiamondStart.X--; }
    if ( this->BoardPositionDiamondStart.Y > 0 )
    { this->BoardPositionDiamondStart.Y--; }
    square1 = square2;    
  }
  
  if (square1 != nullptr)
  {
    this->BoardPositionRenderWith = square1->CoordinateRender;
    rectRender = this->RenderSquare();
    this->Position.X = (rectRender.X);
    this->Position.Y = (rectRender.Y);
    this->Size.Width = (int)rectRender.Width;
    this->Size.Height = (int)rectRender.Height;
  }
  
  
}

void Robot::Update()
{
  //this->UpdateScanXY(0.10f,1.0f,1.0f); //debug scan routine to scan in x and y
  this->UpdateCommand();
  this->UpdateFromCurrentCommand();
  this->UpdateForCollision();
  this->UpdateFrame();
 
  this->UpdateSetWorldPosition();
  GameObject::Update();
  return;  
}

//TODO: change to transformed or leave name but change to not transformed
RECTF Robot::TileRectTransformed()
{
  RECTF robotTileRect;
  POINTF transformed;
  
  transformed = this->_playState->GameBoard->TransForm(this->BoardPosition.PointF());
  robotTileRect.X =  transformed.X + ((1 - this->CurrentThemeObject->ScaleToParent) / 2);
  robotTileRect.Y = transformed.Y + ((1 - this->CurrentThemeObject->ScaleToParent) / 2);
  robotTileRect.Width = this->CurrentThemeObject->ScaleToParent;
  robotTileRect.Height = this->CurrentThemeObject->ScaleToParent;

  return robotTileRect;
}





//returns if finished
void Robot::UpdateFromCommandForward(int timeDifferenceInMilliseconds)
{
  float movement;

  movement = ((float)timeDifferenceInMilliseconds / 1000.0f) * this->TilesPerSecond;
  switch( this->CurrentRotation )
  {
    case RotationClockWise0:  
      this->BoardPosition.X += movement;
      this->_boardPositionFImageFrame.X  += movement;

      if ( BoardPosition.X >= (float)this->_commandDestinatonCoordinate.X )
      { this->BoardPosition.X = (float)this->_commandDestinatonCoordinate.X;  }      
      if ( this->_boardPositionFImageFrame.X >= (float)this->_commandDestinatonImageFrame.X )
      { this->_boardPositionFImageFrame.X = (float)this->_commandDestinatonImageFrame.X;  }      
      break;
    case RotationClockWise180:  
      this->BoardPosition.X -= movement;
      this->_boardPositionFImageFrame.X  -= movement;

      if ( BoardPosition.X <= (float)this->_commandDestinatonCoordinate.X )
      { this->BoardPosition.X = (float)this->_commandDestinatonCoordinate.X;  }      
      if ( this->_boardPositionFImageFrame.X <= (float)this->_commandDestinatonImageFrame.X )
      { this->_boardPositionFImageFrame.X = (float)this->_commandDestinatonImageFrame.X;  }      

      break;
    case RotationClockWise270:
      this->BoardPosition.Y -= movement;
      this->_boardPositionFImageFrame.Y  -= movement;
      if ( BoardPosition.Y <= (float)this->_commandDestinatonCoordinate.Y )
      { this->BoardPosition.Y = (float)this->_commandDestinatonCoordinate.Y;  }      
      if ( this->_boardPositionFImageFrame.Y <= (float)this->_commandDestinatonImageFrame.Y )
      { this->_boardPositionFImageFrame.Y = (float)this->_commandDestinatonImageFrame.Y;  }      
      
      break;
    case RotationClockWise90:
      this->BoardPosition.Y += movement;
      this->_boardPositionFImageFrame.Y  += movement;
      if ( BoardPosition.Y >= (float)this->_commandDestinatonCoordinate.Y )
      { this->BoardPosition.Y = (float)this->_commandDestinatonCoordinate.Y;  }      
      if ( this->_boardPositionFImageFrame.Y >= (float)this->_commandDestinatonImageFrame.Y )
      { this->_boardPositionFImageFrame.Y = (float)this->_commandDestinatonImageFrame.Y;  }      
     
     /*
      this->BoardPosition.Y -= movement;
      this->_boardPositionFImageFrame.Y  -= movement;
      if ( BoardPosition.Y <= (float)this->_commandDestinatonCoordinate.Y )
      { this->BoardPosition.Y = (float)this->_commandDestinatonCoordinate.Y;  }      
      if ( this->_boardPositionFImageFrame.Y <= (float)this->_commandDestinatonImageFrame.Y )
      { this->_boardPositionFImageFrame.Y = (float)this->_commandDestinatonImageFrame.Y;  }      
    */      
      break;
   }
}

void Robot::UpdateFromCurrentCommand()
{
  int currentTotalMiliseconds;
  int differenceInMilliseconds;
  float movement;
  BoardSquare* square;
  if ( _currentCommand == ProgramCommandEnd  || _currentCommand == ProgramCommandNext )
  { return; }

  //in 1 second we need to move this->TilesPerSecond
  currentTotalMiliseconds = SDL_GetTicks();
  differenceInMilliseconds = currentTotalMiliseconds - this->_commandTotalMilliseconds;
    
  switch( _currentCommand )
  {
    case ProgramCommandJump:     
      //todo remobved return value, I kn ow if fisniehd as currentcommand will = Next
      this->UpdateFromCommandForward(differenceInMilliseconds);//may set current commant to next      
      movement = ((float)differenceInMilliseconds / 1000.0f) * this->TilesPerSecond * 5;
      if ( this->_boardPositionFImageFrame.Z < _commandDestinatonImageFrame.Z )
      {
        this->_boardPositionFImageFrame.Z += movement; 
        this->BoardPosition.Z += movement; 
        if ( this->_boardPositionFImageFrame.Z >= this->_commandDestinatonImageFrame.Z )
        { 
          square = this->_playState->GameBoard->Square(this->BoardPosition.Point());          
          this->BoardPosition.Z = _commandDestinatonImageFrame.Z;           
          this->_boardPositionFImageFrame.Z = _commandDestinatonImageFrame.Z;
          this->_commandDestinatonImageFrame.Z = _commandDestinatonCoordinate.Z;
        }                
      }
      else
      {        
        this->_boardPositionFImageFrame.Z  -= movement;
        this->BoardPosition.Z -= movement; 
        if ( this->_boardPositionFImageFrame.Z <= _commandDestinatonImageFrame.Z )
        {  
          this->_boardPositionFImageFrame.Z = _commandDestinatonImageFrame.Z;
          this->BoardPosition.Z = _commandDestinatonCoordinate.Z;         
        }
      }
      
      break;
    case ProgramCommandMoveForward:
      this->UpdateFromCommandForward(differenceInMilliseconds);    
      break;        
    case ProgramCommandTurnLeft90Degrees:
      this->CurrentRotation = MyGame::Instance->Rotate90Degrees(this->CurrentRotation,false);   
      break;
    case ProgramCommandTurnRight90Degrees:
      this->CurrentRotation = MyGame::Instance->Rotate90Degrees(this->CurrentRotation,true);   
      break;      
    case ProgramCommandSwitchLightSwitch:
      this->_playState->GameBoard->LightStateSwitch(this->BoardPosition.Point());             
      break;
  }
        
  this->_commandTotalMilliseconds = currentTotalMiliseconds; //should be SDL_GetTicks();
  if ( this->_boardPositionFImageFrame == this->_commandDestinatonImageFrame   )
  {
    this->CommandSet(ProgramCommandNext);
  }  
}

void Robot::UpdateDestinationImageFrameMoveForward()
{
  switch ( this->CurrentRotation )
  {
    case RotationClockWise0:
      this->_commandDestinatonImageFrame.X = this->BoardPosition.X + 1.0f;
      break; 
    case RotationClockWise180: 
      this->_commandDestinatonImageFrame.X = this->BoardPosition.X - 1.0f;; //((int)Functions::Round(this->BoardPosition.X)) - 1;
      break; 
    case RotationClockWise90: 
      this->_commandDestinatonImageFrame.Y = this->BoardPosition.Y + 1.0f;
      break; 
    case RotationClockWise270: 
      this->_commandDestinatonImageFrame.Y = this->BoardPosition.Y - 1.0f;
      break; 
  }    
}

void Robot::ProgramRun()
{
  _currentCommand = ProgramCommandNext;
}
//get the next command from the program if we have finished with the current command
void Robot::UpdateCommand()
{  
  const float JUMP_HEIGHT = 2.0f;
  int zChange, destinationZ, sourceZ;
  POINT coordinate;
  if ( _currentCommand == ProgramCommandEnd )
  {
    return;
  }
  //TODO: do we need start and next, surely just next
  if ( _currentCommand != ProgramCommandNext )
  {
    return;
  }

  this->CommandSet(_playState->Program->NextCommand());
  

  _commandTotalMilliseconds = SDL_GetTicks();

  this->_commandStartCoordinate = this->BoardPosition;
  this->_commandDestinatonImageFrame = this->BoardPosition;
  this->_boardPositionFImageFrame = this->BoardPosition;

  switch ( _currentCommand )
  {    
    case ProgramCommandJump:
      this->UpdateDestinationImageFrameMoveForward();
      this->_commandDestinatonCoordinate = this->_commandDestinatonImageFrame;
      
      this->_commandDestinatonCoordinate.Z = this->_commandStartCoordinate.Z + 1.0f;
      this->_commandDestinatonImageFrame.Z += JUMP_HEIGHT;
      
      if  ( ! this->_playState->GameBoard->ContainsCoordinate(_commandDestinatonImageFrame.Point()) ) 
      { 
        this->_commandDestinatonCoordinate = _commandStartCoordinate; 
        this->_commandDestinatonImageFrame.X = _commandStartCoordinate.X;
        this->_commandDestinatonImageFrame.Y = _commandStartCoordinate.Y;
      }
      else 
      {
        zChange = this->CommandDestinationZAxisChange(&sourceZ, &destinationZ);
        if ( zChange == 0 )
        {
          this->_commandDestinatonCoordinate = _commandStartCoordinate; 
          this->_commandDestinatonImageFrame.X = _commandStartCoordinate.X;
          this->_commandDestinatonImageFrame.Y = _commandStartCoordinate.Y;
        }
        else if ( zChange < 0 )
        {
          this->_commandDestinatonCoordinate.Z = (float)destinationZ;
          //always okay
        }
        else if ( zChange > 1 )
        {
          this->_commandDestinatonCoordinate = _commandStartCoordinate; 
          this->_commandDestinatonImageFrame.X = _commandStartCoordinate.X;
          this->_commandDestinatonImageFrame.Y = _commandStartCoordinate.Y;
        }
      }
      break;
    case ProgramCommandMoveForward:
      this->UpdateDestinationImageFrameMoveForward();
      this->_commandDestinatonCoordinate = _commandDestinatonImageFrame;
      if  ( ! this->_playState->GameBoard->ContainsCoordinate(_commandDestinatonImageFrame.Point()) ) 
      { this->_commandDestinatonCoordinate =_commandStartCoordinate; }
      else if ( (zChange = this->CommandDestinationZAxisChange(&sourceZ, &destinationZ)) ) 
      { 
        this->_commandDestinatonCoordinate =_commandStartCoordinate; 
      }
      
      break;   
    default:
      _commandDestinatonCoordinate  = _commandStartCoordinate;
      _commandDestinatonImageFrame = _commandStartCoordinate;
      break;
      
       
  } 
}
