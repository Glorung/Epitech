//
// Session.cpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Fri Jun  3 14:38:55 2016 Victor Pugin
// Last update Sun Jun  5 02:34:08 2016 Victor Pugin
//

#include "Session.hpp"

Session::Session(GameEngine *ge) : _parent(ge), _name("session")
{
  for (int i = 1 ; i < 5 ; ++i)
    _player.push_back(new Player(i));
  //_race.push_back(new Race(this));
}

Session::~Session()
{
  _player.clear();
  _race.clear();
}

void	Session::addRace()
{
  _race.push_back(new Race(this));
}

void	Session::removeRace()
{
  _race.pop_back();
}

GameEngine	*Session::getParent() const
{
  return _parent;
}


Race *Session::getRace(int i) const
{
  return ((_race.size() > i) ? _race[i] : NULL);
}
