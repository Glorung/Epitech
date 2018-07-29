/*
** DataRAM.cpp for rush3 in /home/denizo_r/rendu/Piscine/rush/rush3
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jan 23 21:17:47 2016 romain denizot
** Last update Sat Jan 23 22:37:57 2016 romain denizot
*/

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "DataRAM.hpp"

DataRAM::DataRAM()
{
  std::string line;
  std::ifstream infile;
  infile.open("/proc/meminfo");
  getline(infile, line);
  while (line.substr(0, 8) != "MemTotal")
    getline(infile, line);
  MemTotal = atol(line.substr(line.find_first_of("1234567890", 0)
                  , line.size() - line.find_first_of("1234567890", 0) - 3).c_str()) / 1024;
  infile.close();
}

DataRAM::~DataRAM()
{
}

long DataRAM::getMemTotal() const
{
  return (MemTotal);
}

long DataRAM::getMemType(std::string type)
{
  long res;
  std::string line;
  std::ifstream infile;
  infile.open("/proc/meminfo");
  getline(infile, line);
  while (line.substr(0, type.size()) != type)
    getline(infile, line);
  res = atol(line.substr(line.find_first_of("1234567890", 0)
                  , line.size() - line.find_first_of("1234567890", 0) - 3).c_str()) / 1024;
  infile.close();
  return (res);
}

long DataRAM::getMemUse()
{
  long memUse = MemTotal;
  memUse -= getMemType("MemFree");
  memUse -= getMemType("Cached");
  return (memUse);
}

long DataRAM::getSwapTotal()
{
  return (getMemType("SwapTotal"));
}

long DataRAM::getSwapUse()
{
  return (getMemType("SwapTotal") - getMemType("SwapFree") - getMemType("SwapCached"));
}
