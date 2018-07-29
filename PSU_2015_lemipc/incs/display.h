/*
** display.h for display in /home/glorung/Project/PSU_2015_lemipc
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar 23 18:17:19 2016 Glorung
** Last update Thu Mar 24 13:57:52 2016 Glorung
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

# include "list.h"

typedef struct		s_team
{
  char			name;
  int			nbr;
}			t_team;

void		ncurses_error(char *);
void		ncurses_init();
int		ncurses_check(int x, int y);
void		ncurses_end();
void		ncurses_clear_screen();
void		ncurses_draw_square(int, int, int, int);

t_list *	players_get_list(void *);

#endif /* !DISPLAY_H_ */
