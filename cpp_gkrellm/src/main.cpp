/*
** main.cpp for rush in /home/denizo_r/rendu/Piscine/rush
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sat Jan 23 13:29:02 2016 romain denizot
// Last update Sun Jan 24 03:36:32 2016 Noé Maire-Amiot
*/

#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/main.h>
#include <thread>
#include "MainWindows.hpp"
#include "displayMonitor.hpp"

int main(int argc, char **argv)
{
  std::string arg;
  if (argc > 1)
  {
    arg = argv[1];
    if (arg == "-gui")
    {
      Glib::RefPtr<Gtk::Application> app = Gtk::Application::create();
      MainWindows mainwindow;
      mainwindow.set_title("MyGKrellM");
      mainwindow.resize(600, 800);
      std::thread l (MainWindows::display, std::ref(mainwindow));
      app->run(mainwindow);
      l.detach();
    }
    else
    {
      DisplayMonitor *test = new DisplayMonitor();
      test->display();
    }
  }
  else
  {
    DisplayMonitor *test = new DisplayMonitor();
    test->display();
  }
  return (0);
}
