/*
** displayMonitor.cpp for DisplayMonitor in /home/maire-_n/Documents/Tek2/Rush/Gkrellm
**
** Made by Noé Maire-Amiot
** Login   <maire-_n@epitech.net>
**
** Started on  Sat Jan 23 15:22:58 2016 Noé Maire-Amiot
** Last update Sun Jan 24 04:13:55 2016 Noé Maire-Amiot
*/

#include "displayMonitor.hpp"

DisplayMonitor::DisplayMonitor() : _data(new Data), _dataCPU(new DataCPU), _dataRAM(new DataRAM)
{
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, 1);
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_BLACK, COLOR_CYAN);
}

DisplayMonitor::~DisplayMonitor()
{
}

void DisplayMonitor::display()
{
  int _key = 0;
  while (_key != 113 && _key != 3 && _key != 274)
  {
    clear();
    dTime();
    dUser();
    dHostName();
    dOS();
    dVersion();
    dUptime();
    for (int i = 1; i < this->_dataCPU->getNbCore() + 1; i++)
    {
      dProgressBar(i);
    }
    dRam(this->_dataCPU->getNbCore());
    dSwap(this->_dataCPU->getNbCore());
    if (LINES > 33 && COLS > 30)
    dKoala();
    dHelp();
    timeout(1500);
    _key = getch();

  }
  refresh();
  endwin();
}

void DisplayMonitor::dUser()
{
  std::string tmp = this->_data->getUser();
  attron(COLOR_PAIR(2));
  mvprintw(5, 5, "User :");
  attron(A_BOLD);
  mvprintw(5, 24, tmp.c_str());
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
}

void DisplayMonitor::dHostName()
{
  std::string tmp = this->_data->getHostName();
  attron(COLOR_PAIR(2));
  mvprintw(6, 5, "Hostname :");
  attron(A_BOLD);
  mvprintw(6, 24, tmp.c_str());
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
}

void DisplayMonitor::dOS()
{
  std::string tmp = this->_data->getOS();
  attron(COLOR_PAIR(2));
  mvprintw(7, 5, "Operating System :");
  attron(A_BOLD);
  mvprintw(7, 24, tmp.c_str());
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
}

void DisplayMonitor::dVersion()
{
  std::string tmp = this->_data->getVersion();
  attron(COLOR_PAIR(2));
  mvprintw(8, 5, "Kernel version :");
  attron(A_BOLD);
  mvprintw(8, 24, tmp.c_str());
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
}

void DisplayMonitor::dTime()
{
  std::string date = "|| " + this->_data->getDate() + " ||";
  std::string beg = "=";
  std::string hours = "|| " + this->_data->getHours();
  for (size_t i = 0; i < date.size() - 1; i++) {
    beg += "=";
  }
  attron(COLOR_PAIR(1));
  mvprintw(0, ((COLS/2) - (date.size()/2)) - 1, beg.c_str());
  mvprintw(1, ((COLS/2) - (date.size()/2)) - 1, date.c_str());
  mvprintw(2, ((COLS/2) - (date.size()/2)) - 1, hours.c_str());
  mvprintw(2, ((COLS/2) + (date.size()/2)) - 3, "||");
  mvprintw(3, ((COLS/2) - (date.size()/2)) - 1, beg.c_str());
  attroff(COLOR_PAIR(1));

}

void DisplayMonitor::dUptime()
{
  std::string tmp = this->_data->getUpTime();
  attron(COLOR_PAIR(2));
  mvprintw(10, 5, "Uptime :");
  attron(A_BOLD);
  mvprintw(10, 24, tmp.c_str());
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
}

void DisplayMonitor::dProgressBar(int nbCpu)
{
  float per_float = this->_dataCPU->getCPUact(nbCpu);
  if (per_float == -0)
  per_float = 0;
  int per_int = static_cast<int>(per_float);
  std::stringstream cpu;
  cpu << nbCpu;
  std::stringstream percent;
  percent << std::fixed << std::setprecision(2) << per_float;
  mvprintw(12 + nbCpu, 5, cpu.str().c_str());
  mvprintw(12 + nbCpu, 8, "[");
  mvprintw(12 + nbCpu, COLS - 11, percent.str().c_str());
  mvprintw(12 + nbCpu, COLS - 5, "%%");
  for (int i = 9; i < COLS - 13 ; i++)
  {
    if (i - 9 < (per_int * (COLS - 22)) / 100)
    {
      if (i - 9 < ((COLS - 22)/4)*3)
      {
        attron(COLOR_PAIR(3));
        mvprintw(12 + nbCpu, i, "|");
        attroff(COLOR_PAIR(3));
      }
      else
      {
        attron(COLOR_PAIR(4));
        mvprintw(12 + nbCpu, i, "|");
        attroff(COLOR_PAIR(4));
      }
    }
  }
  mvprintw(12 + nbCpu, COLS - 13, "]");
}

void DisplayMonitor::dKoala()
{
  mvprintw(20, (COLS/2) - 15, "  ___..._           _...__");
  mvprintw(21, (COLS/2) - 15, "/'--.._ `'-=\"\"\"=-'` _..--'\\");
  mvprintw(22, (COLS/2) - 15, "|   ~. )  _     _  ( .~   |");
  mvprintw(23, (COLS/2) - 15, " \\  '~/   a  _  a   \\~'  /");
  mvprintw(24, (COLS/2) - 15, "  \\  `|     / \\     |`  /");
  mvprintw(25, (COLS/2) - 15, "   `'--\\    \\_/    /--'`");
  mvprintw(26, (COLS/2) - 15, "       .'._  J__.-'.");
  mvprintw(27, (COLS/2) - 15, "      / /  '-/_ `-  \\");
  mvprintw(28, (COLS/2) - 15, "     / -\"-'-.  '-.__/");
  mvprintw(29, (COLS/2) - 15, "     \\__,-.\\/     | `\\");
  mvprintw(30, (COLS/2) - 15, "     /  ;---.  .--'   |");
  mvprintw(31, (COLS/2) - 15, "    |     /\\'-'      /");
  mvprintw(32, (COLS/2) - 15, "    '.___.\\   _.--;'`)");
  mvprintw(33, (COLS/2) - 15, "           '-'     `\"");
}

void DisplayMonitor::dHelp()
{
  mvprintw(LINES - 1, 0, "F10");
  attron(COLOR_PAIR(5));
  mvprintw(LINES - 1, 3, "Quit");
  attroff(COLOR_PAIR(5));
}

void DisplayMonitor::dRam(int nbCpu)
{
  long total = this->_dataRAM->getMemTotal();
  long use = this->_dataRAM->getMemUse();
  long percent = (use * 100) / total;
  std::stringstream strTotal;
  strTotal << total;
  std::stringstream strUse;
  strUse << use;
  mvprintw(13 + nbCpu, 5, "Mem");
  mvprintw(13 + nbCpu, 8, "[");
  mvprintw(13 + nbCpu, COLS - 6, strTotal.str().c_str());
  mvprintw(13 + nbCpu, COLS -7, "/");
  mvprintw(13 + nbCpu, COLS - 11, strUse.str().c_str());
  mvprintw(13 + nbCpu, COLS - 2, "MB");
  for (int i = 9; i < COLS - 13 ; i++)
  {
    if (i - 9 < (percent * (COLS - 22)) / 100)
    {
      if (i - 9 < ((COLS - 22)/4)*3)
      {
        attron(COLOR_PAIR(3));
        mvprintw(13 + nbCpu, i, "|");
        attroff(COLOR_PAIR(3));
      }
      else
      {
        attron(COLOR_PAIR(4));
        mvprintw(13 + nbCpu, i, "|");
        attroff(COLOR_PAIR(4));
      }
    }
  }
  mvprintw(13 + nbCpu, COLS - 13, "]");
}

void DisplayMonitor::dSwap(int nbCpu)
{
  long total = this->_dataRAM->getSwapTotal();
  long use = this->_dataRAM->getSwapUse();
  long percent = (use * 100) / total;
  std::stringstream strTotal;
  strTotal << total;
  std::stringstream strUse;
  strUse << use;
  mvprintw(14 + nbCpu, 5, "Swp");
  mvprintw(14 + nbCpu, 8, "[");
  mvprintw(14 + nbCpu, COLS - 6, strTotal.str().c_str());
  mvprintw(14 + nbCpu, COLS -7, "/");
  mvprintw(14 + nbCpu, COLS - 11, strUse.str().c_str());
  mvprintw(14 + nbCpu, COLS - 2, "MB");
  for (int i = 9; i < COLS - 13 ; i++)
  {
    if (i - 9 < (percent * (COLS - 22)) / 100)
    {
      if (i - 9 < ((COLS - 22)/4)*3)
      {
        attron(COLOR_PAIR(3));
        mvprintw(14 + nbCpu, i, "|");
        attroff(COLOR_PAIR(3));
      }
      else
      {
        attron(COLOR_PAIR(4));
        mvprintw(14 + nbCpu, i, "|");
        attroff(COLOR_PAIR(4));
      }
    }
  }
  mvprintw(14 + nbCpu, COLS - 13, "]");
}
