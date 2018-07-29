//
// Game.cpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Wed Jun  1 13:09:06 2016 Victor Pugin
// Last update Sat Jun  4 17:56:37 2016 Victor Pugin
//
#include <irrlicht.h>
#include "driverChoice.h"
#include "Camera.hpp"
#include "Land.hpp"
#include "Game.hpp"

using namespace irr;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

Game::Game()
{
  _gfxe = new GraphicsEngine(this);
  _ge = new GameEngine(this);
  _se = new SoundEngine(this);

  _ge->setGraphicsEngine(_gfxe);
  _ge->setSoundEngine(_se);

  _gfxe->setGameEngine(_ge);
  _gfxe->setSoundEngine(_se);

  _se->setGameEngine(_ge);
  _se->setGraphicsEngine(_gfxe);

  _running = true;
}

Game::~Game()
{
  delete _ge;
  delete _gfxe;
  delete _se;
}

void	Game::run()
{
  std::unique_lock<std::mutex> is_running_lock(_running_mutex);
  bool is_running = _running;
  is_running_lock.unlock();

  _gfxe->setCollision();
  // _gfxe->draw();

  while (is_running)
    {
      _ge->frame();
      _gfxe->frame();
      _se->frame();
      is_running_lock.lock();
      is_running = _running;
      is_running_lock.unlock();
    }
}

void	Game::end()
{
  std::unique_lock<std::mutex> is_running_lock(_running_mutex);
  _running = false;
}

void	Game::save() const
{
  _ge->save();
}

GameEngine *Game::getGe() const
{
  return (_ge);
}
