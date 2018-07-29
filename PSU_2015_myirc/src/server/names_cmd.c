/*
** names_cmd.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Wed Jun 01 17:16:46 2016 Maxime
** Last update May Jun 2 14:28:52 2016
*/

#include "myirc.h"

char 		*strtokcpy(char *dest, char *s, char c, int n)
{
  int		j;
  int		i;

  i = -1;
  j = 0;
  while (s[++i] && s[i] != c)
    {
      while (s[i] && n)
	{
	  if (s[i] == c)
	    n--;
	  i++;
	}
      if (!s[i])
	return (NULL);
      dest[j] = s[i];
     j++;
     i++;
    }
  dest[j] = '\0';
  return (dest);
}

void		cmd_NAMES(char *arg, t_list *list, int fd, t_channel *chan)
{
  int		i;
  char		chan_name[1024];

  i = count_char(arg, ',');
  if (arg[0] == '\0')
    NAMES_all(chan, list, fd);
  else
    while (strtokcpy(chan_name, arg, ',', i--))
	send_names(chan, list, fd, chan_name);
}
