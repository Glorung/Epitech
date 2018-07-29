//
// Race.cpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Sat Jun  4 15:27:30 2016 Victor Pugin
// Last update Sun Jun  5 02:45:52 2016 Victor Pugin
//

#include "Race.hpp"
#include <iostream>

Race::Race(Session *parent) : _parent(parent)
{
  addPlayer("plop");
  std::cout << "FUUUUUUUUUUUUUUUUUUUU" << std::endl;
}

Race::~Race()
{

}

Session	*Race::getParent() const
{
  return _parent;
}

Car *Race::getCar(int i) const
{
  return ((_car.size() > i) ? _car[i] : NULL);
}

void Race::addPlayer(std::string const& file)
{
//  _car.push_back(new Car(this ,1));
}
