/*
** list_remove.c for list_remove in /home/glorung/Project/PSU_2015_philo/Sources
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar  9 18:25:05 2016 Glorung
** Last update Thu Mar 24 08:35:43 2016 Glorung
*/

#include <stdlib.h>
#include "list.h"

static void	list_remove_this(t_list *list_elem)
{
  free(list_elem->this);
  free(list_elem);
}

void		list_remove_elem(t_list **list_elem, t_list *this)
{
  if (*list_elem == NULL)
    return ;
  if (this->next == this)
    {
      list_remove_this(this);
      *list_elem = NULL;
      return ;
    }
  if (this == *list_elem)
    *list_elem = this->next;
  this->prev->next = this->next;
  this->next->prev = this->prev;
  list_remove_this(this);
}

void		list_remove_all(t_list **list)
{
  t_list	*this;

  while (*list != NULL)
    {
      this = *list;
      list_remove_elem(list, this);
    }
}
