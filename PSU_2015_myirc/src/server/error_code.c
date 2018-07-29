/*
** error_code.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Wed Jun 01 02:13:50 2016 Maxime
** Last update May Jun 2 15:26:12 2016
*/

#include "myirc.h"

int		need_more_param(t_list *list, char *cmd)
{
  char		tab[200];

  strcpy(tab, cmd);
  strcat(tab, ":Not enough parameters");
  return (s_send(461, tab, list));
}

int		existant_nick(t_list *user, t_list *list, char *name)
{
  t_list	*tmp;
  char		tab[128];

  strcpy(tab, name);
  strcat(tab, ": :Nickname is already in use");
  tmp = list;
  while (tmp != NULL)
    {
      if (strcmp(tmp->nick, name) == 0)
	{
	  s_send(433, tab, user);
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		existant_channel(t_channel *chan, int fd,
				 char *name, t_list *list)
{
  int		i;
  char		tab[256];

  i = 0;
  while (chan != NULL)
    {
      if (strcmp(chan->name, name) == 0)
	{
	  while (i < 1024)
	    {
	      if (chan->fd_client[i] == fd)
		chan->fd_client[i] = 0;
	      i++;
	    }
	  return (-2);
	}
      chan = chan->next;
    }
  if (sprintf(tab, "%s :No such channel", name) < 0)
    exit(1);
  return (s_send(403, tab, find_by_id(list, fd)));
}
