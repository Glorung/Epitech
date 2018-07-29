#ifndef			GRAPH_HPP
#define			GRAPH_HPP

#include		<gtkmm/drawingarea.h>
#include		"DataCPU.hpp"

class			Graph :	public Gtk::DrawingArea
{
public:
  Graph(int, int);
  virtual		~Graph();
  void			reset();
  void			addPoint(unsigned int i);
  bool on_draw(const Cairo::RefPtr<Cairo::Context>&) override;
  void draw_text(const Cairo::RefPtr<Cairo::Context>&);
  std::list<unsigned int>	points;
  int				actual_point;
  int				height;
  int				width;
};

#endif
