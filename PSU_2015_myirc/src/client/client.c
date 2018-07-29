/*
** client.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Mon May 23 20:19:49 2016 Maxime
** Last update Jan Jun 5 18:01:43 2016
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<sys/time.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		<sys/select.h>
#include		<curses.h>
#include		<ncurses.h>
#include		"my.h"
#include		"myirc_client.h"
#include		"ncurses_genshlib.h"

int			use_cmd(t_client *client)
{
  int			i;
  char			**tab;

  i = 0;
  tab = xmalloc(sizeof(char *) * 2048);
  tab[0] = strtok(strdup(client->client_input), " ");
  if (tab[0] == NULL)
    return (0);
  while ((tab[++i] = strtok(NULL, " ")) != NULL);
  i = -1;
  while (client->user_cmd[++i] != NULL)
    if (strcmp(tab[0], client->user_cmd[i]) == 0)
      return ((*(client->user_fct[i]))(client, tab));
  if (client->server.connected == 1 && FD_ISSET(FD[1], &(FD_WRITE)))
    {
      i = 0;
      while (tab[i + 1] != NULL)
	dprintf(FD[1], "%s ", tab[i++]);
      dprintf(FD[1], "%s\n\r", tab[i]);
    }
  return (0);
}

void			user_action(t_client *client)
{
  int			i;

  if (FD_ISSET(0, &(FD_READ)))
    {
      client->client_input = xmalloc(4096);
      if ((i = read(0, client->client_input, 4096)) > 0)
	{
	  client->client_input[i - 1] = '\0';
	  if (client->client_input[0] != '\0')
	    {
	      client->client_input = epur_str(client->client_input);
	      if (use_cmd(client) == -1)
		printf("Error with cmd\n");
	    }
	}
      free(client->client_input);
    }
}
