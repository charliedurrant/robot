#pragma once
#include "stdafx.h"
#include "framework.h"

using namespace std;

Vector2D::Vector2D()
{
  this->X = 0;
  this->Y = 0;
}

Vector2D::Vector2D(float x, float y)
{
  this->X = x;
  this->Y = y;
}

Vector2D::~Vector2D(void)
{
  ;  
}

float Vector2D::Length()
{
  return sqrt(this->X * this->X + this->Y * this->Y);
}

Vector2D Vector2D::operator+(const Vector2D& v2) const
{  
  return Vector2D(this->X + v2.X, this->Y + v2.Y);
}


Vector2D& Vector2D::operator+=(const Vector2D &rhs)
{
  this->X += rhs.X;
  this->Y += rhs.Y;
  return *this;
}


Vector2D Vector2D::operator*(float scalar)
{
  return Vector2D(X * scalar, Y * scalar);
}

Vector2D& Vector2D::operator*=(float scalar)
{
  this->X = (this->X * scalar);
  this->Y = (this->Y * scalar);
  return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v2) const
{
  return Vector2D(this->X - v2.X, this->Y - v2.Y);
}
 

Vector2D& Vector2D::operator-=(const Vector2D &rhs)
{
  this->X -= rhs.X;
  this->Y -= rhs.Y;
  return *this;
}

Vector2D Vector2D::operator=(Vector2D const& v2)
{
  this->X = v2.X;
  this->Y = v2.Y;
  return *this;
}

Vector2D Vector2D::operator/(float scalar)
{
  return Vector2D(Y / scalar, Y / scalar);
}

Vector2D& Vector2D::operator/=(float scalar)
{
  Y = (X / scalar);
  Y = (Y / scalar);

  return *this;
}

void Vector2D::Normalize()
{
  float l = this->Length();
  if (l > 0) // we never want to attempt to divide by 0
  {
    (*this) *= 1 / l;
  }
}




