#pragma once
#include "stdafx.h"
#include "headers.h"

ButtonBar::ButtonBar(int columns, int buttonMargin, int buttonWidth, int buttonHeight) : GameObject() 
{
  this->_columns = columns;
  this->_buttonMargin = buttonMargin;
  this->_buttonSize.Width = buttonWidth;
  this->_buttonSize.Height = buttonHeight;  
}

ButtonBar::~ButtonBar(void)
{
  ; 
}

void ButtonBar::AddButton(Buttn* button)
{
  this->Children()->Add(button);
}

int ButtonBar::ColumnCount()
{
  int columns;

  if ( this->_columns == -1 )
  {
    columns = (int)this->Children()->Size();
  }
  else
  {
    columns = this->_columns;
  }
  return columns;
}

int ButtonBar::RowCount()
{
  return (int)Functions::Round((float)this->Children()->Size() / (float)this->ColumnCount());  
}


SIZE ButtonBar::ButtonSize()
{
  SIZE sz;
  
  sz.Width  = (this->Size.Width - (this->ColumnCount() - 1) * (this->_buttonMargin)) / (this->ColumnCount());
  sz.Height= (this->Size.Height - (this->RowCount() - 1) * (this->_buttonMargin)) / (this->RowCount());;
  return sz;  
}

SIZE ButtonBar::SizeCalculate()
{
  SIZE sz;

  if ( this->Children()->Size() > 0 )
  {
    sz.Width = (this->ColumnCount() * this->_buttonSize.Width) + (this->ColumnCount() - 1 * this->_buttonMargin); 
    sz.Height = (this->RowCount() * this->_buttonSize.Height) + (this->RowCount() - 1 * this->_buttonMargin);   
  }
  else
  {
    sz.Height = sz.Width = 0;  
  }   
  return sz;         
}

Buttn* ButtonBar::ButtonAt(POINT pt)
{
  size_t i;
  Buttn* button;
  if ( ! this->Rentangle().Contains(pt) )
  { return nullptr; }
  
  for( i = 0; i < this->Children()->Size(); i++ )
  {
    button = (Buttn*)this->Children()->Item(i);
    if ( button == nullptr )
    { continue; }
    if ( button->Rentangle().Contains(pt) )
    {
      return button;
    }
  }
  return nullptr;
}


void ButtonBar::Resize(int width, int height)
{
  int buttonCount;
  int i;
  POINT pt, coordinate;
  Buttn* button;
  SIZE szButton;
  SIZE szGrid;
  
  GameObject::Resize(width, height);
  
  szButton = this->ButtonSize();
  buttonCount = this->Children()->Size();
  szGrid.Width = this->ColumnCount();
  szGrid.Height = this->RowCount();

  if ( buttonCount )
  {
    pt = this->Position.Point();
    i = 0;
    for( coordinate.Y = 0; coordinate.Y < szGrid.Height; coordinate.Y++ )
    {
      pt.X = (int)this->Position.X;
      for( coordinate.X = 0; coordinate.X < szGrid.Width; coordinate.X++ )
      {
        button = (Buttn*)this->Children()->Item((size_t)i);
        button->PositionAndSize(pt.X, pt.Y, szButton.Width, szButton.Height);
        pt.X += szButton.Height + _buttonMargin;
        i++;
        if ( i > buttonCount  - 1)
        { break; } 
      }
      pt.Y += this->_buttonMargin + szButton.Height;
    }        
  }

}

