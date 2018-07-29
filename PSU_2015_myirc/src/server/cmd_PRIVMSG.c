/*
** cmd_PRIVMSG.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Thu Jun 02 14:29:46 2016 Maxime
** Last update Jan Jun 5 15:30:06 2016
*/

#include "myirc.h"

int		privmsg_user(int fd, t_list *list, t_parse *buf)
{
  t_list	*winner;
  char		tab[1024];

  winner = list;
  while (winner != NULL)
    {
      if (strcmp(winner->nick, buf->arg1) == 0)
	break;
      winner = winner->next;
    }
  if (winner == NULL)
    return (0);
  if (sprintf(tab, ":%s!~%s@%s PRIVMSG %s %s\r\n",
	      find_by_id(list, fd)->nick, find_by_id(list, fd)->user,
	      find_by_id(list, fd)->ip, buf->arg1, buf->comment) < 0)
    return (-2);
  return (write(winner->fd, tab, strlen(tab)));
}

int		privmsg(int fd, t_channel *chan, t_list *list, t_parse *buf)
{
  int		i;
  t_channel	*tmp;
  t_list 	*winner;
  char 		tab[1024];

  i = 0;
  if ((tmp = find_by_name(chan, buf->arg1)) == NULL)
    return (privmsg_user(fd, list, buf));
  while (i < 1024)
    {
      if (tmp->fd_client[i] != 0 && tmp->fd_client[i] != fd)
	{
	  if ((winner = find_by_id(list, tmp->fd_client[i])) == NULL)
	    return (-2);
	  if (sprintf(tab, ":%s!~%s@%s PRIVMSG %s %s\r\n",
		  find_by_id(list, fd)->nick, winner->user,
		  winner->ip, buf->arg1, buf->comment) < 0)
	    return (-2);
	  write(tmp->fd_client[i], tab, strlen(tab));
	}
      i++;
    }
  return (0);
}
