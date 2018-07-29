/*
** client.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Mon May 23 20:19:49 2016 Maxime
** Last update Feb May 23 20:19:56 2016
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<sys/time.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		<sys/select.h>
#include		"my.h"
#include		"myirc_client.h"

void			set_my_fd(t_client *client)
{
  if (client->server.connected == 1)
    {
      FD_SET(FD[1], &(FD_READ));
      FD_SET(FD[1], &(FD_WRITE));
      client->fd.fd_max = FD[1] + 1;
    }
  FD_SET(0, &(FD_READ));
  FD_SET(1, &(FD_WRITE));
}

int			main()
{
  t_client		*client;
  struct timeval	time;

  client = NULL;
  init(&client);
  FD_SET(0, &(FD_READ));
  FD_SET(1, &(FD_WRITE));
  time.tv_sec = 0;
  time.tv_usec = 40;
  while (select(client->fd.fd_max, &(FD_READ),
		&(FD_WRITE), NULL, &time) != -1)
    {
      user_action(client);
      server_action(client);
      set_my_fd(client);
    }
  return (EXIT_SUCCESS);
}
