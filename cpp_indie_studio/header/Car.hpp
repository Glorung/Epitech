/*
** Player.hpp for first in /home/denizo_r/test/irrlicht/first
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jun 04 15:53:31 2016 romain denizot
// Last update Sun Jun  5 02:42:04 2016 Victor Pugin
*/

#ifndef CAR_HPP_
# define CAR_HPP_

#include <irrlicht.h>
#include "GraphicsEngine.hpp"

class GraphicsEngine;
class Race;

class Car
{
public:
  Car(GraphicsEngine *ge);
  ~Car();

  void moveUp(int);
  void moveDown(int);
  void moveLeft(int);
  void moveRight(int);
  irr::scene::IAnimatedMeshSceneNode *getCar() const;

private:
  Race *_parent;
  irr::scene::IAnimatedMeshSceneNode *_car;
  irr::core::vector3df _position;
  irr::core::vector3df _rotation;
};

#endif /* !CAR_HPP_ */
