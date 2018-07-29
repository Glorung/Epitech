/*
** generic.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Tue May 24 17:45:11 2016 Maxime
** Last update Jan Jun 5 14:36:37 2016
*/

#include <ifaddrs.h>
#include "myirc.h"

char		*ip_addr()
{
  char			ip[32];
  struct sockaddr_in    *s_sock2;
  struct ifaddrs        *s_ip;

  if (getifaddrs(&s_ip) == -1)
    return (NULL);
  while (s_ip->ifa_addr && s_ip->ifa_addr->sa_family != AF_INET)
    s_ip = s_ip->ifa_next;
  s_sock2 = (struct sockaddr_in *)(s_ip->ifa_next->ifa_addr);
  sprintf(ip, "%d.%d.%d.%d",
	  s_sock2->sin_addr.s_addr & 0x000000FF,
	  s_sock2->sin_addr.s_addr>>8 & 0x0000FF,
	  s_sock2->sin_addr.s_addr>>16 & 0x00FF,
          s_sock2->sin_addr.s_addr>>24);
  return (strdup(ip));
}

t_list		*find_by_id(t_list *list, int fd)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL && tmp->fd != fd)
    tmp = tmp->next;
  return (tmp);
}

t_channel		*find_by_name(t_channel *list, char *name)
{
  t_channel	*tmp;

  tmp = list;
  while (tmp != NULL && strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  return (tmp);
}

int		s_send(int reply_code, char *text, t_list *list)
{
  char		buffer[4096];
  char		*ip;

  ip = ip_addr();
  if (list != NULL && list->nick[0] != '\0')
    {
      if (0 > sprintf(buffer, ":%s %d %s %s\r\n", ip,
		      reply_code, list->nick, text))
	exit(1);
    }
  else if (list != NULL)
    {
      if (0 > sprintf(buffer, ":%s %d * %s\r\n", ip,
		      reply_code, text))
	exit(1);
    }
  free(ip);
  if (list != NULL)
    return (write(list->fd, buffer, strlen(buffer)));
  else
    return (0);
}

t_list		*rm_it(t_list *list, int fd, t_channel *chan)
{
  t_channel	*lol;
  int		i;

  while ((lol = find_chan_by_id(fd, chan)) != NULL)
    {
      i = 0;
      while (i < 1024)
	{
	  if (lol->fd_client[i] == fd)
	    lol->fd_client[i] = 0;
      	  i++;
      	}
    }
  return (rm_list(list, fd));
}
