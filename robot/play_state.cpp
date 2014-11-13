#pragma once
#include "stdafx.h"
#include "headers.h"
using namespace std;
using namespace std::placeholders; // for `_1` callback arguments
using namespace fmt;

PlayState::PlayState(void) : State("play"), Program(nullptr), _lastProgramCommandButton(nullptr)
{
  
}

PlayState::~PlayState(void)
{
  if ( this->Program != nullptr )
  {
    delete this->Program;
    this->Program = nullptr;
  }
}

CommandBarButton* PlayState::FunctionButtonAt(POINT_FRAMEWORK pt)
{
  CommandBarButton* button = nullptr;

  button = this->CommandsMain->ButtonAt(pt);
  if ( button == nullptr ) { button = this->CommandsFunction1->ButtonAt(pt); }
  if ( button == nullptr ) { button = this->CommandsFunction2->ButtonAt(pt); }
  return button; 
}

string PlayState::ProgramTextGet()
{
  //generate the program text from the functions command bars  
  string program = "";

  program += this->ProgramTextGetFromFunctionCommandBar(this->CommandsMain, "main" );
  program += "\r\n";
  program += this->ProgramTextGetFromFunctionCommandBar(this->CommandsFunction1,"function1");
  program += "\r\n";
  program += this->ProgramTextGetFromFunctionCommandBar(this->CommandsFunction1,"function2");
  return Functions::Trim(program);
}

string PlayState::ProgramTextGetFromFunctionCommandBar(CommandBar* commandBar, string functionName )
{
  size_t i;
  string s;
  string line;
  CommandBarButton* button;

  s = str(fmt::Format( "def {0}():\r\n") << functionName );
  for( i = 0; i < commandBar->Children()->Size(); i++ )
  {
    button = (CommandBarButton*)commandBar->Children()->Item(i);
    line = this->Program->CommandToFunctionString( button->CommandGet() );
    if ( line.length() > 0 )
    { 
      s = s + "\t" + line + "\r\n";
    }
  }  
  return s;  
}


void PlayState::BoardRotationArrowClick(void* sender)
{
  BoardRotationArrow* arrow;

  arrow = (BoardRotationArrow*)sender;
  
  this->GameBoard->Rotate(arrow->Clockwise);
}


void PlayState::ProgramRunClick(void* sender)
{
  string text;
  this->ProgramStopClick(sender);
  text = this->ProgramTextGet();
  this->ProgText->TextSet(text);  
  this->Program->Parse(text);
  //now map back the command bar indexes back to the display so we can highlight the buttons was the program plays
  //this all seems a little circular but it makes sense as we alsways want parsing to be the correct route...
  this->MapCommandBarsIndexesFromProgram();
  this->GameBoard->RoBot->ProgramRun();
}

void PlayState::MapCommandBarsIndexesFromProgram()
{
  this->MapCommandBarIndexesFromProgramFunction(this->CommandsMain, &this->Program->_main, ProgramCommandFunctionMain);
  this->MapCommandBarIndexesFromProgramFunction(this->CommandsFunction1, &this->Program->_function1, ProgramCommandFunction1);
  this->MapCommandBarIndexesFromProgramFunction(this->CommandsFunction2, &this->Program->_function2, ProgramCommandFunction2);
  //this->Program->
}

//function maps program function commands back to the command bar buttons
void PlayState::MapCommandBarIndexesFromProgramFunction(CommandBar* commandBar, vector<ProgramCommandData>* function, ProgramCommand commandBarID)
{
  ProgramCommandData command;
  CommandBarButton* button;
  int i;
  int programIndex;

  for (programIndex = -1,i = 0; i < commandBar->Children()->Size(); i++)
  {
    button = (CommandBarButton*)commandBar->Children()->Item(i);
    command = button->CommandGet();
    
    if ( command.Command == ProgramCommandNone )
    { continue; }    

    if ( this->Program->CommandIsFunction(command) )
    { continue; }

    programIndex++;
    (*function)[programIndex].CommandBarButtonIndex = i;
    (*function)[programIndex].CommandbarID = commandBarID;
    button->CommandSet((*function)[programIndex]); ///put it back on the button
  }
}

CommandBarButton* PlayState::ProgramCurrentCommandButton()
{
  ProgramCommandData command;
  CommandBar* bar;
  CommandBarButton* button;
  command = this->GameBoard->RoBot->CommandGet();
  if (command.Command < ProgramCommandActionsStart)
  {
    return nullptr;
  }
  switch (command.CommandbarID)
  {
    case ProgramCommandFunctionMain:
      bar = this->CommandsMain;
      break;
    case ProgramCommandFunction1:
      bar = this->CommandsFunction1;
      break;
    case ProgramCommandFunction2:
      bar = this->CommandsFunction2;
      break;
    default:
      throw new Exception(str(fmt::Format("Failed to find the command bar for the command id '{0}'") << command.CommandbarID));
  }
  button = (CommandBarButton*)bar->Button(command.CommandBarButtonIndex);
  if (button->CommandGet().Command != command.Command )
  {
    throw new Exception(str(fmt::Format("Failed to find the button for the command '{0}'") << command.Command));;
  }
  return button;
}

void PlayState::ProgramStopClick(void* sender)
{  
  this->Program->Clear();
  this->GameBoard->LoadLevel(MyGame::Instance->LevlPacks->CurrentLevel());    
}

void PlayState::ProgramResetClick(void* sender)
{
  this->ProgramStopClick(sender);
  this->CommandsMain->Clear(); 
  this->CommandsFunction1->Clear();
  this->CommandsFunction1->Clear();
}

void PlayState::CommandDragDrop(CommandBarButton* sender)
{
  CommandBarButton* dragButton;

  dragButton = this->FunctionButtonAt(MyGame::GameInstance->Input->Mouse->Position->Point()); //TODO: again naff that we need to know about the play state
  if ( dragButton != nullptr )
  {
    dragButton->CommandSet(sender->CommandGet());
    //if running dont do this
    string text;
    text = this->ProgramTextGet();
  } 
}

void PlayState::Update()
{
  CommandBarButton* button;
  State::Update();
  ProgramCommandData command;
  //we update the function buttons of the program is playing, we have to do this here as we don't have a game onject to do it
  button = this->ProgramCurrentCommandButton();
  if (button != nullptr)
  {
    command = button->CommandGet();
    if ( (_lastProgramCommandButton != nullptr) && 
         ((_lastProgramCommandButtonCommand.CommandbarID != command.CommandbarID) || ( _lastProgramCommandButtonCommand.CommandBarButtonIndex != command.CommandBarButtonIndex) ))
    {
      _lastProgramCommandButton->ForceLeftButtonMouseDown = false;
    }
    _lastProgramCommandButton = button;
    _lastProgramCommandButtonCommand = command;
    button->ForceLeftButtonMouseDown = true;
  }
  else if (_lastProgramCommandButton != nullptr)
  {
    _lastProgramCommandButton->ForceLeftButtonMouseDown = false;
    _lastProgramCommandButton = nullptr;
  }

}

void PlayState::OnEnter()
{
  GameObject* go = nullptr;
  StandardBackground* background = nullptr;
  ButtonBar* buttonBar;
  Buttn* button;
  Board* board = nullptr;
  ProgramText* programText = nullptr;
  //Player* player = nullptr;
  RECT_FRAMEWORK rectBoard, rectGameObject;
  SIZEF szBoard;
  int BUTTON_MARGIN;
  int BUTTON_SIZE;
    
  COLOR color;
  SIZE_FRAMEWORK sz;
  int margin, i, right;
  try
  {
    this->Program = new RobotProgram();
  

    //TODO scale with size
    
    //BACKGROUND
    background = new StandardBackground();    
    background->PositionAndSize(0,0,MyGame::GameInstance->WindowMain->LogicalSize.Width, MyGame::GameInstance->WindowMain->LogicalSize.Height);
    this->Objects->Add(background);

    color = MyGame::Instance->Theme->BackgroundColor->Col();
    SDL_SetRenderDrawColor(MyGame::GameInstance->WindowMain->Renderer, color.r, color.g, color.b, color.a);
    
    margin = MyGame::Instance->WindowMain->ScaleToLogicalDesignHeight(50);
    //BOARD
    
    szBoard.Width = (float)MyGame::Instance->WindowMain->ScaleToLogicalDesignWidth(1200); 
    szBoard.Height = Functions::RectangleDimensionToOtherByDegrees(szBoard.Width, 25.0f);
    rectBoard.Width = (int)Functions::Round(szBoard.Width);
    rectBoard.Height = (int)Functions::Round(szBoard.Height);
    rectBoard.X = margin;
    rectBoard.Y = MyGame::GameInstance->WindowMain->LogicalSize.Height - (margin + rectBoard.Height);
    
    board = new Board(this);
    board->PositionAndSize(rectBoard);
    board->LoadLevel(MyGame::Instance->LevlPacks->CurrentLevel());
    this->GameBoard = board;
    this->Objects->Add( board);    

    

    //ROTATION ARROW RIGHT
    go = new BoardRotationArrow(false);
    go->OnClick(std::bind(&PlayState::BoardRotationArrowClick,this,_1));
    rectGameObject.Width = rectBoard.Width / 4;
    sz = Functions::ScaleToWidth(go->CurrentThemeObject->FirstImage()->Img->Size,rectGameObject.Width);
    rectGameObject.Height = sz.Height;
    i = (((rectBoard.Width / 4) -  rectGameObject.Width) / 2) ;
    rectGameObject.X = rectBoard.Right() - (i + rectGameObject.Width);
    rectGameObject.Y = rectBoard.Bottom() - (rectGameObject.Height + margin);

    go->PositionAndSize(rectGameObject);
    this->Objects->Add(go);    
    
    //ROTATION ARROW LEFT
    go = new BoardRotationArrow(true);
    go->OnClick(std::bind(&PlayState::BoardRotationArrowClick,this,_1));

    rectGameObject.X = rectBoard.X + i;
    go->PositionAndSize(rectGameObject);
    this->Objects->Add(go);    

    rectGameObject.Y = rectGameObject.X = margin;
    rectGameObject.Width = MyGame::Instance->WindowMain->ScaleToLogicalDesignWidth( 400 );
    rectGameObject.Height = MyGame::Instance->WindowMain->ScaleToLogicalDesignHeight( 300 );
    go = new HeadUpDisplay();
    go->Visible = false;
    go->PositionAndSize(rectGameObject);
    this->Objects->Add(go);   
    
    BUTTON_SIZE = MyGame::Instance->WindowMain->ScaleToLogicalDesignWidth(85);    
    BUTTON_MARGIN = MyGame::Instance->WindowMain->ScaleToLogicalDesignWidth(15);    
    
    //Command Bar - the program commands
    this->Commands = new CommandBar(-1,BUTTON_MARGIN,BUTTON_SIZE);
    this->Commands->CanReceiveCommands = false;
    this->Commands->AddButton(ProgramCommandForward);
    this->Commands->AddButton(ProgramCommandLeft);
    this->Commands->AddButton(ProgramCommandRight);
    this->Commands->AddButton(ProgramCommandJump);
    this->Commands->AddButton(ProgramCommandSwitch);
    this->Commands->AddButton(ProgramCommandFunction1);
    this->Commands->AddButton(ProgramCommandFunction2);
    
    sz = this->Commands->SizeCalculate();
    rectGameObject.Width = sz.Width;
    rectGameObject.Height = sz.Height;
    rectGameObject.Y = margin;
    rectGameObject.X = MyGame::GameInstance->WindowMain->LogicalSize.Width - (margin + rectGameObject.Width);
    
    this->Commands->OnCommandDragDrop(std::bind(&PlayState::CommandDragDrop,this,_1));
    this->Commands->PositionAndSize(rectGameObject);
    this->Objects->Add(this->Commands);   
    
    //PROGRAM TEXT
    programText = new ProgramText(this);
    rectGameObject.Width = MyGame::Instance->WindowMain->ScaleToLogicalDesignWidth(235);
    rectGameObject.Height = MyGame::Instance->WindowMain->ScaleToLogicalDesignHeight(400);
    rectGameObject.X = MyGame::GameInstance->WindowMain->LogicalSize.Width - (margin + rectGameObject.Width);
    rectGameObject.Y = this->Commands->Rentangle().Bottom() + margin;
    programText->PositionAndSize(rectGameObject);
    this->ProgText = programText;
    this->Objects->Add(this->ProgText);
    
    right = this->ProgText->Rentangle().X - BUTTON_MARGIN;
    
    //FUNCTION MAIN commands
    this->CommandsMain = new CommandBar(4,BUTTON_MARGIN, BUTTON_SIZE);
    this->CommandsMain->AddButtons(12,ProgramCommandNone);
    sz = this->CommandsMain->SizeCalculate();
    rectGameObject.Width = sz.Width;
    rectGameObject.Height = sz.Height;
    rectGameObject.Y = this->Commands->Rentangle().Bottom() + margin;
    rectGameObject.X = right - rectGameObject.Width;
    this->CommandsMain->OnCommandDragDrop(std::bind(&PlayState::CommandDragDrop,this,_1));
    this->CommandsMain->PositionAndSize(rectGameObject);
    this->Objects->Add(this->CommandsMain);   


    //FUNCTION 1 commands
    this->CommandsFunction1 = new CommandBar(4,BUTTON_MARGIN, BUTTON_SIZE);
    this->CommandsFunction1->AddButtons(8,ProgramCommandNone);
    sz = this->CommandsFunction1->SizeCalculate();
    rectGameObject.Width = sz.Width;
    rectGameObject.Height = sz.Height;
    rectGameObject.Y = this->CommandsMain->Rentangle().Bottom() + margin;
    rectGameObject.X = right - rectGameObject.Width;

    
    this->CommandsFunction1->OnCommandDragDrop(std::bind(&PlayState::CommandDragDrop,this,_1));
    this->CommandsFunction1->PositionAndSize(rectGameObject);
    this->Objects->Add(this->CommandsFunction1);   
    
    //FUNCTION 2 commands
    
    this->CommandsFunction2 = new CommandBar(4,BUTTON_MARGIN, BUTTON_SIZE);
    this->CommandsFunction2->AddButtons(8,ProgramCommandNone);
    sz = this->CommandsFunction2->SizeCalculate();
    rectGameObject.Width = sz.Width;
    rectGameObject.Height = sz.Height;
    rectGameObject.Y = this->CommandsFunction1->Rentangle().Bottom() + margin;
    rectGameObject.X = right - rectGameObject.Width;
    
    this->CommandsFunction2->OnCommandDragDrop(std::bind(&PlayState::CommandDragDrop,this,_1));
    this->CommandsFunction2->PositionAndSize(rectGameObject);
    this->Objects->Add(this->CommandsFunction2);   
   
    this->CommandBarProgramCommandHighlight = new Buttn(MyGame::Instance->Theme->CommandBarButtonJump);
    
    rectGameObject.X = rectGameObject.Y = 0;
    rectGameObject.Height = rectGameObject.Width = BUTTON_SIZE;

    this->CommandBarProgramCommandHighlight->PositionAndSize(rectGameObject);
    this->Objects->Add(this->CommandBarProgramCommandHighlight);

    //PROGRAM TEXT resize heigh
    rectGameObject = this->ProgText->Rentangle();
    rectGameObject.Height = this->CommandsFunction2->Rentangle().Bottom() - rectGameObject.Y;
    this->ProgText->PositionAndSize(rectGameObject);

    //GENERAL BUTTONS
    buttonBar = new ButtonBar(1,BUTTON_MARGIN,BUTTON_SIZE * 2,BUTTON_SIZE);
    button = new Buttn(MyGame::Instance->Theme->ButtonStopProgram);    
    buttonBar->AddButton(button);
    button->OnClick(std::bind(&PlayState::ProgramStopClick,this,_1));
    
    button = new Buttn(MyGame::Instance->Theme->ButtonRunProgram);    
    buttonBar->AddButton(button);
    button->OnClick(std::bind(&PlayState::ProgramRunClick,this,_1));
    
    button = new Buttn(MyGame::Instance->Theme->ButtonResetProgram);    
    buttonBar->AddButton(button);
    button->OnClick(std::bind(&PlayState::ProgramResetClick,this,_1));
    
    sz = buttonBar->SizeCalculate();
    rectGameObject.Width = sz.Width;
    rectGameObject.Height = sz.Height;
    rectGameObject.Y = this->CommandsMain->Position.Point().Y;
    rectGameObject.X = this->CommandsMain->Position.Point().X - (margin + rectGameObject.Width);
    buttonBar->PositionAndSize(rectGameObject);
    //I want these buttons to action at the start of the pdate cycle as they effect others state
    this->Objects->AddAfter(buttonBar,background);   
 
    
  }
  catch (Exception* ex) 
  {     
     throw new Exception("Failed to create the game",ex);
  }  

}




