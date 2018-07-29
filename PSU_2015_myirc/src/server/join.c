/*
** join.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Tue May 24 17:53:09 2016 Maxime
** Last update Jan Jun 5 13:56:04 2016
*/

#include "myirc.h"

char		*all_name(t_channel *chan, t_list *list)
{
  int		i;
  int		flags;
  char		buffer[4096];

  i = 0;
  flags = 0;
  memset(buffer, 0, 4096);
  if (chan == NULL)
    exit(1);
  while (i < 1024)
    {
      if (chan->fd_client[i] != 0)
	{
	  if (flags == 0)
	    flags = 1;
	  else
	    strcat(buffer, " ");
	  if (find_by_id(list, chan->fd_client[i]) != NULL)
	    strcat(buffer, find_by_id(list, chan->fd_client[i])->nick);
	}
      i++;
    }
  return (strdup(buffer));
}

char		*RPL_REPLYNAME(t_channel *chan, t_list *list, char *name)
{
  char		buffer[8192];
  char		*allname;

  allname = all_name(chan, list);
  if (0 > sprintf(buffer, "= %s :%s", name, allname))
    exit(1);
  free(allname);
  return (strdup(buffer));
}

void		reply_join(int fd, t_channel *chan, t_list *list, char *name)
{
  char		tab[1024];
  t_list	*winner;

  winner = find_by_id(list, fd);
  if (0 > sprintf(tab, ":%s!~%s@%s JOIN %s\r\n", winner->nick, winner->user,
		  winner->ip, name))
    exit(1);
  write(fd, tab, strlen(tab));
  if (0 > sprintf(tab, "%s: A channel from myirc@epitech.eu", name))
    exit(1);
  s_send(332, tab, find_by_id(list, fd));
  everyoneact(chan, list, name);
}

void		everyoneact(t_channel *chan, t_list *list, char *name)
{
  int		i;
  char		*lol;
  t_channel	*tmp;
  char		tab[1024];

  i = 0;
  if ((tmp = find_by_name(chan, name)) != NULL)
    {
      while (i < 1024)
	{
	  if (tmp->fd_client[i] != 0)
	    {
	      lol = RPL_REPLYNAME(tmp, list, name);
	      s_send(353, lol, find_by_id(list, tmp->fd_client[i]));
	      if (0 > sprintf(tab, "%s :End of /NAMES list.", name))
		exit(1);
	      free(lol);
	      s_send(366, tab, find_by_id(list, tmp->fd_client[i]));
	    }
	  i++;
	}
    }
}
