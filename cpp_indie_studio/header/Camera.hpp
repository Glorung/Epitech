//
// Camera.hpp<2> for  in /home/pugin_v/cpp/cpp_indie_studio/victor
// 
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
// 
// Started on  Sat Jun  4 16:24:02 2016 Victor Pugin
// Last update Sat Jun  4 16:37:54 2016 Victor Pugin
//

#ifndef __CAMERA_HPP__
# define __CAMERA_HPP__

#include "GraphicsEngine.hpp"

class GraphicsEngine;

class Camera
{
public:
  Camera(GraphicsEngine* graph);
  ~Camera();
  irr::scene::ICameraSceneNode *getCamera();
  void setPosition(irr::core::vector3df position);
  void setTarget(irr::core::vector3df position);
  irr::core::vector3df getPosition();

private:
  irr::scene::ICameraSceneNode* camera;
};

#endif /* !__CAMERA_HPP__ */
