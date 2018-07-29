/*
** main.c for SBMLparser in /home/gendro_v/Piscine/P1/SBMLparser
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Mon Jun 15 13:11:45 2015 Vincent Gendron
** Last update Sun Dec  6 22:07:33 2015 Vincent Gendron
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"list.h"
#include	"my.h"

char		**put_in_tab(char **tab, char *line)
{
  char		**new_tab;
  int		i;

  if (tab == NULL || tab[0] == NULL)
    {
      if ((tab = malloc(sizeof(char *) * 2)) == NULL)
	exit(EXIT_FAILURE);
      tab[0] = line;
      tab[1] = NULL;
      return (tab);
    }
  i = 0;
  while (tab && tab[i] != NULL)
    i = i + 1;
  if ((new_tab = malloc(sizeof(char *) * (i + 3))) == NULL)
    exit(EXIT_FAILURE);
  i = -1;
  while (tab[++i] != NULL)
    new_tab[i] = tab[i];
  free(tab);
  new_tab[i] = line;
  new_tab[i + 1] = NULL;
  return (new_tab);
}
