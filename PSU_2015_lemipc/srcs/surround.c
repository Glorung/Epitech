/*
** surround.c for lemipc in /home/rebour_j/sysunix/PSU_2015_lemipc
** 
** Made by Jonathan Rebourt
** Login   <rebour_j@epitech.net>
** 
** Started on  Tue Mar 22 10:59:29 2016 Jonathan Rebourt
** Last update Sun Mar 27 22:35:56 2016 Glorung
*/

#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<string.h>
#include	"lemipc.h"

extern key_t	g_key;

int		check_surrounding(struct s_case *ptr, int xdiff, int ydiff)
{
  if (ptr->x + xdiff >= 0 && ptr->x + xdiff < BOARD_SIZE)
    ptr += xdiff;
  else
    return (0);
  if (ptr->y + ydiff >= 0 && ptr->y + ydiff < BOARD_SIZE)
    ptr += ydiff * BOARD_SIZE;
  else
    return (0);
  return (ptr->nteam);
}

int		is_surrounded_by_team(int tab[8])
{
  int		i;
  int		j;

  j = -1;
  while (++j < 8)
    {
      i = -1;
      while (++i < 8)
	{
	  if (i != j && tab[j] && tab[i] && tab[i] == tab[j])
	    return (1);
	}
    }
  return (0);
}

int		is_surrounded(void *ptr)
{
  struct s_case	*player_ptr;
  int		tab[8];
  int		i;
  int		j;
  int		n;
  int		ret;

  j = -2;
  n = -1;
  player_ptr = (struct s_case *)ptr;
  memset((void *)&tab[0], 0, sizeof(int) * 8);
  while (++j < 2)
    {
      i = -2;
      while (++i < 2)
	{
	  if ((i || j) && (ret = check_surrounding(player_ptr, j, i)))
	    tab[++n] = ret;
  	}
    }
  return (is_surrounded_by_team(tab));
}
