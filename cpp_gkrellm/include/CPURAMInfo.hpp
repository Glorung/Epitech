#ifndef CPURAMINFO_HPP_
#define CPURAMINFO_HPP_
#include <gtkmm/table.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/alignment.h>
#include "DataCPU.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include "WrapGraph.hpp"

class CPURAMInfo : public Gtk::Table
{
public:
    CPURAMInfo();
    virtual ~CPURAMInfo();
    Gtk::Widget *graph[8];
protected:
    DataCPU data;
    Gtk::Table *InfoCPU;
    Gtk::Label *NbCore;
    Gtk::Label *specs;
    Gtk::Frame *frameCPU;
    Gtk::Frame *frame[8];
};

#endif
