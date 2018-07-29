/*
** actions.c for action in /home/glorung/Project/PSU_2015_philo/Sources
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar  9 18:07:40 2016 Glorung
** Last update Fri Mar 11 11:07:15 2016 Glorung
*/

#include "init.h"
#include "extern.h"
#include "actions.h"

void		philo_eats(t_list *l)
{
  l->this->eat_nb--;
  LOCK(&(l->next->this->mu_id));
  lphilo_take_chopstick(&(l->next->this->mu_id));
  if (l->this->state != THINK)
    {
      LOCK(&(l->this->mu_id));
      lphilo_take_chopstick(&(l->this->mu_id));
    }
  l->this->state = EAT;
  lphilo_eat();
  if (l->this->eat_nb == 0)
    {
      UNLOCK(&(l->this->mu_id));
      lphilo_release_chopstick(&(l->this->mu_id));
      UNLOCK(&(l->next->this->mu_id));
      lphilo_release_chopstick(&(l->next->this->mu_id));
    }
}

void		philo_thinks(t_list *l)
{
  l->this->state = THINK;
  LOCK(&(l->this->mu_id));
  lphilo_take_chopstick(&(l->this->mu_id));
  lphilo_think();
}

void		philo_sleeps(t_list *l)
{
  l->this->state = SLEEP;
  UNLOCK(&(l->this->mu_id));
  lphilo_release_chopstick(&(l->this->mu_id));
  if (l->next->this->state != EAT || l->next->this->state != THINK)
    {
      UNLOCK(&(l->next->this->mu_id));
      lphilo_release_chopstick(&(l->next->this->mu_id));
    }
  lphilo_sleep();
}
