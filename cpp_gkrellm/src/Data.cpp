/*
** Data.cpp for rush in /home/denizo_r/rendu/Piscine/rush
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jan 23 12:05:33 2016 romain denizot
** Last update Sat Jan 23 19:20:32 2016 romain denizot
*/

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include "Data.hpp"

Data::Data()
{
}

Data::~Data()
{
}


std::string const & Data::getHours() const
{
  time_t t = time(0);
  struct tm * now = localtime( & t );
  std::stringstream ss;
  ss << std::setfill('0') << std::setw(2) << (now->tm_hour) << ':'
         << std::setfill('0') << std::setw(2) << (now->tm_min) << ':'
         << std::setfill('0') << std::setw(2) << now->tm_sec;
  std::string *Hours = new std::string(ss.str());
  return (*Hours);
}

std::string const & Data::getUser() const
{
  std::string *name = new std::string((std::getenv("HOME") + 6));
  return (*name);
}

std::string const & Data::getDate() const
{
  time_t t = time(0);
  struct tm * now = localtime( & t );
  std::stringstream ss;
  ss << std::setfill('0') << std::setw(2) <<  now->tm_mday << '/'
     << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '/'
         << (now->tm_year + 1900);
  std::string *date = new std::string(ss.str());
  return (*date);
}

std::string const & Data::getHostName() const
{
  std::ifstream file("/etc/hostname");
  std::stringstream ss;
  ss << file.rdbuf();
  std::string *os = new std::string(ss.str());
  *os = os->substr(0, os->size() - 1);
  file.close();
  return (*os);
}

std::string const & Data::getOS() const
{
  std::string *line = new std::string("");
  std::ifstream file;
  file.open("/etc/os-release");
  while (line->substr(0, 11) != "PRETTY_NAME")
    getline(file, *line);

  *line = line->substr(13, line->find("\"", 13) - 13);
  return (*line);
}

std::string const & Data::getVersion() const
{
  std::ifstream file("/proc/sys/kernel/osrelease");
  std::stringstream ss;
  ss << file.rdbuf();
  std::string *ver = new std::string(ss.str());
  *ver = ver->substr(0, ver->size() - 1);
  file.close();
  return (*ver);
}

std::string const & Data::getUpTime() const
{
  std::ifstream file("/proc/uptime");
  std::stringstream ss;
  ss << file.rdbuf();
  std::string *os = new std::string(ss.str().substr(0, ss.str().find(" " , 0)));

  int uptime = atoi(os->c_str());
  std::stringstream ss2;
  ss2 << std::setfill('0') << std::setw(2) << uptime / 3600 << ":"
      << std::setfill('0') << std::setw(2) << (uptime % 3600) / 60 << ":"
      << std::setfill('0') << std::setw(2) << (uptime % 60);
  *os = ss2.str();
  file.close();
  return (*os);
}
