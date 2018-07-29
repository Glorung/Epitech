/*
** ncurses_draw.c for ncurses in /home/glorung/Project/PSU_2015_lemipc/srcs/ncurses
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar 23 18:05:39 2016 Glorung
** Last update Sun Mar 27 18:20:27 2016 Jonathan Rebourt
*/

#include	<ncurses.h>

void		ncurses_clear_screen()
{
  int		x;
  int		y;

  x = -1;
  while (++x != LINES + 1)
    {
      y = -1;
      while (++y != COLS + 1)
	{
	  move(x, y);
	  printw(" ");
	}
    }
}

void		ncurses_draw_square(int begin_x, int begin_y,
				    int end_x, int end_y)
{
  int		x;
  int		y;

  x = begin_x - 1;
  while (++x != end_x + 1)
    {
      y = begin_y - 1;
      while (++y != end_y + 1)
	{
	  move(x, y);
	  if (x == begin_x || x == end_x)
	    printw("#");
	  else if (y == 0 || y == end_y)
	    printw("#");
	}
    }
}
