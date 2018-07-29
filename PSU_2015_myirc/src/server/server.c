/*
** server.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Tue May 17 17:11:39 2016 Maxime
** Last update Jan Jun 5 15:36:05 2016
*/

#include "myirc.h"

void			FD_SET_ALL(t_list *list, fd_set *fds)
{
  int			i;

  FD_ZERO(fds);
  i = size_list(list);
  while (i > 0)
    {
      i--;
      FD_SET(list->fd, fds);
      list = list->next;
    }
}

int		count_char(char *str, char c)
{
  int		j;
  int		i;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == c)
	j++;
      i++;
    }
  return (j);
}

t_list		*try_to_read2(t_list **list, t_channel **chan,
			      t_list *head, char *buffer)
{
  t_parse	*buf;
  char		*tmp;
  int		size;

  size = read((*list)->fd, buffer, 4999);
  if (size > 0)
    {
      buffer[size] = '\0';
      if (strstr(buffer, "CAP LS") != NULL)
	memmove(buffer, (buffer + 8), size - 8);
      if (count_char(buffer, '\n') > 1)
	{
	  if ((tmp = rindex(buffer, '\r')) != NULL)
	    *tmp = '\0';
	  buf = parse_it(strstr(buffer, "\n") + 1, size);
	  hodor((*list)->fd, buf, chan, &head);
	}
      if ((buf = parse_it(buffer, size)) != NULL)
	if (hodor((*list)->fd, buf, chan, &head) == 1)
	  *list = rm_it(*list, (*list)->fd, *chan);
      free(buf);
      return (head);
    }
  else
    return ((*list = rm_it(*list, (*list)->fd, *chan)));
}

t_list		*try_to_read(t_list **list, fd_set *readf, t_channel **chan)
{
  t_list	*head;
  char		buffer[5000];

  head = *list;
  while (*list != NULL)
    {
      if (FD_ISSET((*list)->fd, readf))
	head = try_to_read2(list, chan, head, buffer);
      if (*list == NULL)
	return (NULL);
      *list = (*list)->next;
    }
  return (head);
}

int			server(int port)
{
  t_channel		*chan;
  fd_set		readf;
  t_list		*fds;
  struct timeval	tv;

  fds = NULL;
  chan = NULL;
  fds = add_list(fds, my_socket(port));
  while (1)
    {
      tv.tv_usec = 100;
      tv.tv_sec = 0;
      FD_SET_ALL(fds, &readf);
      if (select(fd_max(fds) + 1, &readf, NULL, NULL, &tv) == -1)
	exit(1);
      if (FD_ISSET(fds->fd, &readf))
	fds = add_list(fds, accept(fds->fd, NULL, NULL));
      fds->next = try_to_read(&fds->next, &readf, &chan);
    }
  close(fds->fd);
  return (0);
}
