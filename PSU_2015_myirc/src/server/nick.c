/*
** nick.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epi2ech.net>
**
** Started on  Tue May 24 17:42:54 2016 Maxime
** Last update May Jun 2 17:18:01 2016
*/

#include "myirc.h"

t_channel	*find_chan_by_id(int fd, t_channel *chan)
{
  int		i;

  while (chan != NULL)
    {
      i = 0;
      while (i < 1024)
	{
	  if (chan->fd_client[i] == fd)
	    return (chan);
	  i++;
	}
      chan = chan->next;
    }
  return (NULL);
}

void		change_nick(int fd, char *buffer, t_list *list, t_channel *chan)
{
  t_list	*tmp;
  char		tab[1024];

  tmp = find_by_id(list, fd);
  if (tmp != NULL)
    {
      if (0 > sprintf(tab, ":%s!~%s@%s NICK :%s\r\n", tmp->nick, tmp->user,
		      tmp->ip, buffer))
	exit(1);
      strcpy(tmp->nick, buffer);
      write(fd, tab, strlen(tab));
      everyoneact(chan, list, find_chan_by_id(fd, chan)->name);
    }
}
