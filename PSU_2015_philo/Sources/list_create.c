/*
** list_create.c for list in /home/glorung/Project/PSU_2015_philo/Sources
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Tue Mar  8 20:30:25 2016 Glorung
** Last update Thu Mar 10 16:28:49 2016 Glorung
*/

#include <stdlib.h>
#include "list.h"

static t_list	*list_init_new_elem(void *data)
{
  t_list	*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem == NULL)
    exit(EXIT_FAILURE);
  new_elem->this = data;
  return (new_elem);
}

static void	list_new_lonely_elem(t_list **list, void *data)
{
  t_list	*new_elem;

  new_elem = list_init_new_elem(data);
  new_elem->next = new_elem;
  new_elem->prev = new_elem;
  *list = new_elem;
}

void		list_push_front(t_list **list, void *data)
{
  t_list	*new_elem;

  if (*list == NULL)
    {
      list_new_lonely_elem(list, data);
      return ;
    }
  new_elem = list_init_new_elem(data);
  new_elem->next = *list;
  new_elem->prev = (*list)->prev;
  (list_get_last_elem(*list))->next = new_elem;
  (*list)->prev = new_elem;
  *list = new_elem;
}

void		list_push_back(t_list **list, void *data)
{
  t_list	*new_elem;
  t_list	*i;

  if (*list == NULL)
    {
      list_new_lonely_elem(list, data);
      return ;
    }
  new_elem = list_init_new_elem(data);
  i = list_get_last_elem(*list);
  i->next = new_elem;
  new_elem->next = *list;
  new_elem->prev = i;
  (*list)->prev = new_elem;
}
