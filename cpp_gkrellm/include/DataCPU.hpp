/*
** DataCPU.hpp for rush in /home/denizo_r/rendu/Piscine/rush/rush3
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jan 23 15:32:35 2016 romain denizot
** Last update Sat Jan 23 19:37:07 2016 romain denizot
*/

#include "IMonitorModule.hpp"
#include <string>

#ifndef DATACPU_HPP_
# define DATACPU_HPP_

class DataCPU : public IMonitorModule
{
private:
  int nbCore;
  float all[4];
  float activ[4];
  float getSumOfAll(std::string str);
  float getSumOfActiv(std::string str);

public:
  DataCPU();
  ~DataCPU();
  int getNbCore() const;
  float getCPUact(int i);
  std::string const & getInfo() const;
};

#endif
