/*
** get_next_line.c for get_next_line in /home/gendro_v/Dropbox/Epitech/Tek2d/PSU/PSU_2015_minishell1/lib
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun Dec  6 14:53:53 2015 Vincent Gendron
** Last update Sun Dec  6 22:24:21 2015 Vincent Gendron
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

char	*my_strcat(char *str, char *str2)
{
  char	*full;
  int	i;
  int	j;

  if (str2 == NULL)
    return (str);
  if (str == NULL)
    return (str2);
  if ((full = malloc(sizeof(*str) * (strlen(str) + strlen(str2) + 1))) == NULL)
    exit(3);
  i = 0;
  while (i < ((int)strlen(str) + (int)strlen(str2) + 1))
    full[i++] = '\0';
  i = 0;
  j = 0;
  while (str[i])
    full[j++] = str[i++];
  i = 0;
  while (str2[i])
    full[j++] = str2[i++];
  free(str);
  free(str2);
  return (full);
}

char	*my_malloc(int i)
{
  char	*str;
  int	j;

  j = 0;
  str = malloc(i);
  if (str == NULL)
    exit(EXIT_FAILURE);
  while (j < i)
    str[j++] = '\0';
  return (str);
}

int	go_to_line(char *buff, int rd)
{
  int	i;

  i = 0;
  while (buff[i] != '\n' && i < rd)
    i++;
  return (i);
}

char		*get_next_line(const int fd)
{
  static char	buff[BUFFER];
  static int	rd = 0;
  int		i;
  char  	*str;
  int		j;

  j = 0;
  i = -1;
  if (rd <= 0)
    {
      if ((rd = read(fd, buff, BUFFER - 1)) <= 0)
	return (NULL);
    }
  str = my_malloc(((go_to_line(buff, rd) + 1) * sizeof(str)));
  while (buff[++i] != '\n' && buff[i] != '\0')
    str[i] = buff[i];
  i++;
  rd = rd - i;
  while (i < BUFFER)
    buff[j++] = buff[i++];
  while (j < BUFFER)
    buff[j++] = '\0';
  return ((rd < 0 && str[strlen(str) - 1] != '\n')
  	  ? my_strcat(str, get_next_line(fd)) : str);
}
