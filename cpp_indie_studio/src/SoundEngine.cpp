//
// SoundEngine.cpp for  in /home/pugin_v/cpp/indie
// 
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
// 
// Started on  Wed Jun  1 14:00:40 2016 Victor Pugin
// Last update Wed Jun  1 14:11:33 2016 Victor Pugin
//

#include <iostream>
#include "SoundEngine.hpp"

SoundEngine::SoundEngine(Game *game) :
  AEngine(game)
{

}

SoundEngine::~SoundEngine()
{

}

void	SoundEngine::frame()
{
  std::cout << "frame: SoundEngine" << std::endl;
}
