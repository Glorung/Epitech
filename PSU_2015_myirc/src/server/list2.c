/*
** list2.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Mon May 23 19:54:21 2016 Maxime
** Last update Feb May 23 20:12:22 2016
*/

#include "myirc.h"

int		fd_max(t_list *list)
{
  int		i;

  i = 0;
  while (list != NULL)
    {
      if (list->fd > i)
	i = list->fd;
      list = list->next;
    }
  return (i);
}

t_list		*get_list_at(t_list *list, int index)
{
  if (index > size_list(list))
    return (NULL);
  while (index != 0)
    list = list->next;
  return (list);
}
