/*
** init.c for init in /home/glorung/Project/PSU_2015_philo/Sources
**
** Made by Glorung
** Login   <glorung@epitech.net>
**
** Started on  Wed Mar  9 18:07:48 2016 Glorung
** Last update Sat Mar 12 17:24:10 2016 Glorung
*/

#include <stdlib.h>
#include <stdio.h>
#include "init.h"
#include "actions.h"
#include "list.h"
#include "philosophers.h"

int		is_locked(t_philo *philo)
{
  if (TRYLOCK(&(philo->mu_id)) != 0)
    {
      UNLOCK(&(philo->mu_id));
      return (0);
    }
  return (1);
}

void		*loop_philo(void *l)
{
  t_list	*list;

  list = (t_list *)l;
  while (list->this->eat_nb > 0)
    {
      if ((list->this->state == SLEEP) &&
	  (is_locked(list->this) == 0 && is_locked(list->next->this) == 0))
	philo_eats(list);
      else if (list->this->state == EAT && is_locked(list->this) == 0)
	philo_thinks(list);
      else if (list->this->state == THINK)
	philo_sleeps(list);
    }
  pthread_exit(0);
}

t_list		*init_philo(t_parser *p, t_list *l)
{
  unsigned int	i;
  t_philo	*philo;
  pthread_t	th[p->philo_nbr];

  i = 0;
  while (++i != (p->philo_nbr + 1))
    {
      if ((philo = malloc(sizeof(*philo))) == NULL)
        return (NULL);
      philo->id = i;
      philo->eat_nb = p->eat_limit;
      philo->state = THINK;
      pthread_mutex_init(&(philo->mu_id), NULL);
      list_push_back(&l, (void *)philo);
      pthread_create(&th[i], NULL, loop_philo, (void *)list_get_last_elem(l));
    }
  i = 0;
  while (i++ != p->philo_nbr)
    pthread_join(th[i], NULL);
  return (l);
}
