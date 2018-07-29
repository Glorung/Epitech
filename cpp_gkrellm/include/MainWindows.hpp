#ifndef MAINWINDOWS_HPP_
#define MAINWINDOWS_HPP_
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/notebook.h>
#include "Informations.hpp"
#include <unistd.h>
#include <iostream>
#include <thread>
#include "Graph.hpp"
#include "CPURAMInfo.hpp"
#include "WrapGraph.hpp"
#include "RAMInfo.hpp"
#include "WrapRam.hpp"
#include "Koala.hpp"

class MainWindows : public Gtk::Window
{
public:
    MainWindows();
    virtual ~MainWindows();
    static void display(MainWindows &);
    bool wantQuit();
    void QUIT();
protected:
  DataCPU datacpu;
  Gtk::Notebook onglets;
  Gtk::VBox boiteV;
  Informations info;
  CPURAMInfo cpu;
  RAMInfo ram;
  Koala koala;
  bool quit;
};

#endif
