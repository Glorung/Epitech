#include "Informations.hpp"

Informations::Informations(bool a, int r) : VBox(a, r)
{
    this->set_border_width(15);

    std::string nMachine = "\tMachine Name : " + data.getHostName();
    std::string nUser =    "\tUser Name       : " + data.getUser();
    std::string nUptime =  "\tUptime             : " + data.getUpTime();

    std::string nVersion = "\tVersion             : " + data.getVersion();
    std::string nOS =      "\tOS                    : " + data.getOS();

    std::string nDate =    "\tDate                  : " + data.getDate();
    std::string nTime =    "\tTime                  : " + data.getHours();

    first = new Gtk::Table(3, 3);
    second = new Gtk::Table(3, 3);
    third = new Gtk::Table(3, 3);

    Label_MachineName = new Gtk::Label(nMachine.c_str());
    Label_UserName = new Gtk::Label(nUser.c_str());
    Label_Uptime = new Gtk::Label(nUptime.c_str());
    Label_MachineName->set_alignment(0, 0.5);
    Label_UserName->set_alignment(0, 0.5);
    Label_Uptime->set_alignment(0, 0.5);
    first->attach(*Label_MachineName, 0, 2, 0, 1);
    first->attach(*Label_UserName, 0, 2, 1, 2);
    first->attach(*Label_Uptime, 0, 2, 2, 3);

    Name.set_label("Machine name and User name");
    Name.set_label_align(Gtk::ALIGN_START);
    Name.add(*first);

    Label_Version = new Gtk::Label(nVersion.c_str());
    Label_OS = new Gtk::Label(nOS.c_str());
    Label_Version->set_alignment(0, 0.5);
    Label_OS->set_alignment(0, 0.5);
    second->attach(*Label_OS, 0, 2, 0, 1);
    second->attach(*Label_Version, 0, 2, 1, 2);

    OS.set_label("Operating system and Kernel version");
    OS.set_label_align(Gtk::ALIGN_START);
    OS.add(*second);

    Label_Date = new Gtk::Label(nDate.c_str());
    Label_Time = new Gtk::Label(nTime.c_str());
    Label_Date->set_alignment(0, 0.5);
    Label_Time->set_alignment(0, 0.5);
    third->attach(*Label_Date, 0, 2, 0, 1);
    third->attach(*Label_Time, 0, 2, 1, 2);

    Date.set_label("Date and Time");
    Date.set_label_align(Gtk::ALIGN_START);
    Date.add(*third);

    add(Name);
    add(OS);
    add(Date);
    show_all();
}

void Informations::updateTime()
{
    this->Label_Time->set_text ("\tTime                  : " + data.getHours());
}

void Informations::updateUpTime()
{
    this->Label_Uptime->set_text ("\tUptime             : " + data.getUpTime());
}

void Informations::updateDate()
{
    this->Label_Date->set_text ("\tDate                  : " + data.getDate());
}


Informations::~Informations()
{
    delete this->Label_MachineName;
    delete this->Label_UserName;
    delete this->Label_Uptime;
    delete this->first;
    delete this->Label_Version;
    delete this->Label_OS;
    delete this->second;
    delete this->Label_Date;
    delete this->Label_Time;
    delete this->third;

}
