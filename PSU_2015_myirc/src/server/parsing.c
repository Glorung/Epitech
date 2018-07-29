/*
** parsing.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Mon May 23 22:53:33 2016 Maxime
** Last update May Jun 2 17:29:03 2016
*/

#include "myirc.h"

int		my_register_nick(int fd, t_parse *buf,
				 t_list **list, t_channel *chan)
{
  if (strcmp(buf->cmd, "NICK") == 0)
    {
      if (strlen(buf->arg1) == 0)
	return (need_more_param(find_by_id(*list, fd), "NICK"));
      if (existant_nick(find_by_id(*list, fd), *list, buf->arg1) == 1)
	return (1);
      if (find_by_id(*list, fd)->connected == 0)
	{
	  strcpy(find_by_id(*list, fd)->nick, buf->arg1);
	  find_by_id(*list, fd)->connected = 2;
	}
      else if (find_by_id(*list, fd)->connected == 1)
	{
	  find_by_id(*list, fd)->connected = 3;
          strcpy(find_by_id(*list, fd)->nick, buf->arg1);
	}
      else
	change_nick(fd, buf->arg1, *list, chan);
      return (0);
    }
  return (1);
}

int		analyze2(int fd, t_parse *buf, t_channel **chan, t_list **list)
{
  char 		tab[1024];
  t_list 	*winner;

  winner = find_by_id(*list, fd);
  if (strcasecmp(buf->cmd, "PART") == 0)
    {
      if (buf->arg1[0] == '\0')
	return (need_more_param(find_by_id(*list, fd), "PART"));
      if (existant_channel(*chan, fd, buf->arg1, *list) != -2)
	return (0);
      sprintf(tab, ":%s!~%s@%s PART %s\r\n",
	      find_by_id(*list, fd)->nick, winner->user, winner->ip, buf->arg1);
      write(fd, tab, strlen(tab));
      everyoneact(*chan, *list, buf->arg1);
      return (0);
    }
  else if (strcasecmp(buf->cmd, "QUIT") == 0)
    {
      sprintf(tab, ":%s!~%s@%s QUIT %s\r\n",
	      find_by_id(*list, fd)->nick, winner->user,
	      winner->ip, buf->comment);
      write(fd, tab, strlen(tab));
      return (1);
    }
  return (0);
}

int		analyze(int fd, t_parse *buf, t_channel **chan, t_list **list)
{
  if (strcasecmp(buf->cmd, "NICK") == 0)
      return (my_register_nick(fd, buf, list, *chan));
  else if (strcasecmp(buf->cmd, "JOIN") == 0)
    {
      if (buf->arg1[0] == '\0')
	need_more_param(find_by_id(*list, fd), "JOIN");
      else
	reply_join(fd, (*chan = add_client(*chan, buf->arg1, fd))
		   , *list, buf->arg1);
	return (0);
    }
  else if (strcasecmp(buf->cmd, "NAMES") == 0)
    {
      s_send(353, RPL_REPLYNAME(*chan, *list, buf->arg1),
	     find_by_id(*list, fd));
      s_send(366, ":End of /NAMES list.", find_by_id(*list, fd));
      return (0);
    }
  else if (strcasecmp(buf->cmd, "USERS") == 0)
    return (cmd_USERS(*list, fd));
  else if (strcasecmp(buf->cmd, "PRIVMSG") == 0)
    return (privmsg(fd, *chan, *list, buf));
  else
    return (analyze2(fd, buf, chan, list));
}

int		my_register(int fd, t_parse *buf,
			    t_list **list, t_channel *chan)
{
  if (strcmp(buf->cmd, "USER") == 0)
    {
      if (find_by_id(*list, fd)->connected == 1)
	return (s_send(462, "You may not reregister", find_by_id(*list, fd)));
      if (strlen(buf->arg3) == 0)
	return (need_more_param(find_by_id(*list, fd), "USER"));
      strcpy(find_by_id(*list, fd)->user, buf->arg1);
      strcpy(find_by_id(*list, fd)->ip, buf->arg3);
      if (find_by_id(*list, fd)->connected == 0)
	find_by_id(*list, fd)->connected = 1;
      else
	find_by_id(*list, fd)->connected = 3;
    }
  else if (my_register_nick(fd, buf, list, chan) == 0)
    return (0);
  else
    return (s_send(451, ":You have not registered", find_by_id(*list, fd)));
  return (0);
}

int		hodor(int fd, t_parse *buf, t_channel **chan, t_list **list)
{
  if (find_by_id(*list, fd)->connected != 3)
    {
      my_register(fd, buf, list, *chan);
      if (find_by_id(*list, fd)->connected == 3)
	{
	  s_send(001, "Welcome to my irc!", find_by_id(*list, fd));
	  s_send(375, "", find_by_id(*list, fd));
	  s_send(372, "Born to code !", find_by_id(*list, fd));
	  s_send(376, "", find_by_id(*list, fd));
	}
    }
  else
    return (analyze(fd, buf, chan, list));
  return (0);
}
