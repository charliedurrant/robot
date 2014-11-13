#pragma once
#include "stdafx.h"
#include "headers.h"

ButtonBar::ButtonBar(int columns, int buttonMargin, int buttonWidth, int buttonHeight) : GameObject(), _onButtonClickCallBack(nullptr)
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

void ButtonBar::OnButtonClick(std::function<void(void*, Buttn* button)> onButtonClickCallBack)
{
  this->_onButtonClickCallBack = onButtonClickCallBack;
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

void ButtonBar::Click(void* sender)
{
  Buttn* button;
  
  if (this->_onButtonClickCallBack != nullptr)
  {
    button = this->ButtonAt(Game::GameInstance->Input->Mouse->Position->Point());
    if (button != nullptr)
    {
      this->_onButtonClickCallBack(this, button);
    }    
  }
}



int ButtonBar::RowCount()
{
  return (int)Functions::Round((float)this->Children()->Size() / (float)this->ColumnCount());  
}


SIZE_FRAMEWORK ButtonBar::ButtonSize()
{
  SIZE_FRAMEWORK sz;
  RECT_FRAMEWORK r;
  r = this->RectangleLessPadding();

  sz.Width  = (r.Width - (this->ColumnCount() - 1) * (this->_buttonMargin)) / (this->ColumnCount());
  sz.Height= (r.Height - (this->RowCount() - 1) * (this->_buttonMargin)) / (this->RowCount());;
  return sz;  
}

void ButtonBar::PositionAndAutoSize(POINT_FRAMEWORK pt)
{
  SIZE_FRAMEWORK sz;
  sz = this->SizeCalculate();
  GameObject::PositionAndSize(pt.X, pt.Y, sz.Width, sz.Height);  
}

SIZE_FRAMEWORK ButtonBar::SizeCalculate()
{
  SIZE_FRAMEWORK sz;

  if ( this->Children()->Size() > 0 )
  {
    sz.Width = (this->ColumnCount() * this->_buttonSize.Width) + (this->ColumnCount() - 1 * this->_buttonMargin) + this->Padding.Width(); 
    sz.Height = (this->RowCount() * this->_buttonSize.Height) + (this->RowCount() - 1 * this->_buttonMargin) + this->Padding.Height();
  }
  else
  {
    sz.Height = sz.Width = 0;  
  }   
  return sz;         
}



Buttn* ButtonBar::ButtonAt(POINT_FRAMEWORK pt)
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
  POINT_FRAMEWORK pt, coordinate, ptStart;
  Buttn* button;
  SIZE_FRAMEWORK szButton;
  SIZE_FRAMEWORK szGrid;
 
  GameObject::Resize(width, height);
  
  szButton = this->ButtonSize();
  buttonCount = this->Children()->Size();
  szGrid.Width = this->ColumnCount();
  szGrid.Height = this->RowCount();

  if ( buttonCount )
  {
    pt= ptStart = this->RectangleLessPadding().Point();
    i = 0;
    for( coordinate.Y = 0; coordinate.Y < szGrid.Height; coordinate.Y++ )
    {
      pt.X = ptStart.X;
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


Buttn* ButtonBar::Button(int index)
{
  return (Buttn*)this->Children()->Item((size_t)index);
}