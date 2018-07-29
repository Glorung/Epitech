/*
** mmalloc_tab.c for my_malloc_tab in /home/gendro_v/Dropbox/Epitech/Tek2d/PSU/PSU_2015_minishell1/lib
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun Dec  6 14:56:00 2015 Vincent Gendron
** Last update Sun Dec  6 22:04:29 2015 Vincent Gendron
*/

#include <stdlib.h>
#include "my.h"

char	**my_malloc_tab(int i)
{
  char	**tab;

  if ((tab = malloc(i)) == NULL)
    exit(EXIT_FAILURE);
  return (tab);
}
