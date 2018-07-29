/*
** error.c for client in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src/client
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Sun Jun 05 18:01:27 2016 Maxime
** Last update Jan Jun 5 18:01:41 2016
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"myirc_client.h"

int		check_serv(t_client *client)
{
  if (client->server.connected != 1)
    return (-1);
  return (1);
}

void		exit_msg(int nbr, char *msg)
{
  dprintf(2, "%s\n", msg);
  exit(nbr);
}
