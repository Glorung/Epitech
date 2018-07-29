/*
** display.c for display in /home/glorung/Project/PSU_2015_lemipc/srcs
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Fri Mar 18 15:50:58 2016 Glorung
** Last update Sun Mar 27 22:26:49 2016 Glorung
*/

#include		<ncurses.h>
#include		<unistd.h>
#include		"list.h"
#include		"display.h"
#include		"lemipc.h"

void			display_players_onboard(void *arena_ptr)
{
  struct s_case	*	tmp;
  int			pos[2];

  pos[0] = -1;
  tmp = (struct s_case *)arena_ptr;
  while (++pos[0] < BOARD_SIZE)
    {
      pos[1] = -1;
      while (++pos[1] < BOARD_SIZE)
	{
	  tmp = (struct s_case *)(arena_ptr
				  + (LINE_SIZE * pos[0]) + (TILE_SIZE * pos[1]));
	  move(pos[1] + 1, pos[0] + 1);
	  if (tmp->nteam > 0)
	    addch(tmp->nteam + '@');
	  else
	    addch(' ');
	}
    }
}

void			display_players_onside_clear()
{
  int			line;

  line = 1;
  while (line <= BOARD_SIZE)
      mvprintw(line++, BOARD_SIZE + 3, "              ");
}

void			display_players_onside(void *arena_ptr)
{
  t_list *		list[2];
  int			line;

  display_players_onside_clear();
  if ((list[0] = players_get_list(arena_ptr)) == NULL)
    return ;
  line = 1;
  list[1] = list[0];
  mvprintw(line++, BOARD_SIZE + 3, "Team %c -> %03d",
	   ((t_team *)(list[0]->this))->name + '@',
	   ((t_team *)(list[0]->this))->nbr);
  while ((list[1] = list[1]->next) != list[0])
    {
      if (line < BOARD_SIZE)
	mvprintw(line++, BOARD_SIZE + 3, "Team %c -> %03d",
		 ((t_team *)(list[1]->this))->name + '@',
		 ((t_team *)(list[1]->this))->nbr);
      else
	{
	  mvprintw(line, BOARD_SIZE + 3, "...           ");
	  list_remove_all(&(list[1]));
	  return ;
	}
    }
  list_remove_all(&(list[1]));
}

void			display_game(void *arena_ptr)
{
  if (ncurses_check(BOARD_SIZE + 3, BOARD_SIZE + 19) != 0)
    {
      ncurses_draw_square(0, 0, BOARD_SIZE + 1, BOARD_SIZE + 1);
      ncurses_draw_square(0, BOARD_SIZE + 1,
			  BOARD_SIZE + 1, BOARD_SIZE + 17);
      display_players_onboard(arena_ptr);
      display_players_onside(arena_ptr);
      refresh();
    }
}

void			*display_routine(void *arena_ptr)
{
  int			begin;

  begin = 0;
  while (begin != 2)
    {
      if (!begin)
	begin = no_begin(arena_ptr);
      if (is_won(arena_ptr) && begin)
	begin++;
      display_game(arena_ptr);
      usleep(0);
    }
  return (NULL);
}
