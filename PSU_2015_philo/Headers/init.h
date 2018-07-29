/*
** init.h for init in /home/glorung/Project/PSU_2015_philo/Headers
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar  9 18:09:14 2016 Glorung
** Last update Wed Mar  9 18:09:15 2016 Glorung
*/

#ifndef INIT_H
# define INIT_H

# include "parser.h"
# include "philosophers.h"

t_list		*init_philo(t_parser *, t_list *);
int		is_locked(t_philo *);

#endif // !INIT_H
