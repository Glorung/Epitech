/*
** leave.c for client in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src/client
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Sun Jun 05 18:01:48 2016 Maxime
** Last update Jan Jun 5 18:01:51 2016
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<curses.h>
#include	<ncurses.h>
#include	"myirc_client.h"

int		xquit(t_client *client, char **tab)
{
  if (client->server.connected == 1)
    {
      close(FD[1]);
      FD[1] = -1;
    }
  exit(0);
  tab = tab;
  return (0);
}
