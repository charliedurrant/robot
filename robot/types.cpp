#pragma once
#include "stdafx.h"
#include "framework.h"
using namespace std;




#if defined(_MSC_VER)
  #define SplitPath(Path__,Drive__,Name__,Ext__) _splitpath(Path__,Drive__,Dir__,Name__,Ext__)
#elif defined(__unix)
  #define SplitPath(Path__,Drive__,Name__,Ext__) unix_splitpath(Path__,Drive__,Name__,Ext__)
#endif

POINT_FRAMEWORK operator+(POINT_FRAMEWORK const& lhs, POINT_FRAMEWORK const& rhs)
{
  POINT_FRAMEWORK ret;
  ret.X = lhs.X + rhs.X;
  ret.Y = lhs.Y + rhs.Y;
  return ret;
}

POINT_FRAMEWORK operator-(POINT_FRAMEWORK const& lhs, POINT_FRAMEWORK const& rhs)
{
  POINT_FRAMEWORK ret;
  ret.X = lhs.X - rhs.X;
  ret.Y = lhs.Y - rhs.Y;
  return ret;
}

bool operator==(POINT_FRAMEWORK const& lhs, POINT_FRAMEWORK const& rhs)
{
  return (lhs.X == rhs.X && lhs.Y == rhs.Y);
}

POINT_FRAMEWORK POINT_FRAMEWORK::operator=(POINTF const& rhs)
{
  this->X = (int)(rhs.X);
  this->Y = (int)(rhs.Y);
  return *this;
}



POINT3D operator+(POINT3D const& lhs, POINT3D const& rhs)
{
  POINT3D ret;
  ret.X = lhs.X + rhs.X;
  ret.Y = lhs.Y + rhs.Y;
  ret.Z = lhs.Z + rhs.Z;
  return ret;
}

POINT3D operator-(POINT3D const& lhs, POINT3D const& rhs)
{
  POINT3D ret;
  ret.X = lhs.X - rhs.X;
  ret.Y = lhs.Y - rhs.Y;
  ret.Z = lhs.Z - rhs.Z;
  return ret;
}

bool operator==(POINT3D const& lhs, POINT3D const& rhs)
{
  return (lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z);
}

POINT3D POINT3D::operator=(POINTF3D const& rhs)
{
  this->X = (int)(rhs.X);
  this->Y = (int)(rhs.Y);
  this->Z = (int)(rhs.Z);
  return *this;
}





POINTF operator+(POINTF const& lhs, POINTF const& rhs)
{
  POINTF ret;
  ret.X = lhs.X + rhs.X;
  ret.Y = lhs.Y + rhs.Y;
  return ret;
}

POINTF operator-(POINTF const& lhs, POINTF const& rhs)
{
  POINTF ret;
  ret.X = lhs.X - rhs.X;
  ret.Y = lhs.Y - rhs.Y;
  return ret;
}

bool operator==(POINTF const& lhs, POINTF const& rhs)
{
  return (lhs.X == rhs.X && lhs.Y == rhs.Y);
}


POINTF3D operator+(POINTF3D const& lhs, POINTF3D const& rhs)
{
  POINTF3D ret;
  ret.X = lhs.X + rhs.X;
  ret.Y = lhs.Y + rhs.Y;
  ret.Z = lhs.Z + rhs.Z;
  return ret;
}

POINTF3D operator-(POINTF3D const& lhs, POINTF3D const& rhs)
{
  POINTF3D ret;
  ret.X = lhs.X - rhs.X;
  ret.Y = lhs.Y - rhs.Y;
  ret.Z = lhs.Z - rhs.Z;
  return ret;
}

bool operator==(POINTF3D const& lhs, POINTF3D const& rhs)
{
  return (lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z);
}




