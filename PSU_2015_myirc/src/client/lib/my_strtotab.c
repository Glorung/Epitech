/*
** mstr_tab.c for lib in /mnt/home/hiprog/Epitech/PSU_2014_minishell1/libc/my
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun May 17 21:33:11 2015 Vincent Gendron
** Last update Sun Dec  6 22:24:33 2015 Vincent Gendron
*/

#include	<stdlib.h>
#include	<string.h>
#include	"my.h"

char    **my_strtotab(char *str, char *separator)
{
  char	**tab;
  int	i;

  tab = my_malloc_tab(sizeof(*tab) * (2048));
  i = -1;
  while (++i != 2048)
    if ((tab[i] = malloc(sizeof(char) * 4096)) == NULL)
      exit(-1);
  i = 0;
  tab[0] = strtok(str, separator);
  while ((tab[++i] = strtok(NULL, separator)) != NULL);
  tab[i] = NULL;
  return (tab);
}
