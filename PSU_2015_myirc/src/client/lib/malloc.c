/*
** get_next_line.c for get_next_line in /home/gendro_v/Dropbox/Epitech/Tek2d/PSU/PSU_2015_minishell1/lib
** 
** Made by Vincent Gendron
** Login   <gendro_v@epitech.net>
** 
** Started on  Sun Dec  6 14:53:53 2015 Vincent Gendron
** Last update Sun Dec  6 22:24:21 2015 Vincent Gendron
*/

#include	<stdlib.h>
#include	"my.h"
#include	"myirc_client.h"

void		*xmalloc(int size)
{
  void		*return_v;

  return_v = malloc(size);
  if (return_v == NULL)
    exit_msg(MALLOC_ERROR, MALLOC_MSG);
  return (return_v);
}
