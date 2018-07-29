/*
** bot.c for lemipc in /home/rebour_j/sysunix/PSU_2015_lemipc
** 
** Made by Jonathan Rebourt
** Login   <rebour_j@epitech.net>
** 
** Started on  Sun Mar 27 13:05:49 2016 Jonathan Rebourt
** Last update Sun Mar 27 22:25:41 2016 Glorung
*/

#include	<sys/shm.h>
#include	<sys/msg.h>
#include	<stdlib.h>
#include	<string.h>
#include	"lemipc.h"

extern key_t	g_key;

void		*check_case(struct s_case *arena, struct s_case *player,
			    int i, int j)
{
  struct s_case	*tmp;

  tmp = arena + (player->y + i) * BOARD_SIZE + (player->x + j);
  if (player->y + i < BOARD_SIZE && player->x + j < BOARD_SIZE &&
            player->y + i > 0 && player->x + j > 0 &&
      tmp->nteam && tmp->nteam != player->nteam)
    return (tmp);
  return (NULL);
}

void		*get_closest_enemy(struct s_case *arena, struct s_case *player)
{
  int		i;
  int		j;
  int		rng;

  rng = 0;
  while (++rng < BOARD_SIZE)
    {
      i = 0;
      while (++i <= rng)
	{
	  j = 0;
	  while (++j <= rng)
	    {
	      if (check_case(arena, player, i, j))
		return (check_case(arena, player, i, j));
	      if (check_case(arena, player, -1 * i, -1 * j))
		return (check_case(arena, player, -1 * i, -1 * j));
	      if (check_case(arena, player, -1 * i, j))
		return (check_case(arena, player, -1 * i, j));
	      if (check_case(arena, player, i, -1 * j))
		return (check_case(arena, player, i, -1 * j));
	    }
	}
    }
  return (NULL);
}

int		get_empty_spot(struct s_case *player_ptr)
{
  if (player_ptr->x > 0 && (player_ptr - 1)->nteam == 0)
    return (2);
  if (player_ptr->x < BOARD_SIZE - 1 && (player_ptr + 1)->nteam == 0)
    return (3);
  if (player_ptr->y > 0 && (player_ptr - BOARD_SIZE)->nteam == 0)
    return (0);
  return (1);
}

int		get_move(struct s_case *arena_ptr, struct s_case *player_ptr)
{
  int		msg_id;
  int		ret;
  struct s_case	*ptr;
  t_msgbuf	buf;

  ret = -1;
  msg_id = msgget(g_key, SHM_W | SHM_R);
  if (msgrcv(msg_id, &buf, 8, ((struct s_case *)player_ptr)->nteam,
	     IPC_NOWAIT) == 8)
    ptr = arena_ptr + buf.mtext[1] * BOARD_SIZE + buf.mtext[0];
  else
    ptr = get_closest_enemy(arena_ptr, player_ptr);
  if (ptr && abs(ptr->x - player_ptr->x) > abs(ptr->y - player_ptr->y))
    ptr->x - player_ptr->x > 0 ? (ret = 3) : (ret = 2);
  else if (ptr)
    ptr->y - player_ptr->y > 0 ? (ret = 1) : (ret = 0);
  if (ret == -1)
    return (rand() % 4);
  memcpy(buf.mtext, ptr, 8);
  buf.mtype = ptr->nteam;
  msgsnd(msg_id, &buf, 8, IPC_NOWAIT);
  return (ret);
}

int		is_last(void *arena_ptr, void *player_ptr)
{
  struct s_case	*arena;
  struct s_case	*player;
  int		i;

  i = -1;
  arena = arena_ptr;
  player = player_ptr;
  while (++i < BOARD_SIZE * BOARD_SIZE)
    {
      if (player != arena && player->nteam == arena->nteam)
	return (0);
      arena++;
    }
  return (1);
}
