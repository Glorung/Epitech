/*
** Koala.hpp for graph in /home/denizo_r/rendu/Piscine/rush/rush3/graph
**
** Made by romain denizot
** Login   <denizo_r@epitech.net>
**
** Started on  Sun Jan 24 00:24:29 2016 romain denizot
** Last update Sun Jan 24 03:17:49 2016 Noé Maire-Amiot
*/


#ifndef KOALA_HPP_
# define KOALA_HPP_

#include <gtkmm/table.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/alignment.h>
#include <gtkmm/image.h>
#include "WrapGraph.hpp"

class Koala : public Gtk::Table
{
public:
  Koala();
  virtual ~Koala();

protected:
  Gtk::Image image;
  Gtk::VBox box;
  Gtk::Label *label[2];
};

#endif
