/*
** players.c for players in /home/glorung/Project/PSU_2015_lemipc/srcs
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Thu Mar 24 08:41:34 2016 Glorung
** Last update Sun Mar 27 22:35:18 2016 Glorung
*/

#include		<stdlib.h>
#include		"list.h"
#include		"display.h"
#include		"lemipc.h"

t_list			*players_list_update(void *arena_ptr, t_list *list)
{
  t_list		*tmp;

  tmp = list;
  if (((t_team *)tmp->this)->name == ((struct s_case *)arena_ptr)->nteam)
    {
      ((t_team *)tmp->this)->nbr += 1;
      return (list);
    }
  tmp = tmp->next;
  while (tmp != list)
    {
      if (((t_team *)tmp->this)->name == ((struct s_case *)arena_ptr)->nteam)
	{
	  ((t_team *)tmp->this)->nbr += 1;
	  return (list);
	}
      tmp = tmp->next;
    }
  return (list);
}

int			players_check_inlist(t_list *list, void *arena_ptr)
{
  t_list		*tmp;

  if (list == NULL)
    return (0);
  tmp = list;
  if (((t_team *)tmp->this)->name == ((struct s_case *)arena_ptr)->nteam)
    return (1);
  tmp = tmp->next;
  while (tmp != list)
    {
      if (((t_team *)tmp->this)->name == ((struct s_case *)arena_ptr)->nteam)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

t_list			*players_list_init(void *arena_ptr, t_list *list)
{
  struct s_case		*tmp;
  int			pos[2];
  t_team		*team;

  list = NULL;
  pos[0] = -1;
  while (++pos[0] < BOARD_SIZE)
    {
      pos[1] = -1;
      while (++(pos[1]) < BOARD_SIZE)
	{
	  tmp = (struct s_case *)(arena_ptr
				  + (LINE_SIZE * pos[0]) + (TILE_SIZE * pos[1]));
	  if (tmp->nteam > 0 && players_check_inlist(list, tmp))
	    players_list_update(tmp, list);
	  else if (tmp->nteam > 0 && !players_check_inlist(list, tmp))
	    {
	      team = malloc(sizeof(t_team));
	      team->name = tmp->nteam;
	      team->nbr = 1;
	      list_push_back(&list, team);
	    }
	}
    }
  return (list);
}

t_list			*players_get_list(void *arena_ptr)
{
  t_list		*list;

  list = players_list_init(arena_ptr, NULL);
  list = list_classify(&list);
  return (list);
}
