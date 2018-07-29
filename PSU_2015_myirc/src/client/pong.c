/*
** pong.c for client in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src/client
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Sun Jun 05 18:02:34 2016 Maxime
** Last update Jan Jun 5 18:02:38 2016
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"myirc_client.h"

int		pong(t_client *client, char **tab)
{
  if (tab[0] && tab[1] && !tab[2])
    dprintf(FD[1], "PONG %s\n\r", tab[1]);
  else
    {
      printf("Error pong\n");
      return (-1);
    }
  return (0);
}
