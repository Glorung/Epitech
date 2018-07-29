/*
** list.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Tue May 17 16:17:16 2016 Maxime
** Last update May Jun 2 18:08:54 2016
*/

#include "myirc.h"

int		size_list(t_list *head)
{
  int		i;

  i = 0;
  while (head != NULL)
    {
      i++;
      head = head->next;
    }
  return (i);
}

t_list		*get_last(t_list *head)
{
  t_list	*tmp;

  tmp = head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (tmp);
}

t_list		*add_list(t_list *list, int fd)
{
  t_list	*head;
  t_list	*tmp;

  head = list;
  if ((tmp = malloc(sizeof(t_list))) == NULL)
    exit(1);
  tmp->fd = fd;
  tmp->next = NULL;
  tmp->connected = 0;
  memset(tmp->ip, 0, 40);
  memset(tmp->user, 0, 128);
  memset(tmp->nick, 0, 128);
  if (list == NULL)
    return (tmp);
  while (list->next != NULL)
    list = list->next;
  list->next = tmp;
  return (head);
}

t_list		*rm_list(t_list *list, int fd)
{
  t_list	*head[2];

  head[0] = list;
  if (list == NULL)
    return (NULL);
  if (list->fd == fd)
    {
      head[1] = list->next;
      close(fd);
      free(list);
      return (head[1]);
    }
  while (list != NULL && list->next != NULL)
    {
      head[1] = list;
      list = list->next;
      if (list->fd == fd)
	{
	  close(fd);
	  head[1]->next = list->next;
	  free(list);
	  return (head[0]);
	}
    }
  return (NULL);
}

t_list		*free_list(t_list *list)
{
  t_list	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
  return (NULL);
}
