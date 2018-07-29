/*
** main.c for makefile_src in /home/glorung/Project/my_move/makefile_scr
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Mon Apr  4 13:12:51 2016 Glorung
** Last update Mon Apr  4 19:43:17 2016 Glorung
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"make_src.h"

void		display_make(char **tab)
{
  int		i;

  i = 1;
  printf("%s", UP_BEGIN);
  while (++i != 50)
    printf("%s", UP);
  printf("%s\n", UP_END);
  i = 1;
  while (tab[++i])
    printf("%s %10s %-31s %s %s\n", SIDE, tab[1], tab[i], DONE, SIDE);
  i = 1;
  printf("%s", DOWN_BEGIN);
  while (++i != 50)
    printf("%s", DOWN);
  printf("%s\n", DOWN_END);
}

int		main(int ac, char **av)
{
  if (ac > 2)
    display_make(av);
  return (EXIT_SUCCESS);
}
