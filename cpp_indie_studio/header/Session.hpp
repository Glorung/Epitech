//
// Session.hpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Fri Jun  3 14:30:47 2016 Victor Pugin
// Last update Sun Jun  5 02:33:25 2016 Victor Pugin
//

#ifndef __SESSION_HPP__
# define __SESSION_HPP__

#include <vector>
#include <string>
#include "Player.hpp"
#include "Race.hpp"
#include <cstdlib>

class GameEngine;

class Session
{
public:
  Session(GameEngine *ge);
  ~Session();

  void addRace();
  void removeRace();
  Race *getRace(int i) const;
  GameEngine *getParent() const;

private:
  GameEngine *_parent;
  std::string _name;
  std::vector<Player *> _player;
  std::vector<Race *> _race;
  int _laps;
};

#endif /* !__SESSION_HPP__ */
