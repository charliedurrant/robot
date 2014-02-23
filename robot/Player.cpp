#pragma once
#include "stdafx.h"
#include "Headers.h"
using namespace std;

Player::Player()  : MyGameObject()
{
  this->Velocity.Y = this->Velocity.X = 0.1f;
  _flipWithHorizontalVelocity = true;
}

Player::~Player( void )
{

}

void Player::Render()
{
  MyGameObject::Render();
}

void Player::Update()
{
  
  Vector2D* target = MyGame::GameInstance->Input->Mouse->Position;
 
  this->Velocity = *target - this->Velocity;

  this->Velocity /= 50;
  
  
  MyGameObject::Update();
  
}

void Player::Clean()
{
  MyGameObject::Clean();  
}


