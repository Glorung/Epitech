/*
** notice.c for client in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src/client
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Sun Jun 05 18:02:19 2016 Maxime
** Last update Jan Jun 5 18:02:26 2016
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"myirc_client.h"
#include	"my.h"

int		notice(t_client *client, char **tab)
{
  int		i;
  int		j;
  char		**tab2;
  char		**tab3;

  tab2 = my_strtotab(strdup(client->serv_input), "\n");
  i = -1;
  printf("- %s -", client->server.ip);
  while (tab2[++i] != NULL)
    {
      tab3 = my_strtotab(tab2[i], " ");
      j = 3;
      if (tab3[0] && tab3[1] && tab3[2] && tab3[3])
	{
	  if (tab3[j][0] == ':')
	    tab3[j][0] = ' ';
	  while (tab3[j] != NULL && tab3[j + 1] != NULL)
	    printf("%s ", tab3[j++]);
	}
      if (tab3[j])
	printf("%s", tab3[j]);
      printf("\n");
    }
  tab = tab;
  return (0);
}
