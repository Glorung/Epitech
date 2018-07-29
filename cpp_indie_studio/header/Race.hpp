//
// Race.hpp for  in /home/pugin_v/cpp/indie
//
// Made by Victor Pugin
// Login   <pugin_v@epitech.net>
//
// Started on  Sat Jun  4 15:13:46 2016 Victor Pugin
// Last update Sun Jun  5 02:39:09 2016 Victor Pugin
//

#ifndef __RACE_HPP__
# define __RACE_HPP__

#include <vector>
#include <string>
#include "Car.hpp"

class Session;

class Race
{
public:
  Race(Session *);
  ~Race();

  Session *getParent() const;
  void addPlayer(std::string const& file);
  Car *getCar(int i) const;

private:
  Session *_parent;
  std::vector<Car *> _car;
  int _laps;
  int _timer;
  bool _pause;
};

#endif /* !__RACE_HPP__ */
