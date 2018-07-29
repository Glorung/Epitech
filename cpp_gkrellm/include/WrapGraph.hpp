#ifndef WRAPGRAPH_HPP_
#define WRAPGRAPH_HPP_
#include "Graph.hpp"
#include <gtkmm/box.h>
#include  <iostream>
#include <string>
#include <gtkmm/label.h>
#include "DataCPU.hpp"

class WrapGraph : public Gtk::VBox
{
public:
    WrapGraph(int, int, int);
    void UpdateUsage();
    virtual ~WrapGraph();
protected:
    DataCPU cpu;
    int n;
    Gtk::Label *Usage;
    Gtk::Widget *graph;
};

#endif
