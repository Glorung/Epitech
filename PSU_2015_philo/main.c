/*
** main.c for main in /home/glorung/Project/PSU_2015_philo
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar  9 18:08:27 2016 Glorung
** Last update Fri Mar 11 10:56:45 2016 Glorung
*/

#include <stdlib.h>
#include "actions.h"
#include "init.h"
#include "extern.h"

int		main(int ac, char **av)
{
  t_parser	*param;
  t_list	*list;

  if (ac < 5)
    return (EXIT_FAILURE);
  RCFStartup(ac, av);
  if ((param = init_parser(ac, av)) == NULL || param->philo_nbr <= 1 ||
      param->eat_limit == 0 || param->philo_nbr > 60000)
    return (EXIT_FAILURE);
  list = NULL;
  if ((list = init_philo(param, list)) == NULL)
    return (EXIT_FAILURE);
  list_remove_all(&list);
  free(param);
  RCFCleanup();
  return (EXIT_SUCCESS);
}
