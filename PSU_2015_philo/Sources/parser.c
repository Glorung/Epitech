/*
** parser.c for parser in /home/glorung/Project/PSU_2015_philo/Sources
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar  9 18:08:16 2016 Glorung
** Last update Wed Mar  9 18:08:16 2016 Glorung
*/

#include <stdlib.h>
#include <string.h>
#include "philosophers.h"
#include "parser.h"

int		isnum(char *str)
{
  if (str == NULL || str[0] == EOLINE)
    return (0);
  if (!(str[0] >= '0' && str[0] <= '9'))
    return (0);
  while ((++str)[0] != '\0')
    {
      if (!(str[0] >= '0' && str[0] <= '9'))
	return (0);
    }
  return (1);
}

t_parser	*init_parser(int ac, char **av)
{
  int		i;
  t_parser	*return_v;

  if ((return_v = malloc(sizeof(t_parser))) == NULL)
    return (NULL);
  return_v->philo_nbr = 0;
  return_v->eat_limit = 0;
  i = 0;
  while (++i != ac)
    {
      if (strcmp(av[i], PHILO_PARAM) == 0 && av[i + 1] && isnum(av[i + 1]) &&
	  return_v->philo_nbr == 0)
	return_v->philo_nbr = (unsigned int)atoi(av[(i++) + 1]);
      else if (strcmp(av[i], EAT_PARAM) == 0 && av[i + 1] && isnum(av[i + 1]) &&
	       return_v->eat_limit == 0)
	return_v->eat_limit = (unsigned int)atoi(av[(i++) + 1]);
    }
  return (return_v);
}
