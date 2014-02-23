#pragma once
#include "stdafx.h"

#include "framework.h"
using namespace std;

GameObjects::GameObjects(void) : _cleared(false)
{

}

GameObjects::~GameObjects(void)
{
  this->Clear();
}

void GameObjects::Clear()
{
  GameObject* go;
  
  for(std::vector<GameObject*>::size_type i = 0; i !=  _objects.size(); i++)
  {
    go = _objects[i];
    if ( go != nullptr )
    {
      _objects[i] = nullptr;    
      delete go;    
    }
  } 
  _objects.clear();  
}

GameObject* GameObjects::Item( size_t index)
{
  return this->_objects[index];
}


void GameObjects::Add( GameObject * go )
{
  _objects.push_back(go);
  go->ParentState = Game::GameInstance->States->Current();
}

void GameObjects::AddAtStart( GameObject * go )
{
  this->Add(go,0);
}


void GameObjects::AddAfter( GameObject * go, GameObject* after )
{
  size_t i;

  for( i = 0; i < _objects.size(); i++ )
  {
    if ( _objects[i] == after )
    {
      this->Add(go, i + 1);
      break;
    }
  }  
}


void GameObjects::Add( GameObject * go, int index )
{
  _objects.insert(_objects.begin() + index,go); 
  go->ParentState = Game::GameInstance->States->Current();
}


void GameObjects::Render()
{
  GameObject* go;
  
  for(std::vector<GameObject*>::size_type i = 0; i <  _objects.size(); i++)
  {
    go = _objects[i];
    if ( go != nullptr )
    {
      go->Render();
    }    
  } 
}


size_t GameObjects::Size()
{
  return _objects.size();
}

void GameObjects::RenderDebugInfo()
{
  GameObject* go;
  
  for(std::vector<GameObject*>::size_type i = 0; i <  _objects.size(); i++)
  {
    go = _objects[i];
    if ( go != nullptr )
    {
      go->RenderDebugInfo();
    }    
  } 
}

void GameObjects::Update()
{
  GameObject* go;
  
  for(std::vector<GameObject*>::size_type i = 0; i <  _objects.size(); i++)
  {
    go = _objects[i];
    if ( go != nullptr )
    {
      go->Update();
    }    
  } 
}
