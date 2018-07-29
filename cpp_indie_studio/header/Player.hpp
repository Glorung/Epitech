//
// Player.hpp for  in /home/pugin_v/cpp/indie
// 
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
// 
// Started on  Wed Jun  1 14:39:42 2016 Victor Pugin
// Last update Sat Jun  4 15:21:34 2016 Victor Pugin
//

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include <map>

class Player
{
public:
  Player(int id);
  ~Player();

private:
  int _id;
  bool _npc;

private:
  std::map<int, int> _bind;
};

#endif /* !__PLAYER_HPP__ */
