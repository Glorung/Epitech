/*
** ncurses.c for ncurses in /home/glorung/Project/PSU_2015_lemipc/srcs/ncurses
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar 23 18:03:52 2016 Glorung
** Last update Wed Mar 23 18:59:19 2016 Glorung
*/

#include	<string.h>
#include	<unistd.h>
#include	<ncurses.h>
#include	"display.h"

void		ncurses_error(char *msg)
{
  int		begin;

  begin = strlen(msg);
  begin = ((COLS - begin) / 2);
  if (begin < 0)
    begin = 0;
  move(0, 0);
  move(begin, LINES / 2);
  printw("%s\n", msg);
  refresh();
}

void		ncurses_init()
{
  initscr();
  raw();
  noecho();
}

int		ncurses_check(int x, int y)
{
  if (x > LINES || y > COLS)
    {
      ncurses_clear_screen();
      ncurses_error("You need a bigger terminal to see the fight\n");
      return (0);
    }
  return (1);
}

void		ncurses_end()
{
  echo();
  endwin();
}
