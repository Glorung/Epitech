/*
** cmd_USERS.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Wed Jun 01 18:00:45 2016 Maxime
** Last update Thu Jun 02 15:39:33 2016 Maxime
*/

#include "myirc.h"

void		RPL_USERS(t_list *list, char *tab)
{
  char		cpy[4096];
  int		flags;

  flags = 0;
  while (list != NULL)
    {
      if (flags == 0)
	flags = 1;
      else
	strcat(tab, " ");
      strcat(tab, list->nick);
      list = list->next;
    }
  strcpy(cpy, tab);
  if (cpy[0] == '\0')
    strcpy(tab, "RPL_NOUSERS :Nobody logged in");
  else
    {
      strcpy(tab, "RPL_USERS :");
      strcat(tab, cpy);
    }
}

int		cmd_USERS(t_list *list, int fd)
{
  char		tab[4096];

  memset(tab, 0, 4096);
  s_send(392, "RPL_USERSSTART :User Start", find_by_id(list, fd));
  RPL_USERS(list, tab);
  if (strcmp(tab, "RPL_NOUSERS :Nobody logged in") == 0)
    s_send(395, tab, find_by_id(list, fd));
  else
    s_send(393, tab, find_by_id(list, fd));
  s_send(394, "RPL_ENDOFUSERS :End of users", find_by_id(list, fd));
  return (0);
}
