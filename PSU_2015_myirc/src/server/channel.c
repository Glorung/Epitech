/*
** channel.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Mon May 23 22:30:42 2016 Maxime
** Last update May Jun 2 13:17:36 2016
*/

#include "myirc.h"

int				size_channel(t_channel *chan)
{
  int				i;

  i = 0;
  while (chan != NULL)
    {
      chan = chan->next;
      i++;
    }
  return (i);
}

t_channel			*new_channel(t_channel *channel, char *name)
{
  t_channel			*head;
  t_channel			*elem;

  head = channel;
  if ((elem = malloc(sizeof(t_channel))) == NULL)
    exit(1);
  memset(elem->fd_client, 0, 1024 * sizeof(int));
  strcpy(elem->name, name);
  elem->next = NULL;
  if (channel == NULL)
    return (elem);
  while (channel->next != NULL)
    channel = channel->next;
  channel->next = elem;
  return (head);
}

t_channel			*add_client(t_channel *list, char *name, int fd)
{
  int				i;
  t_channel			*head;

  head = list;
  i = 0;
  while (list != NULL && strcmp(name, (list)->name) != 0)
    list = (list)->next;
  if (list == NULL)
    return (add_client(new_channel(head, name), name, fd));
  while (i < 1024 && list->fd_client[i] != 0)
    i++;
  if (i >= 1024)
    exit(1);
  (list)->fd_client[i] = fd;
  return (head);
}

t_channel			*remove_client(t_channel *list,
					       char *name, int fd)
{
  int				i;
  t_channel			*head;

  head = list;
  i = 0;
  while (list != NULL && strcmp(name, list->name) != 0)
    list = list->next;
  if (list != NULL)
    {
      while (i < 1024)
	{
	  if (list->fd_client[i] == fd)
	    {
	      list->fd_client[i] = 0;
	      return (head);
	    }
	  i++;
	}
    }
  return (head);
}

int				*client_from(t_channel *list, char *name)
{
  while (list != NULL && strcmp(name, list->name) != 0)
    list = list->next;
  if (list == NULL)
    return (NULL);
  else
    return (list->fd_client);
}
