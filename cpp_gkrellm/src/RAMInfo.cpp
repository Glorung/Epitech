#include "RAMInfo.hpp"

RAMInfo::RAMInfo() : Gtk::Table(1,1)
{
    std::stringstream ss;
    this->resize(1, 3);

    frame[0] = new Gtk::Frame();
    frame[0]->set_label("RAM");
    graph[0] = new WrapRam(337, 678, 0);
    frame[0]->add(*graph[0]);

    frame[1] = new Gtk::Frame();
    frame[1]->set_label("Swap");
    graph[1] = new WrapRam(337, 678, 1);
    frame[1]->add(*graph[1]);
    attach(*frame[0], 0, 1 , 0, 1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND, 10, 10);
    attach(*frame[1], 0, 1 , 1, 2, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND, 10, 10);
    show_all();
}

RAMInfo::~RAMInfo()
{
    delete frame[0];
    delete frame[1];
    delete graph[0];
    delete graph[1];

}
