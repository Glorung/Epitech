#include "Koala.hpp"

Koala::Koala() : Gtk::Table(1,2)
{
  image.set("./img/rush3.gif");
  box.pack_start(image);
  attach(box,0,1,0,1);
  label[0] = new Gtk::Label("\tMade by :\n\t\tmaire-_n\n\t\tparria_m\n\t\tdenizo_r\n\t\tgendro_v");
  label[0]->set_alignment(0,0.5);
  attach(*label[0],0,1,1,2);
}

Koala::~Koala()
{
}
