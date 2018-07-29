/*
** connect.c for client in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src/client
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Sun Jun 05 18:01:21 2016 Maxime
** Last update Jan Jun 5 18:01:42 2016
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		"myirc_client.h"

void			login(t_client *client, char **tab)
{
  dprintf(FD[1], "USER %s * %s :epitech\n\r", getenv("USER"), tab[1]);
  dprintf(FD[1], "NICK %s\n\r", getenv("USER"));
  dprintf(FD[1], "PASS default\n\r");
}

int			xconnect(t_client *client, char **tab)
{
  struct sockaddr_in	addr;

  if (!tab[0] && !tab[1])
    return (-1);
  if (client->server.connected == 1)
    {
      client->server.connected = 0;
      close(FD[1]);
    }
  addr.sin_family = AF_INET;
  if (tab[2])
    addr.sin_port = htons(atoi(tab[2]));
  else
    addr.sin_port = htons(6667);
  if ((FD[1] = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    return (-1);
  if (inet_pton(AF_INET, tab[1], &addr.sin_addr) <= 0)
    return (-1);
  if (connect(FD[1],
	      (struct sockaddr *)(&addr), sizeof(addr)) < 0)
    return (-1);
  login(client, tab);
  client->server.connected = 1;
  client->server.ip = strdup(tab[1]);
  return (0);
}
