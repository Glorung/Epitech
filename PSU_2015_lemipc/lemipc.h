/*
** lemipc.h for lemipc in /home/rebour_j/sysunix/PSU_2015_lemipc
** 
** Made by Jonathan Rebourt
** Login   <rebour_j@epitech.net>
** 
** Started on  Sun Mar 27 23:12:27 2016 Jonathan Rebourt
** Last update Sun Mar 27 23:12:29 2016 Jonathan Rebourt
*/

#ifndef LEMIPC_H__
# define LEMIPC_H__

struct  s_case
{
  int   x;
  int   y;
  int   nteam;
};

# define BOARD_SIZE 10
# define TILE_SIZE sizeof(struct s_case)
# define LINE_SIZE BOARD_SIZE * TILE_SIZE

typedef void *(*move_t)(struct s_case *);

typedef struct	s_msgbuf
{
  long		mtype;
  int		mtext[2];
}		t_msgbuf;

void	play_game(void *, void *);
void	*display_routine(void *);
int	is_surrounded(void *);
int	is_won(void *);
int	no_begin(void *);
int	lemipc(int);
void	*move_player(void *, void *);
int	get_move(struct s_case *, struct s_case *);
int	is_last(void *, void *);
int	get_empty_spot(struct s_case *);

#endif /* !LEMIPC_H__ */
