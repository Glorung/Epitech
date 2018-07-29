#include "CPURAMInfo.hpp"

CPURAMInfo::CPURAMInfo() : Table(1,1)
{
    this->set_border_width(15);
    std::stringstream ss;
    int tmp = 0;
    this->resize(2, data.getNbCore() / 2 + 1);
    frameCPU = new Gtk::Frame();
    frameCPU->set_label("Informations processeur");
    InfoCPU = new Gtk::Table(1, 2);
    ss << "\tNombre de coeurs physiques : " << data.getNbCore();
    NbCore = new Gtk::Label(ss.str().c_str());
    ss.str("");
    std::string nInfoCpu = "\tInformations Processeur : " + data.getInfo();
    specs = new Gtk::Label(nInfoCpu.c_str());
    NbCore->set_alignment(0, 0.5);
    specs->set_alignment(0, 0.5);
    InfoCPU->attach(*NbCore, 0, 1 , 0, 1);
    InfoCPU->attach(*specs, 0, 1 , 1, 2);
    frameCPU->add(*InfoCPU);

    this->attach(*frameCPU, 0, 2 , 0, 1);

    for (int i = 0 ; i != data.getNbCore(); i++)
    {
        this->frame[i] = new Gtk::Frame();
        ss << i;
        this->frame[i]->set_label("CPU " + ss.str());
        ss.str("");
    }
    for (int i = 0; i < data.getNbCore(); i++)
    {
        this->graph[i] = new WrapGraph(200, 314, i + 1);
        if (i % 2 == 0 && i != 0)
        tmp++;
        frame[i]->add (*graph[i]);
        this->attach(*frame[i], i % 2, i % 2 + 1, tmp + 1, tmp + 2, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND, 10, 10);
    }

    show_all();
}

CPURAMInfo::~CPURAMInfo()
{
    for (int i = 0; i < data.getNbCore(); i++)
    {
        delete frame[i];
    }
    delete InfoCPU;
    delete NbCore;
    delete specs;
    delete frameCPU;
}
