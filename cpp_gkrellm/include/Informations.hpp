#ifndef INFORMATIONS_HPP_
#define INFORMATIONS_HPP_

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include "Data.hpp"
#include <gtkmm/table.h>
#include <gtkmm/layout.h>
#include <gtkmm/alignment.h>
#include <string>

class Informations : public Gtk::VBox
{
public:
    Informations(bool, int);
    virtual ~Informations();
    void updateTime();
    void updateUpTime();
    void updateDate();

protected:
    Data data;
    Gtk::Frame Name;
    Gtk::Frame OS;
    Gtk::Frame Date;

    Gtk::Label *Label_MachineName;
    Gtk::Label *Label_UserName;
    Gtk::Label *Label_Uptime;
    Gtk::Table *first;

    Gtk::Label *Label_Version;
    Gtk::Label *Label_OS;
    Gtk::Table *second;

    Gtk::Label *Label_Date;
    Gtk::Label *Label_Time;
    Gtk::Table *third;
};

#endif
