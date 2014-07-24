#pragma once
#include "framework.h"

class Vector2D
{
public:

  Vector2D(float x, float y);
  Vector2D();
  ~Vector2D(void); 
  float X;
  float Y;
  float Length(); 
  
  POINT_FRAMEWORK Point()
  {
    POINT_FRAMEWORK point;
    point.X = (int)Functions::Round(this->X);
    point.Y = (int)Functions::Round(this->Y);
    return point;
  }

  POINTF PointF()
  {
    POINTF point;
    point.X = this->X;
    point.Y = this->Y;
    return point;
  }

  Vector2D operator=(const Vector2D& v2);
  Vector2D operator+(const Vector2D& v2) const;
  Vector2D operator*(float scalar);
  Vector2D& operator+=(const Vector2D &rhs);

  
  Vector2D& operator*=(float scalar);
  
  Vector2D operator-(const Vector2D& v2) const;
  
  Vector2D& operator-=(const Vector2D &rhs);

  Vector2D operator/(float scalar);
  Vector2D& operator/=(float scalar);
  
  void Normalize();
  
  
};

