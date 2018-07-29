//
// GameEngine.cpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Wed Jun  1 14:00:40 2016 Victor Pugin
// Last update Sun Jun  5 02:32:19 2016 Victor Pugin
//

#include <iostream>
#include "GameEngine.hpp"

GameEngine::GameEngine(Game *game) :
  AEngine(game)
{
  // simulate a session
  _session = new Session(this);
}

GameEngine::~GameEngine()
{

}

void	GameEngine::frame()
{
  std::cout << "frame: GameEngine" << std::endl;
}

void	GameEngine::save() const
{

}

GraphicsEngine	*GameEngine::getGraphicsEngine() const
{
  return _gfxe;
}

Session *GameEngine::getSession() const
{
  return (_session);
}
