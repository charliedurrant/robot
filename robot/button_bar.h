#pragma once
#include "headers.h"
using namespace std;

class Buttn;

class ButtonBar : public GameObject
{
public:
  ButtonBar(int columns, int buttonMargin, int buttonWidth, int buttonHeight);
  virtual ~ButtonBar(void);  
  int ColumnCount();
  int RowCount();
  void AddButton(Buttn* button);
  Buttn* ButtonAt(POINT pt);
  SIZE SizeCalculate();
  void Resize(int width, int height) override;
protected:
  SIZE ButtonSize();  
private:
  int _columns;
  int _buttonMargin;
  SIZE _buttonSize;
  
};

