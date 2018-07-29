//
// Game.hpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Wed Jun  1 13:08:12 2016 Victor Pugin
// Last update Wed Jun  1 16:34:50 2016 Victor Pugin
//

#ifndef __GAME_HPP__
# define __GAME_HPP__

#include <mutex>
#include <list>
#include "GameEngine.hpp"
#include "GraphicsEngine.hpp"
#include "SoundEngine.hpp"

class Game
{
public:
  Game();
  ~Game();

  void run();
  void end();
  void save() const;
  GameEngine *getGe() const;

private:
  std::mutex _running_mutex;
  bool _running;

private:
  GameEngine *_ge;
  GraphicsEngine *_gfxe;
  SoundEngine *_se;
};

#endif /* !__GAME_HPP__ */
