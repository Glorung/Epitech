/*
** bot.c for lemipc in /home/rebour_j/sysunix/PSU_2015_lemipc
** 
** Made by Jonathan Rebourt
** Login   <rebour_j@epitech.net>
** 
** Started on  Sun Mar 27 13:02:28 2016 Jonathan Rebourt
** Last update Sun Mar 27 22:33:27 2016 Glorung
*/

#include	<stdlib.h>
#include	"lemipc.h"

void		*move_up(struct s_case *ptr)
{
  struct s_case	*tmp;

  if (!ptr)
    return (NULL);
  if (ptr->y > 0)
    {
      tmp = ptr - BOARD_SIZE;
      if (tmp->nteam)
	return (ptr);
      tmp->nteam = ptr->nteam;
      ptr->nteam = 0;
      return (tmp);
    }
  return (ptr);
}

void		*move_down(struct s_case *ptr)
{
  struct s_case	*tmp;

  if (!ptr)
    return (NULL);
  if (ptr->y < BOARD_SIZE - 1)
    {
      tmp = ptr + BOARD_SIZE;
      if (tmp->nteam)
	return (ptr);
      tmp->nteam = ptr->nteam;
      ptr->nteam = 0;
      return (tmp);
    }
  return (ptr);
}

void		*move_left(struct s_case *ptr)
{
  struct s_case	*tmp;

  if (!ptr)
    return (NULL);
  if (ptr->x > 0)
    {
      tmp = ptr - 1;
      if (tmp->nteam)
	return (ptr);
      tmp->nteam = ptr->nteam;
      ptr->nteam = 0;
      return (tmp);
    }
  return (ptr);
}

void		*move_right(struct s_case *ptr)
{
  struct s_case	*tmp;

  if (!ptr)
    return (ptr);
  if (ptr->x < BOARD_SIZE - 1)
    {
      tmp = ptr + 1;
      if (tmp->nteam)
	return (ptr);
      tmp->nteam = ptr->nteam;
      ptr->nteam = 0;
      return (tmp);
    }
  return (ptr);
}

void		*move_player(void *arena_ptr, void *player_ptr)
{
  move_t	move_ptrs[4];
  void		*tmp;

  move_ptrs[0] = &move_up;
  move_ptrs[1] = &move_down;
  move_ptrs[2] = &move_left;
  move_ptrs[3] = &move_right;
  if (!is_last(arena_ptr, player_ptr))
    {
      tmp = move_ptrs[get_move(arena_ptr, player_ptr)](player_ptr);
      if (tmp == player_ptr)
	return (move_ptrs[get_empty_spot(player_ptr)](player_ptr));
      return (tmp);
    }
  return (move_ptrs[rand() % 4](player_ptr));
}
