/*
** get_next_line.c for get_next_line in /home/gendro_v/Dropbox/Epitech/Tek2d/PSU/PSU_2015_minishell1/lib
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun Dec  6 14:53:53 2015 Vincent Gendron
** Last update Sun Dec  6 22:24:21 2015 Vincent Gendron
*/

#include		<stdlib.h>

int			ischar(char str, char *patern)
{
  int			i;

  i = -1;
  while (patern[++i])
    if (patern[i] == str)
      return (1);
  return (0);
}

int			isstr(char *str, char *patern)
{
  int			i;

  i = -1;
  while (str[++i])
    {
      if (!ischar(str[i], patern))
	return (0);
    }
  return (1);
}
