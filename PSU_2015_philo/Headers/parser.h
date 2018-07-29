/*
** parser.h for parser in /home/glorung/Project/PSU_2015_philo/Headers
** 
** Made by Glorung
** Login   <glorung@epitech.net>
** 
** Started on  Wed Mar  9 18:09:21 2016 Glorung
** Last update Wed Mar  9 18:09:22 2016 Glorung
*/

#ifndef PARSER_H
# define PARSER_H

/*
** This header file contains the prototypes of the parser's functions.
*/

# define PHILO_PARAM	("-p")
# define EAT_PARAM	("-e")

typedef struct	s_parser
{
  unsigned int	philo_nbr;
  unsigned int	eat_limit;
}		t_parser;

int		isnum(char *str);
t_parser	*init_parser(int ac, char **av);

#endif // !PARSER_H
