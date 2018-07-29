/*
** displayMonitor.hpp for diplayMonitor in /home/maire-_n/Documents/Tek2/Rush/Gkrellm
**
** Made by Noé Maire-Amiot
** Login   <maire-_n@epitech.net>
**
** Started on  Sat Jan 23 14:46:06 2016 Noé Maire-Amiot
** Last update Sun Jan 24 04:13:42 2016 Noé Maire-Amiot
*/

#ifndef DISPLAYMONITOR_HPP_
#define DISPLAYMONITOR_HPP_

#include <ncurses/curses.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Data.hpp"
#include "DataCPU.hpp"
#include "DataRAM.hpp"
#include "IMonitorDisplay.hpp"

class DisplayMonitor : public IMonitorDisplay
{
private:
  Data *_data;
  DataCPU *_dataCPU;
  DataRAM *_dataRAM;
public:
  DisplayMonitor();
  ~DisplayMonitor();
  void display();
  void dUser();
  void dHostName();
  void dOS();
  void dVersion();
  void dTime();
  void dUptime();
  void dProgressBar(int i);
  void dRam(int nbCpu);
  void dSwap(int nbCpu);
  void dKoala();
  void dHelp();
};

#endif
