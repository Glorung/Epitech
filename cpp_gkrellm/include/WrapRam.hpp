#ifndef WrapRam_HPP_
#define WrapRam_HPP_
#include "Graph.hpp"
#include <gtkmm/box.h>
#include  <iostream>
#include <string>
#include <gtkmm/label.h>
#include "DataRAM.hpp"

class WrapRam : public Gtk::VBox
{
public:
    WrapRam(int, int, int);
    void UpdateRam();
    virtual ~WrapRam();
protected:
    Gtk::Widget *graph;
    DataRAM data;
    int n;
    Gtk::Label *Usage;
};

#endif
