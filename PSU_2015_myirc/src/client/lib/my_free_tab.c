/*
** mfree_tab.c for my_free_tab in /home/gendro_v/Dropbox/Epitech/Tek2d/PSU/PSU_2015_minishell1/lib
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun Dec  6 14:55:38 2015 Vincent Gendron
** Last update Sun Dec  6 14:55:43 2015 Vincent Gendron
*/

#include <stdlib.h>

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}
