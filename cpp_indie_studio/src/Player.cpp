//
// Player.cpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Wed Jun  1 14:44:50 2016 Victor Pugin
// Last update Fri Jun  3 15:23:47 2016 Victor Pugin
//

#include "Player.hpp"

Player::Player(int id) : _id(id)
{
  if (_id == 1)
    _npc = false;
  else
    _npc = true;
  
}

Player::~Player()
{

}
