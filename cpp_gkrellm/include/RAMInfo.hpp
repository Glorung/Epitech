#ifndef RAMINFO_HPP_
#define RAMINFO_HPP_
#include <gtkmm/table.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/alignment.h>
#include "DataRAM.hpp"
#include "WrapRam.hpp"
#include <sstream>
#include <string>
#include <iostream>

class RAMInfo : public Gtk::Table
{
public:
    RAMInfo();
    virtual ~RAMInfo();
    Widget *graph[2];
protected:
    Gtk::Frame *frame[2];
};

#endif
