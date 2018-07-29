/*
** game.c for lemipc in /home/rebour_j/sysunix/PSU_2015_lemipc
** 
** Made by Jonathan Rebourt
** Login   <rebour_j@epitech.net>
** 
** Started on  Thu Mar 17 14:27:16 2016 Jonathan Rebourt
** Last update Sun Mar 27 22:57:59 2016 Glorung
*/

#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#include	<sys/sem.h>
#include	<sys/msg.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	"lemipc.h"

extern key_t	g_key;

int		is_won(void *arena_ptr)
{
  int		i;
  int		j;
  int		nteam;
  struct s_case	*cast;

  j = -1;
  nteam = 0;
  cast = arena_ptr;
  while (++j < BOARD_SIZE)
    {
      i = -1;
      while (++i < BOARD_SIZE)
	{
	  if (cast->nteam != 0)
	    {
	      if (nteam == 0)
		nteam = cast->nteam;
	      else if (nteam != cast->nteam)
		return (0);
	    }
	  cast++;
	}
    }
  return (1);
}

int		no_begin(void *arena_ptr)
{
  int		i;
  int		j;
  int		nteam;
  struct s_case	*cast;

  j = -1;
  nteam = 0;
  while (++j < BOARD_SIZE)
    {
      i = -1;
      while (++i < BOARD_SIZE)
	{
	  cast = (struct s_case*)(arena_ptr + j * LINE_SIZE + i * TILE_SIZE);
	  if (cast->nteam != 0)
	    {
	      if (nteam == 0)
		nteam = cast->nteam;
	      else if (nteam != cast->nteam)
		return (1);
	    }
	}
    }
  return (0);
}

void		init_sembuf(struct sembuf *ptr, int op)
{
  if (ptr)
    {
      ptr->sem_num = 0;
      ptr->sem_flg = 0;
      ptr->sem_op = op;
    }
}

void		play_game(void *arena_ptr, void *player_ptr)
{
  int		sem_id;
  struct sembuf	incr;
  struct sembuf	decr;
  int		begin;
  int		t1;
  int		t2;

  begin = 0;
  sem_id = semget(g_key, 1, SHM_W | SHM_R);
  init_sembuf(&incr, 1);
  init_sembuf(&decr, -1);
  while (begin != 2 && player_ptr)
    {
      if (begin == 1 || (begin = no_begin(arena_ptr)) == 1)
	{
	  semop(sem_id, &decr, 1);
	  usleep(100);
	  if (!(t1 = is_surrounded(player_ptr)) && !(t2 = is_won(arena_ptr)))
	    player_ptr = move_player(arena_ptr, player_ptr);
	  else
	    begin = 2;
	  semop(sem_id, &incr, 1);
	}
    }
  ((struct s_case*)player_ptr)->nteam = 0;
}
