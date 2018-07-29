/*
** philosophers.h for philosophers in /home/glorung/Project/PSU_2015_philo/Headers
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar  9 18:09:33 2016 Glorung
** Last update Thu Mar 10 16:25:47 2016 Glorung
*/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include "list.h"

# define EOLINE		('\0')
# define TRYLOCK	(pthread_mutex_trylock)
# define LOCK		(pthread_mutex_lock)
# define UNLOCK		(pthread_mutex_unlock)

typedef enum		ph_state
{
  SLEEP = 0,
  THINK = 1,
  EAT = 2
}			ph_state;

typedef struct		s_philo
{
  int			id;
  ph_state		state;
  int			eat_nb;
  pthread_mutex_t	mu_id;
}			t_philo;

#endif /* !PHILOSOPHERS_H */
