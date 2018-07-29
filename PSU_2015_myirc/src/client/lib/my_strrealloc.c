/*
** mstrrealloc.c for my_strrealloc in /home/gendro_v/Dropbox/Epitech/Tek2d/PSU/PSU_2015_minishell1/lib
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun Dec  6 14:56:57 2015 Vincent Gendron
** Last update Sun Dec  6 22:09:50 2015 Vincent Gendron
*/

#include <stdlib.h>
#include "list.h"
#include "my.h"

char	*my_strrealloc(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*str;

  if ((str = my_malloc(sizeof(str) * (my_strlen(str1) + my_strlen(str2) + 1)))
      == NULL)
    return (NULL);
  i = 0;
  while (str1[i])
    {
      str[i] = str1[i];
      i = i + 1;
    }
  j = 0;
  while (str2[j])
    str[i++] = str2[j++];
  str[i] = '\0';
  return (str);
}
