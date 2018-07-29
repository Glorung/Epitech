/*
** main.c for lemipc in /home/rebour_j/sysunix/PSU_2015_lemipc
** 
** Made by Jonathan Rebourt
** Login   <rebour_j@epitech.net>
** 
** Started on  Thu Mar 17 11:19:53 2016 Jonathan Rebourt
** Last update Sun Mar 27 23:09:14 2016 Jonathan Rebourt
*/

#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#include	<sys/sem.h>
#include	<sys/msg.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<time.h>
#include	<ncurses.h>
#include	<pthread.h>
#include	"lemipc.h"

key_t		g_key;

int		is_full(struct s_case *arena)
{
  int		i;

  i = -1;
  while (++i < BOARD_SIZE * BOARD_SIZE)
    {
      if (arena->nteam == 0)
	return (0);
    }
  return (1);
}

void		join_game(int shm_id, void *arena_ptr, int nteam)
{
  int		x;
  int		y;
  void		*player_ptr;

  if (!arena_ptr)
    {
      arena_ptr = shmat(shm_id, NULL, SHM_R | SHM_W);
      srand(time(0));
    }
  if (is_full(arena_ptr))
    return ;
  x = rand() % BOARD_SIZE;
  y = rand() % BOARD_SIZE;
  player_ptr = arena_ptr + LINE_SIZE * y + TILE_SIZE * x;
  while (((struct s_case *)player_ptr)->nteam != 0)
    {
      x = rand() % BOARD_SIZE;
      y = rand() % BOARD_SIZE;
      player_ptr = arena_ptr + LINE_SIZE * y + TILE_SIZE * x;
    }
  ((struct s_case*)player_ptr)->nteam = nteam;
  play_game(arena_ptr, player_ptr);
}

void		*init_game(int shm_id)
{
  struct s_case	*tmp_ptr;
  struct s_case	*arena_ptr;
  int		ipc_id;
  struct s_case	tmp;

  arena_ptr = (struct s_case *)shmat(shm_id, NULL, SHM_R | SHM_W);
  initscr();
  tmp_ptr = arena_ptr;
  ipc_id = semget(g_key, 1, IPC_CREAT | SHM_W | SHM_R);
  semctl(ipc_id, 0, SETVAL, 1);
  ipc_id = msgget(g_key, IPC_CREAT | SHM_W | SHM_R);
  tmp.nteam = 0;
  tmp.y = -1;
  while (++tmp.y < BOARD_SIZE)
    {
      tmp.x = -1;
      while (++tmp.x < BOARD_SIZE)
	{
	  memcpy(tmp_ptr , &tmp, TILE_SIZE);
	  tmp_ptr++;
	}
    }
  return (arena_ptr);
}

void		end_game(int shm_id, void *arena_ptr, pthread_t thread)
{
  int		ipc_id;

  pthread_join(thread, NULL);
  shmdt(arena_ptr);
  shmctl(shm_id, IPC_RMID, NULL);
  ipc_id = semget(g_key, 1, SHM_W | SHM_R);
  semctl(ipc_id, 0, IPC_RMID);
  ipc_id = msgget(g_key, SHM_W | SHM_R);
  msgctl(ipc_id, 0, IPC_RMID);
  endwin();
}

int		lemipc(int nteam)
{
  int		shm_id;
  int		curs_state;
  pthread_t	thread;
  void		*arena_ptr;

  thread = 0;
  if ((shm_id = shmget(g_key, (BOARD_SIZE * BOARD_SIZE * TILE_SIZE),
		       SHM_W | SHM_R)) == -1)
    {
      shm_id = shmget(g_key, (BOARD_SIZE * BOARD_SIZE * TILE_SIZE),
		      IPC_CREAT | SHM_W | SHM_R);
      arena_ptr = init_game(shm_id);
      curs_state = curs_set(0);
      pthread_create(&thread, NULL, display_routine, arena_ptr);
      join_game(shm_id, arena_ptr, nteam);
      end_game(shm_id, arena_ptr, thread);
      curs_set(curs_state);
    }
  else
    join_game(shm_id, NULL, nteam);
  return (0);
}
