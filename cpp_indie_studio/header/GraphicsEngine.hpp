//
// GraphicsEngine.hpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Wed Jun  1 13:09:38 2016 Victor Pugin
// Last update Sun Jun  5 02:36:19 2016 Victor Pugin
//

#ifndef __GRAPHICSENGINE_HPP__
# define __GRAPHICSENGINE_HPP__

#include <irrlicht.h>
#include <map>
#include "Car.hpp"
#include "AEngine.hpp"
#include "AEvent.hpp"
#include "Camera.hpp"
#include "Land.hpp"

class Land;
class Camera;
class Car;

class GraphicsEngine : public AEngine
{
public:
  GraphicsEngine(Game *);
  virtual ~GraphicsEngine();

  virtual void frame();

  irr::video::IVideoDriver *getDriver() const;
  irr::scene::ISceneManager *getSmgr() const;
  void initKeyMap();
  void checkEvent();
  void setCollision();
  void draw();

private:
  Car *_car;
  irr::video::E_DRIVER_TYPE driverType;
  irr::IrrlichtDevice *device;
  irr::video::IVideoDriver *driver;
  irr::scene::ISceneManager *smgr;
  irr::gui::IGUIEnvironment *env;
  Camera *camera;
  Land *land;
  Game *_game;
  AEvent * _events;
};

#endif /* !__GRAPHICSENGINE_HPP__ */
