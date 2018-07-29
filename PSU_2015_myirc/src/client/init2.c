/*
** client.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Mon May 23 20:19:49 2016 Maxime
** Last update Feb May 23 20:19:56 2016
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<sys/time.h>
#include		<sys/types.h>
#include		<unistd.h>
#include		<sys/select.h>
#include		"myirc_client.h"
#include		"my.h"

void			init_serv_cmd(t_client *new_client)
{
  new_client->serv_cmd[0] = strdup("NOTICE");
  new_client->serv_cmd[1] = NULL;
  new_client->serv_fct[0] = &(notice);
}

void			init_cmd(t_client *new_client)
{
  new_client->user_cmd[0] = strdup("/server");
  new_client->user_cmd[1] = strdup("/nick");
  new_client->user_cmd[2] = strdup("/list");
  new_client->user_cmd[3] = strdup("/join");
  new_client->user_cmd[4] = strdup("/part");
  new_client->user_cmd[5] = strdup("/users");
  new_client->user_cmd[6] = strdup("/names");
  new_client->user_cmd[7] = strdup("/msg");
  new_client->user_cmd[8] = strdup("/send");
  new_client->user_cmd[9] = strdup("/accept");
  new_client->user_cmd[10] = strdup("/quit");
  new_client->user_cmd[11] = NULL;
  new_client->user_fct[0] = &(xconnect);
  new_client->user_fct[1] = &(xnick);
  new_client->user_fct[2] = &(xlist);
  new_client->user_fct[3] = &(xjoin);
  new_client->user_fct[4] = &(xquit);
  new_client->user_fct[5] = &(xusers);
  new_client->user_fct[6] = &(xnames);
  new_client->user_fct[7] = &(xmsg);
  new_client->user_fct[8] = &(xsend);
  new_client->user_fct[9] = &(xaccept);
  new_client->user_fct[10] = &(xquit);
}
