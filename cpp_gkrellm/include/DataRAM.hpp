/*
** DataRAM.hpp for rush3 in /home/denizo_r/rendu/Piscine/rush/rush3
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jan 23 21:10:18 2016 romain denizot
** Last update Sat Jan 23 22:36:23 2016 romain denizot
*/

#include <string>
#include "IMonitorModule.hpp"

#ifndef DATARAM_HPP_
# define DATARAM_HPP_

class DataRAM : public IMonitorModule
{
private:
  long MemTotal;

public:
  DataRAM();
  ~DataRAM();
  long getMemType(std::string);
  long getMemTotal() const;
  long getMemUse();
  long getSwapTotal();
  long getSwapUse();
};

#endif
