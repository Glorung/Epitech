/*
** nick.c for client in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src/client
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Sun Jun 05 18:02:13 2016 Maxime
** Last update Jan Jun 5 18:02:15 2016
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"myirc_client.h"

int		xnick(t_client *client, char **tab)
{
  if (check_serv(client) == -1)
    return (-1);
  if (tab[1] && !tab[2])
    dprintf(FD[1], "NICK %s\n\r", tab[1]);
  else
    {
      printf("Usage: /nick NAME\n");
      return (-1);
    }
  return (0);
}
