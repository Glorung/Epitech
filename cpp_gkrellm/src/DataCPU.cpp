/*
** DataCPU.cpp for rush in /home/denizo_r/rendu/Piscine/rush/rush3
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jan 23 15:36:05 2016 romain denizot
** Last update Sat Jan 23 19:40:33 2016 romain denizot
*/

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "DataCPU.hpp"

DataCPU::DataCPU()
{
  std::string line;
  std::ifstream infile;
  infile.open("/proc/stat");
  getline(infile, line);
  nbCore = -1;
  while (line.substr(0, 3) == "cpu")
  {
    getline(infile, line);
    nbCore++;
  }
  infile.close();
  for (size_t i = 0; i < 4 ; i++) {
    all[i] = 0;
    activ[i] = 0;
  }
}

DataCPU::~DataCPU()
{

}

int DataCPU::getNbCore() const
{
  return (nbCore);
}

float DataCPU::getSumOfAll(std::string str)
{
  int i = str.find(" ", 0);
  int save = i;
  float res = 0;
  for (size_t j = 0; j < 10 ; j++) {
    save = i;
    i = str.find(" ", i + 1);
    res += atof(str.substr(save + 1, i - save).c_str());
  }
  return (res);
}


float DataCPU::getSumOfActiv(std::string str)
{
  int i = str.find(" ", 0);
  int save = i;
  float res = 0;
  for (size_t j = 0; j < 3 ; j++) {
    save = i;
    i = str.find(" ", i + 1);
    res += atof(str.substr(save + 1, i - save).c_str());
  }
  return (res);
  return (0);
}


float DataCPU::getCPUact(int i)
{
  if (i > nbCore)
    return (0);
  std::string line;
  std::ifstream infile;
  infile.open("/proc/stat");
  for (int j = 0; j <= i; j++) {
    getline(infile, line);
  }
  int all1 = getSumOfAll(line);
  int activ1 = getSumOfActiv(line);
  infile.close();
  float res = ((activ[i - 1] - activ1) / (all[i - 1] - all1) * 100);
  activ[i - 1] = activ1;
  all[i - 1] = all1;
  return (res);
}
#include <unistd.h>

std::string const & DataCPU::getInfo() const
{
  std::string *line = new std::string("");
  std::ifstream file;
  file.open("/proc/cpuinfo");
  while (line->substr(0, 10) != "model name")
    getline(file, *line);
  *line = line->substr(line->find(":", 0) + 2, line->size() - line->find(":", 0) + 2) ;
  return (*line);
}
