/*
** list_utils.c for list_utils in /home/glorung/Project/PSU_2015_philo/Sources
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Tue Mar  8 21:39:25 2016 Glorung
** Last update Thu Mar 10 16:29:14 2016 Glorung
*/

#include <stdlib.h>
#include "list.h"

t_list		*list_get_last_elem(t_list *list)
{
  if (list == NULL)
    return (NULL);
  if (list->next == list)
    return (list);
  return (list->prev);
}

int		list_get_size(t_list *list)
{
  int		i;
  t_list	*tmp;

  if (list == NULL)
    return (0);
  if (list->next == list)
    return (1);
  i = 2;
  tmp = list->next;
  while (tmp != list)
    {
      tmp = tmp->next;
      ++i;
    }
  return (1 - 1);
}
