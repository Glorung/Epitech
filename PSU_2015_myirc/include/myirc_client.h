/*
** myirc.h for include in /home/parria_m/rendu/Tech2/PSU_2015_myirc/include
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Tue May 17 16:11:37 2016 Maxime
** Last update Feb May 23 22:58:13 2016
*/

#ifndef MYIRC_CLIENT_H_
# define MYIRC_CLIENT_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include "ncurses_genshlib.h"

#define TIMEOUT (40)

#define MALLOC_ERROR (-1)
#define MALLOC_MSG ("Fatal error: Not enough memory")

#define FD_READ (client->fd.fd_read)
#define FD_WRITE (client->fd.fd_write)
#define FD client->fd.fd

typedef struct		s_channel
{
  char			*name;
  char			*name_client[1024];
  int			fd_client[1024];
  struct s_channel 	*next;
}			t_channel;

typedef struct		s_server
{
  int			connected;
  char			*ip;
  int			port;
  t_channel		channel[1024];
}			t_server;

typedef struct		s_fd
{
  fd_set		fd_read;
  fd_set		fd_write;
  int			fd[2];
  int			fd_max;
}			t_fd;

struct s_client;

typedef int		(*user_fct)(struct s_client *, char **tab);
typedef int		(*serv_fct)(struct s_client *, char **tab);

typedef struct		s_client
{
  char			*client_input;
  char			*serv_input;
  t_server		server;
  char			*user_cmd[11];
  user_fct		user_fct[11];
  char			*serv_cmd[11];
  serv_fct		serv_fct[11];
  t_fd			fd;
}			t_client;

/* client.c */
int			use_cmd(t_client *);
void			user_action(t_client *);
void			server_action(t_client *);

/* error.c */
int			check_serv(t_client *);
void			exit_msg(int, char *);

/* init.c */
void			init_channel(t_channel *);
void			init_server(t_server *);
void			init_client(t_client **);
void			init(t_client **);
void			init_cmd(t_client *);
void			init_serv_cmd(t_client *);

/* USER CMD */
/* accept.c */
int			xaccept(t_client *, char **);

/* connect.c */
int			xconnect(t_client *, char **);

/* join.c */
int			xjoin(t_client *, char **);

/* list.c */
int			xlist(t_client *, char **);

/* msg.c */
int			xmsg(t_client *, char **);

/* msg_send.c */
int			xmsg_user(t_client *, char **);

/* names.c */
int			xnames(t_client *, char **);

/* nick.c */
int			xnick(t_client *, char **);

/* leave.c */
int			xquit(t_client *, char **);

/* send.c */
int			xsend(t_client *, char **);

/* users.c */
int			xusers(t_client *, char **);

/* SERVER CMD */
/* pong.c */
int			pong(t_client *, char **);

/* notice.c */
int			notice(t_client *, char **);

#endif /* !MYIRC_CLIENT_H_ */
