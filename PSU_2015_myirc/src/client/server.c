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

int			server_decrypt(t_client *client)
{
  int			i;
  char			**tab;

  tab = xmalloc(sizeof(char *) * 2048);
  i = -1;
  while (++i != 2048)
    tab[i] = xmalloc(sizeof(char) * 4096);
  tab[0] = strtok(strdup(client->serv_input), " ");
  if (tab[0] == NULL)
    return (0);
  i = 0;
  while ((tab[++i] = strtok(NULL, " ")) != NULL);
  i = -1;
  if (strcmp(tab[0], "PING") == 0)
    return (pong(client, tab));
  if (tab[1])
    while (client->serv_cmd[++i] != NULL)
      if (strcmp(tab[1], client->serv_cmd[i]) == 0)
	return ((*(client->serv_fct[i]))(client, tab));
  i = -1;
  printf("- server - ");
  while (tab[++i] != NULL)
    printf("%s ", tab[i]);
  printf("\n");
  return (0);
}

void			server_action(t_client *client)
{
  int			size;

  if (client->server.connected == 1)
    {
      client->serv_input = xmalloc(4096);
      client->serv_input[0] = '\0';
      if (FD_ISSET(FD[1], &(FD_READ)))
	if ((size = read(FD[1], client->serv_input, 4096)) > 0)
	  {
	    client->serv_input[size - 2] = '\0';
	    if (server_decrypt(client) == -1)
	      printf("Error server action\n");
	  }
      free(client->serv_input);
    }
}
