#pragma once

#include "framework.h"


typedef enum TextAlign
{
  TextAlignTopLeft,
  TextAlignMiddleLeft,
  TextAlignBottomLeft,
  TextAlignTopCenter,
  TextAlignMiddleCenter,
  TextAlignBottomCenter,
  TextAlignTopRight,
  TextAlignMiddleRight,
  TextAlignBottomRight
} TextAlign;

typedef enum FlipType
{
    FlipTypeNone = SDL_FLIP_NONE, 
    FlipTypeHorizontal = SDL_FLIP_HORIZONTAL,    /**< flip horizontally */
    FlipTypeVertical = SDL_FLIP_VERTICAL /**< flip vertically */
} FlipType;


typedef struct PADDING
{
  int Top;
  int Left;
  int Bottom;
  int Right;

  PADDING()
  {
    this->Top = this->Left = this->Bottom = this->Right = 0;
  }
  void Set(int value)
  {
    this->Top = this->Left = this->Bottom = this->Right = value;
  }

  int Width()
  {
    return this->Left + this->Right;
  }
  int Height()
  {
    return this->Top + this->Bottom;
  }

} PADDING;

typedef struct SIZE_FRAMEWORK
{
  int Width;
  int Height;
  SIZE_FRAMEWORK(int width, int height) { this->Width = width; this->Height = height; }
  SIZE_FRAMEWORK() { this->Height = this->Width = 0; }
  int Area() { return this->Height * this->Width; }
} SIZE_FRAMEWORK;


typedef SDL_Color COLOR;

typedef struct RECTF
{
  float X;
  float Y;
  float Width;
  float Height;
  float Right() { return this->X + this->Width; };
  float Bottom() { return this->Y + this->Height; };
} RECTF;


typedef struct SIZEF
{
  float Width;
  float Height;
} SIZEF;

enum CycleMode
{
  CycleModeLeftToRight = 0,
  CycleModeRightToLeft = 1,
  CycleModeBackAndForth = 3
};

typedef struct FRAME_DATA
{
  int Start;
  int End;
  int PerSecond;
  int Current;
  int Total;
  CycleMode CyclMode;
  int CycleIncrement;
  int LastTicks;
  
  FRAME_DATA()
  {
    this->LastTicks = 0;
  }

  int TotalCalculate()
  { 
    return (this->End - this->Start) + 1; 
  }
  void Reset()
  {
    if ( this->CyclMode == CycleModeRightToLeft )
    {
      this->Current = this->End;
      this->CycleIncrement = -1;
    }
    else
    {
      this->Current = this->Start;
      this->CycleIncrement = 1;
    }
  }
  bool HasFramesToClycle()
  {
    return this->PerSecond && (this->Start != this->End);    
  }
} FRAME_DATA;

struct POINTF;

typedef struct POINT_FRAMEWORK
{
  int X;
  int Y;
  POINT_FRAMEWORK operator=(POINTF const& rhs);
  POINT_FRAMEWORK() { this->X = this->Y = 0; };
  
  std::string ToString()
  {
    std::string s;
    s = str(fmt::Format("x({0}), y({1})") << this->X << this->Y );
    return s;
  };

  int DistanceBetweenSquared(POINT_FRAMEWORK pt)
  {
    SIZE_FRAMEWORK sz;
    int i;

    sz.Width = this->X - pt.X;
    sz.Height  = this->Y - pt.Y;

    i = (sz.Height * sz.Height) + (sz.Width + sz.Width);;
    if (i < 0)
    { 
      i*= -1;
    }
    return i;
  }
  
} POINT_FRAMEWORK;

POINT_FRAMEWORK operator+(POINT_FRAMEWORK const& lhs, POINT_FRAMEWORK const& rhs);
POINT_FRAMEWORK operator-(POINT_FRAMEWORK const& lhs, POINT_FRAMEWORK const& rhs);

bool operator==(POINT_FRAMEWORK const& lhs, POINT_FRAMEWORK const& rhs);


struct POINTF3D;

typedef struct POINT3D
{
  int X;
  int Y;
  int Z;
  POINT3D operator=(POINTF3D const& rhs);
  POINT3D() { this->Z = this->X = this->Y = 0; };
  POINT_FRAMEWORK Point() { POINT_FRAMEWORK pt; pt.X = this->X; pt.Y = this->Y; return pt; }
} POINT3D;

POINT3D operator+(POINT3D const& lhs, POINT3D const& rhs);
POINT3D operator-(POINT3D const& lhs, POINT3D const& rhs);
bool operator==(POINT3D const& lhs, POINT3D const& rhs);


typedef struct POINTF
{
  float X;
  float Y;
  POINTF operator=(POINT_FRAMEWORK const& rhs)
  {
    this->X = (float)rhs.X;
    this->Y = (float)rhs.Y;
    return *this;
  }
  POINTF() { this->X = this->Y = 0.0f; };
  std::string ToString()
  {
    std::string s;
    s = str(fmt::Format("x({0}), y({1})") << this->X << this->Y );
    return s;
  };

  float DistanceBetweenSquared(POINTF pt)
  {
    SIZEF sz;

    sz.Width = this->X - pt.X;
    sz.Height = this->Y - pt.Y;

    return (sz.Height * sz.Height) + (sz.Width + sz.Width);
  }



} POINTF;


POINTF operator+(POINTF const& lhs, POINTF const& rhs);
POINTF operator-(POINTF const& lhs, POINTF const& rhs);
bool operator==(POINTF const& lhs, POINTF const& rhs);


typedef struct POINTF3D
{
  float X;
  float Y;
  float Z;
  POINTF3D operator=(POINT_FRAMEWORK const& rhs)
  {
    this->X = (float)rhs.X;
    this->Y = (float)rhs.Y;    
    return *this;
  }
  POINTF3D operator=(POINTF3D const& rhs)
  {
    this->X = rhs.X;
    this->Y = rhs.Y;    
    this->Z = rhs.Z;    
    return *this;
  }
  POINT_FRAMEWORK Point() { POINT_FRAMEWORK pt; pt.X = (int)this->X; pt.Y = (int)this->Y; return pt; }
  POINTF PointF() { POINTF pt; pt.X = this->X; pt.Y = this->Y; return pt; }
  POINTF3D() { this->X = this->Y = this->Z = 0.0f; };
  std::string ToString()
  {
    return str(fmt::Format("X({0}), Y({1}), Z({2})") << this->X << this->Y << this->Z);    
  };
} POINTF3D;



POINTF3D operator+(POINTF3D const& lhs, POINTF3D const& rhs);
POINTF3D operator-(POINTF3D const& lhs, POINTF3D const& rhs);
bool operator==(POINTF3D const& lhs, POINTF3D const& rhs);

typedef struct RECT_FRAMEWORK
{
  int X;
  int Y;
  int Width;
  int Height;

  RECT_FRAMEWORK()
  {
    this->X = this->Y = this->Width = this->Height = 0;
  }

  SIZE_FRAMEWORK Size()
  {
    SIZE_FRAMEWORK sz;
    sz.Width = this->Width;
    sz.Height = this->Height;
    return sz;
  }
  int Bottom()
  {
    return this->Y + this->Height;
  }
  int Right()
  {
    return this->X + this->Width;
  }
  void MoveBy(SIZE_FRAMEWORK sz)
  {
    this->X += sz.Width;
    this->Y += sz.Height;
  }
  void SizeSet(SIZE_FRAMEWORK sz)
  {
    this->Width = sz.Width;
    this->Height = sz.Height;
  }

  POINT_FRAMEWORK Point()
  {
    POINT_FRAMEWORK pt;

    pt.X += this->X;
    pt.Y += this->Y;
    return pt;
  }
  
  std::string ToString()
  {
    std::string s;
    s = str(fmt::Format("x({0}), y({1})\nw({2}), h({3})") << this->X << this->Y << this->Width << this->Height);
    return s;
  }

  POINT_FRAMEWORK Center()
  {
    POINT_FRAMEWORK pt;

    pt.X = this->X  + this->Width / 2;
    pt.Y = this->Y + this->Height / 2;
    return pt;
  }

  int DistanceBetweenSquared(POINT_FRAMEWORK pt)
  {
    POINT_FRAMEWORK ptTemp;
    int distance = 0;
    int right;
    int bottom;

    if (this->Contains(pt))
    { return 0; }

    if (pt.X < this->X)
    { 
      ptTemp.X = this->X;
      if (pt.Y < this->Y)
      {
        ptTemp.Y = this->Y;
      }
      else if (pt.Y >(bottom = this->Bottom()))
      {
        ptTemp.Y = bottom;

      }
      else
      {
        ptTemp.Y = pt.Y;
      }
    }
    else if (pt.X > (right = this->Right()))
    {
      ptTemp.X = right;
      if (pt.Y < this->Y)
      {
        ptTemp.Y = this->Y;
      }
      else if (pt.Y >(bottom = this->Bottom()))
      {
        ptTemp.Y = bottom;
      }
      else
      {
        ptTemp.Y = pt.Y;
      }
    }
    else
    {
      ptTemp.X = pt.X;
      if (pt.Y < this->Y)
      {
        ptTemp.Y = this->Y;
      }
      else if (pt.Y >(bottom = this->Bottom()))
      {
        ptTemp.Y = bottom;
      }
      else
      {
        ptTemp.Y = pt.Y;
      }
    }

    distance = ptTemp.DistanceBetweenSquared(pt);
    return distance;
  }

  bool Contains(POINT_FRAMEWORK pt)
  {
    if ( this->X <= pt.X && this->Right() >= pt.X )
    {
      if ( this->Y <= pt.Y && this->Bottom() >= pt.Y )
      {
        return true;
      }
    }
    return false;
  }

  
} RECT_FRAMEWORK;



//bool operator!=(POINTF const& lhs, POINTF const& rhs);

enum MouseButtonState
{
  MouseButtonUp = 0,
  MouseButtonDown = 1,  
  MouseButtonClicked = 2,  
};



