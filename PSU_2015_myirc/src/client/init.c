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
#include		<curses.h>
#include		<ncurses.h>
#include		"myirc_client.h"
#include		"my.h"

void			init_channel(t_channel *channel)
{
  channel->name = NULL;
}

void			init_server(t_server *server)
{
  server->connected = 0;
  server->ip = NULL;
  server->port = -1;
  init_channel(&(server->channel[0]));
}

void			init_client(t_client **client)
{
  t_client		*new_client;

  new_client = xmalloc(sizeof(t_client));
  init_server(&(new_client->server));
  init_cmd(new_client);
  init_serv_cmd(new_client);
  FD_ZERO(&(new_client->fd.fd_read));
  FD_ZERO(&(new_client->fd.fd_write));
  new_client->fd.fd_max = 1;
  *client = new_client;
}

void			init(t_client **client)
{
  printf("Hello, please enter server ip using :/server IP\n");
  init_client(client);
}
