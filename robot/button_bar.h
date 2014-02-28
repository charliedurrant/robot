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
  void Click(void* sender) override;
  void Resize(int width, int height) override;  
  void OnButtonClick(std::function<void(void*, Buttn* button)> onButtonClickCallBack); //void * will be the sender i.e me
  virtual void PositionAndAutoSize(POINT pt);
  State* ParentState;
protected:
  std::function<void(void*, Buttn* button)> _onButtonClickCallBack;
  SIZE ButtonSize();  
private:  
  int _columns;
  int _buttonMargin;
  SIZE _buttonSize;
  
};

