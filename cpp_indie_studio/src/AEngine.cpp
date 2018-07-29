//
// AEngine.cpp for  in /home/pugin_v/cpp/indie
// 
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
// 
// Started on  Wed Jun  1 13:13:41 2016 Victor Pugin
// Last update Wed Jun  1 14:21:23 2016 Victor Pugin
//

#include "AEngine.hpp"

AEngine::AEngine(Game *game) : _parent(game)
{

}

AEngine::~AEngine()
{

}

void	AEngine::setGameEngine(GameEngine *ge)
{
  _ge = ge;
}

void	AEngine::setGraphicsEngine(GraphicsEngine *gfxe)
{
  _gfxe = gfxe;
}

void	AEngine::setSoundEngine(SoundEngine *se)
{
  _se = se;
}
