#include		"Graph.hpp"
#include		<iostream>

Graph::Graph(int h, int w) : Gtk::DrawingArea()
{
  this->actual_point = 0;
  this->width = h;
  this->height = w;
}

Graph::~Graph()
{}

void			Graph::addPoint(unsigned int i)
{
  if (actual_point >= (height / 4))
    {
      this->points.pop_front();
      this->points.push_back(i);
      return ;
    }
  this->points.push_back(i);
  actual_point = actual_point + 1;
}

void			Graph::reset()
{
  this->points.clear();
  this->actual_point = 0;
}

void Graph::draw_text(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Pango::FontDescription font;

  font.set_family("Monospace");
  font.set_weight((Pango::Weight)(100));
  auto layout = create_pango_layout("100");
  layout->set_font_description(font);
  cr->move_to(5, 0);
  layout->show_in_cairo_context(cr);
}

bool		Graph::on_draw(const Cairo::RefPtr<Cairo::Context>& idk)
{
  int		i;
  int		j;

  draw_text(idk);
  idk->set_source_rgb(0.0, 0.0, 0.0);
  idk->set_line_width(0.5);
  idk->rectangle(0, 0, height, width);
  i = 0;
  j = 0;
  while (j != 100)
    {
      idk->move_to(0, i);
      idk->line_to(8, i);
      j = j + 10;
      i = (height / 100 * j);
    }
  i = 0;
  j = 0;
  while (j != 100)
    {
      idk->move_to(0, i);
      idk->line_to(5, i);
      j = j + 2;
      i = (height / 100 * j);
    }
  idk->stroke();
  idk->set_line_width(2);
  std::list<unsigned int>::iterator it = this->points.begin();
  idk->set_source_rgb(0.8, 0.0, 0.0);
  idk->move_to(0, width);
  i = 0;
  while (it != this->points.end())
    {
      if (*it != 0)
	{
	  idk->line_to(i, width - (width / 100  * *it));
	}
      it++;
      i = i + 4;
    }
  idk->stroke();
  return true;
}
