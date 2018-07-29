#include "MainWindows.hpp"

MainWindows::MainWindows() :  info(false, 10), quit(false)
{
    this->set_icon_from_file("./img/0052.gif");
    this->add(boiteV);
    onglets.set_can_focus(false);
    onglets.append_page(info, "Informations");
    onglets.append_page(cpu, "CPU");
    onglets.append_page(ram, "RAM");
    onglets.append_page(koala, "Koala");

    boiteV.pack_start(onglets);
    this->set_default_size(700, 800);
    this->set_size_request(700, 800);
    this->set_resizable(false);
    show_all();
}

bool MainWindows::wantQuit()
{
    return (this->quit);
}

void MainWindows::QUIT()
{
    this->quit = true;
}

void MainWindows::display(MainWindows &a)
{
    while (1)
    {
        sleep(1);
        //std::cout << "Coucou papa" << std::endl;
        a.info.updateTime();
        a.info.updateUpTime();
        a.info.updateDate();
        for (int i = 0; i < a.datacpu.getNbCore(); i++)
        dynamic_cast<WrapGraph *>(a.cpu.graph[i])->UpdateUsage();
        for (int i = 0; i < 2; i++)
        dynamic_cast<WrapRam *>(a.ram.graph[i])->UpdateRam();
        if (a.wantQuit() == true)
        break;
    }
}

MainWindows::~MainWindows()
{
}
