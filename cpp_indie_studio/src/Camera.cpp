/*
** camera.cpp for test in /home/denizo_r/test/irrlicht/test
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Thu May 26 16:44:53 2016 romain denizot
// Last update Sun Jun  5 22:37:23 2016 romain denizot
*/

#include "Camera.hpp"

Camera::Camera(GraphicsEngine* graph)
{
  camera = graph->getSmgr()->addCameraSceneNode();
  camera->setPosition(irr::core::vector3df(5500, 1000, 5800));
  camera->setTarget(irr::core::vector3df(5450, 150,5050));
  camera->setFarValue(4200000.0f);
}

Camera::~Camera()
{
}

irr::scene::ICameraSceneNode *Camera::getCamera()
{
  return (camera);
}

void Camera::setPosition(irr::core::vector3df position)
{
  this->camera->setPosition(position);
}

void Camera::setTarget(irr::core::vector3df position)
{
  camera->setTarget(position);
}

irr::core::vector3df Camera::getPosition()
{
  return(camera->getAbsolutePosition());
}
