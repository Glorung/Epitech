/*
** parser.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Wed Jun 01 13:55:35 2016 Maxime
** Last update Thu Jun 02 17:52:47 2016 Maxime
*/

#include "myirc.h"

char		*epur_str(char *buffer)
{
  char		*point;
  char		tmp[strlen(buffer)];
  int		i;
  int		j;

  i = -1;
  j = 0;
  while ((point = index(buffer, '\r')) != NULL)
    *point = '\0';
  while (buffer[++i])
    {
      if (buffer[i] == ' ' && buffer[i + 1] == ' ')
	continue;
      tmp[j] = buffer[i];
      j++;
    }
  tmp[j] = '\0';
  return (strdup(tmp));
}

char		*cut(char *tmp, int n, char end)
{
  char		tab[4096];
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (tmp == NULL)
    return (strdup(":"));
  while (tmp[i] && n)
    {
      if (tmp[i] == ' ')
	n--;
      i++;
    }
  while (tmp[i] && (tmp[i] != end && tmp[i] != '\0'))
    {
      tab[j] = tmp[i];
      j++;
      i++;
    }
  tab[j] = '\0';
  return (strdup(tab));
}

t_parse		*parse_it(char *buffer, unsigned int size)
{
  char 		*tmp;
  char		*tof;
  t_parse	*pass;

  buffer[size] = '\0';
  tmp = epur_str(buffer);
  pass = malloc(sizeof(t_parse));
  strcpy(pass->cmd, (tof = cut(tmp, 0, ' ')));
  free(tof);
  strcpy(pass->arg1, (tof = cut(tmp, 1, ' ')));
  free(tof);
  strcpy(pass->arg2, (tof = cut(tmp, 2, ' ')));
  free(tof);
  strcpy(pass->arg3, (tof = cut(tmp, 3, ' ')));
  free(tof);
  strcpy(pass->comment, (tof = cut(strstr(tmp, ":"), 0, '\0')) + 1);
  if (pass->arg1[0] == ':')
    memset(pass->arg1, 0, 256);
  if (pass->arg2[0] == ':' || pass->arg1[0] == '\0')
    memset(pass->arg2, 0, 256);
  if (pass->arg3[0] == ':' || pass->arg2[0] == '\0')
    memset(pass->arg3, 0, 256);
  free(tof);
  free(tmp);
  return (pass);
}
