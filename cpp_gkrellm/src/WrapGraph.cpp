#include "WrapGraph.hpp"
#include <sstream>
#include <iomanip>

WrapGraph::WrapGraph(int a, int b, int c) : n(c)
{
    std::stringstream ss;
    graph = new Graph(a, b);
    ss << cpu.getCPUact(c);
    std::string tmp = "Usage : " + ss.str() + "\%";
    this->Usage = new Gtk::Label(tmp);
    this->pack_start(*Usage,Gtk::PACK_SHRINK);
    this->pack_end(*graph, Gtk::PACK_EXPAND_WIDGET);
}

WrapGraph::~WrapGraph()
{
    delete this->Usage;
    delete this->graph;
}

void WrapGraph::UpdateUsage()
{
    std::stringstream ss;

    float act = cpu.getCPUact(n);
    ss << std::fixed << std::setprecision(2) << act;
    std::string tmp = ss.str();
    dynamic_cast<Graph*>(graph)->addPoint(static_cast<int>(act));
    if (tmp == "-0.00")
    tmp = "0.00";
    this->Usage->set_text("Usage : " + tmp + "\%");
}
