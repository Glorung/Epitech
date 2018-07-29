/*
** list.h for list in /home/glorung/Project/tmp/PSU_2015_philo
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Thu Mar 10 16:19:34 2016 Glorung
** Last update Thu Mar 24 15:42:40 2016 Glorung
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_list
{
  struct s_philo	*this;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

/* List create */
void			list_push_front(t_list **, void *);
void			list_push_back(t_list **, void *);
/* List utils */
t_list			*list_get_last_elem(t_list *);
int			list_get_size(t_list *);
t_list			*list_classify(t_list **);
/* List remove */
void			list_remove_elem(t_list **, t_list *);
void			list_remove_all(t_list **);

#endif /* !LIST_H_ */
