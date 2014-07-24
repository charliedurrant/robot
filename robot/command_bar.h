#pragma once
#include "headers.h"

class CommandBarButton;

class CommandBar : public ButtonBar
{
public:
  CommandBar(int columns,  int buttonMargin, int buttonSize);
  CommandBarButton* AddButton(ProgramCommand command);
  ~CommandBar(void);  
  bool CanReceiveCommands;
  void AddButtons(int count, ProgramCommand command);
  CommandBarButton* ButtonAt(POINT_FRAMEWORK pt);
  CommandBarButton* DragButton;
  CommandBarButton* DragButtonSource;  
  void  OnCommandDragDrop(std::function<void(CommandBarButton* commandBarButton)> onCommandDragDropCallBack);
  void RaiseCommandDragDrop(CommandBarButton* commandBarButton);
  void Clear();
private:
  std::function<void(CommandBarButton* commandBarButton)> _onCommandDragDrop;
};

