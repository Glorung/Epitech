/*
** epur_str.c for epur_str in /home/gendro_v/Dropbox/Epitech/Tek2d/PSU/PSU_2015_minishell1/lib
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun Dec  6 14:53:25 2015 Vincent Gendron
** Last update Mon Dec 21 17:40:23 2015 Vincent Gendron
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "myirc_client.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    exit_msg(MALLOC_ERROR, MALLOC_MSG);
  while (str[++i] != '\0')
    new[i] = str[i];
  new[i] = 0;
  return (new);
}

char	*epur_str(char *str)
{
  int	i[2];
  char	*res;

  i[1] = 0;
  i[0] = 0;
  while (str[i[0]] && str[i[0]++] && (str[i[0]] == ' ' || str[i[0]] == '\t'));
  i[0] = i[0] - 2;
  if (str[i[0] + 1] == '\0')
    return (NULL);
  if ((res = malloc((strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[++i[0]])
    {
      if (str[i[0]] != ' ' && str[i[0]] != '\t')
	res[i[1]++] = str[i[0]];
      else if (str[i[0]] == ' ' && str[i[0] + 1] != ' ' && str[i[0]])
	res[i[1]++] = ' ';
    }
  free(str);
  if (res[i[1] - 1] == ' ')
    res[i[1] - 1] = '\0';
  else
    res[i[1]] = '\0';
  return (res);
}
