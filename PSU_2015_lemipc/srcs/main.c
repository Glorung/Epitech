/*
** main.c for lemipc in /home/rebour_j/sysunix/PSU_2015_lemipc
** 
** Made by Jonathan Rebourt
** Login   <rebour_j@epitech.net>
** 
** Started on  Thu Mar 17 11:19:53 2016 Jonathan Rebourt
** Last update Sun Mar 27 22:51:31 2016 Glorung
*/

#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<signal.h>
#include	"lemipc.h"

key_t		g_key;

void		ctrlc()
{
}

int		usage(char *name)
{
  dprintf(2, "Usage: %s PATH TEAM_NUMBER\n", name);
  return (1);
}

int		main(int ac, char **av)
{
  int		nteam;

  if (ac != 3)
    return (usage(av[0]));
  signal(SIGINT, ctrlc);
  nteam = atoi(av[2]);
  if (nteam > 26 || nteam == 0)
    return (0);
  g_key = ftok(av[1], 42);
  lemipc(nteam);
  return (0);
}
