#include "WrapRam.hpp"
#include <sstream>
#include <iomanip>

WrapRam::WrapRam(int a, int b, int c) : n(c)
{
    long memUse = data.getMemUse();
    long swapUse = data.getSwapUse();
    std::stringstream ss;
    if (c == 0)
    {
        ss << "Usage : ";
        ss << memUse;
        ss << std::string("/");
        ss <<  data.getMemTotal();
        ss << "MB.";
        Usage = new Gtk::Label(ss.str());
    }
    else
    {
        ss << "Usage : ";
        ss << swapUse;
        ss << std::string("/");
        ss <<  data.getSwapTotal();
        ss << "MB.";
        Usage = new Gtk::Label(ss.str());
    }
    graph = new Graph(a, b);
    this->pack_start(*Usage,Gtk::PACK_SHRINK);
    this->pack_end(*graph, Gtk::PACK_EXPAND_WIDGET);
}

WrapRam::~WrapRam()
{
    delete this->Usage;
    delete this->graph;
}

void WrapRam::UpdateRam()
{
    std::stringstream ss;
    long Use;
    long total;
    if (n == 0)
    {
        total = data.getMemTotal();
        Use = data.getMemUse();
        ss << "Usage : ";
        ss << Use;
        ss << std::string("/");
        ss <<  total;
        ss << "MB.";
    }
    else
    {
        total = data.getSwapTotal();
        Use = data.getSwapUse();
        ss << "Usage : ";
        ss << Use;
        ss << std::string("/");
        ss <<  total;
        ss << "MB.";
    }
    this->Usage->set_text(ss.str());
    double act = static_cast<double>(static_cast<double>(Use) / static_cast<double>(total)) * 100;
    if (act < 1.00)
    act = 1.00;
    dynamic_cast<Graph*>(graph)->addPoint(static_cast<int>(act));
}
