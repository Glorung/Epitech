/*
** my.h for my.h in /home/gendro_v/Dropbox/Epitech/Tek2d/PSU/PSU_2015_minishell1/include
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun Dec  6 19:20:12 2015 Vincent Gendron
** Last update Sun Dec  6 22:36:08 2015 Vincent Gendron
*/

#ifndef MY_H_
# define MY_H_

#define BUFFER 10

void	my_putstr(char *);
int	my_strlen(char *);
char	*my_strdup(char *);
int	my_strcmp(char *, char *);
char	*my_strrealloc(char *, char *);
char	*epur_str(char *);
char	**my_strtotab(char *, char *);
char	**put_in_tab(char **, char *);
char	*get_next_line(const int);
char	*my_malloc(int);
char	**my_malloc_tab(int);
void	my_free_tab(char **);
void	*xmalloc(int);
int	ischar(char, char *);
int	isstr(char *, char *);

#endif /* !MY_H_ */
