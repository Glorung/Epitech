/*
** Data.hpp for rush in /home/denizo_r/rendu/Piscine/rush
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jan 23 12:05:41 2016 romain denizot
** Last update Sat Jan 23 14:44:35 2016 romain denizot
*/

#include <string>
#include <map>
#include <vector>
#include "IMonitorModule.hpp"

#ifndef DATA_HPP_
#define DATA_HPP_

class Data : public IMonitorModule
{
public:
  Data();
  ~Data();
  std::string const & getDate() const;
  std::string const & getHours() const;
  std::string const & getUser() const;
  std::string const & getOS() const;
  std::string const & getVersion() const;
  std::string const & getHostName() const;
  std::string const & getUpTime() const;
};

#endif
