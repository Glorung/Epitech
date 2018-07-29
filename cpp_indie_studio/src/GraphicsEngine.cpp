//
// GraphicsEngine.cpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Wed Jun  1 14:00:40 2016 Victor Pugin
// Last update Sun Jun  5 22:39:12 2016 romain denizot
//

#include <iostream>
#include "Game.hpp"
#include "GraphicsEngine.hpp"

GraphicsEngine::GraphicsEngine(Game *game) :
  AEngine(game), _game(game)
{
  driverType = irr::video::EDT_OPENGL;
  irr::SIrrlichtCreationParameters params;
	params.DriverType= driverType;
	params.WindowSize= irr::core::dimension2d<irr::u32>(640, 480);
  _events = new AEvent(this);
	device = createDevice(driverType,
        irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, _events);
  driver = device->getVideoDriver();
  smgr = device->getSceneManager();
  env = device->getGUIEnvironment();
  driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);
   device->getCursorControl()->setVisible(false);
  camera = new Camera(this);
  land = new Land(this);
  land->addCircuit();
  _car = new Car(this);
}

GraphicsEngine::~GraphicsEngine()
{
  device->drop();
}

void	GraphicsEngine::frame()
{
  if (!driver || !device->run())
    {
      _parent->end();
      return;
    }
  draw();
  std::cout << "frame: GraphicsEngine" << std::endl;
}

void	GraphicsEngine::setCollision()
{
  irr::scene::ITriangleSelector* selector
    = this->smgr->createTerrainTriangleSelector(land->getLand(), 0);
  this->land->getLand()->setTriangleSelector(selector);

  irr::scene::ISceneNodeAnimator* anim =
    smgr->createCollisionResponseAnimator(
					  selector, camera->getCamera(),
					  irr::core::vector3df(60,100,60),
					  irr::core::vector3df(0,0,0),
					  irr::core::vector3df(0,50,0));
  selector->drop();
  camera->getCamera()->addAnimator(anim);
  anim->drop();
}

void	GraphicsEngine::draw()
{
  if (device->isWindowActive())
  {
    initKeyMap();
    driver->beginScene(true, true, 0 );
    smgr->drawAll();
    env->drawAll();

    driver->endScene();
    int fps = driver->getFPS();
    irr::core::stringw str = L"Indie Studio";
    checkEvent();
    device->setWindowCaption(str.c_str());
  }
}

irr::video::IVideoDriver* GraphicsEngine::getDriver() const
{
  return (driver);
}

irr::scene::ISceneManager *GraphicsEngine::getSmgr() const
{
  return (smgr);
}

void GraphicsEngine::initKeyMap()
{
}

void GraphicsEngine::checkEvent()
{

  if(_events->IsKeyDown(irr::KEY_KEY_Q))
    _car->moveLeft(1);
  else if(_events->IsKeyDown(irr::KEY_KEY_D))
    _car->moveRight(1);


  if(_events->IsKeyDown(irr::KEY_KEY_Z))
    _car->moveUp(10);
  else if(_events->IsKeyDown(irr::KEY_KEY_S))
    _car->moveDown(10);
}
