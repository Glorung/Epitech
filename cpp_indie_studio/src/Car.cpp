/*
** Car.cpp for first in /home/denizo_r/test/irrlicht/first
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jun 04 16:00:48 2016 romain denizot
// Last update Sun Jun  5 22:40:18 2016 romain denizot
*/

#include <iostream>
#include <cmath>
#include "Car.hpp"
#include "GameEngine.hpp"

Car::Car(GraphicsEngine *ge) /*: _parent(parent)*/
{
   irr::scene::IAnimatedMesh* mesh = ge->getSmgr()->getMesh("file/dodge-viper-gts.obj");
  _car = ge->getSmgr()->addAnimatedMeshSceneNode( mesh );

  _position = irr::core::vector3df(5000,0,4700);
  _rotation = irr::core::vector3df(0,-90,0);
  if (_car)
  {
    _car->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _car->setFrameLoop(0, 310);
    _car->setRotation(_rotation);
    _car->setPosition(_position);
  }
}

Car::~Car()
{

}

void Car::moveUp(int speed)
{
  _position.X += cos((static_cast<int>(_rotation.Y) - 90) * irr::core::PI / 180.0) * speed;
  _position.Z -= sin((static_cast<int>(_rotation.Y) - 90) * irr::core::PI / 180.0) * speed;
  _car->setPosition(_position);

}

void Car::moveDown(int speed)
{
  _position.X -= cos((static_cast<int>(_rotation.Y) - 90) * irr::core::PI / 180.0) * speed;
  _position.Z += sin((static_cast<int>(_rotation.Y) - 90) * irr::core::PI / 180.0) * speed;
  _car->setPosition(_position);

}

void Car::moveLeft(int speed)
{
  _rotation += irr::core::vector3df(0,-5 ,0);
  _rotation.Y = static_cast<int>(_rotation.Y) % 360;
  if (_rotation.Y < 0)
  {
    _rotation.Y += 360;
  }
  _car->setRotation(_rotation);
}

void Car::moveRight(int speed)
{
  _rotation += irr::core::vector3df(0,5,0);
  if (_rotation.Y < 0)
  {
    _rotation.Y += 360;
  }
  _rotation.Y = static_cast<int>(_rotation.Y) % 360;
  _car->setRotation(_rotation);
}

irr::scene::IAnimatedMeshSceneNode *Car::getCar() const
{
  return (_car);
}
