/*
** myirc.h for include in /home/parria_m/rendu/Tech2/PSU_2015_myirc/include
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Tue May 17 16:11:37 2016 Maxime
** Last update Jan Jun 5 14:23:27 2016
*/

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

#ifndef MYIRC_H_
# define MYIRC_H_

typedef struct		s_parse
{
  char			cmd[128];
  char			arg1[256];
  char			arg2[256];
  char			arg3[256];
  char			comment[4096];
}			t_parse;

typedef struct		s_list
{
  int			connected;
  int			fd;
  char			nick[128];
  char			user[128];
  char			ip[40];
  struct s_list 	*next;
}			t_list;

typedef struct		s_channel
{
  char			name[1024];
  int			fd_client[1024];
  struct s_channel 	*next;
}			t_channel;

int			cmd_USERS(t_list *, int);
int			hodor(int, t_parse *, t_channel **, t_list **);
t_parse			*parse_it(char *, unsigned int);
int			existant_nick(t_list *, t_list *, char *);
int			need_more_param(t_list *, char *);
char			*parser(char *, int);
void			everyoneact(t_channel *, t_list *, char *);
int			size_channel(t_channel *);
char			*RPL_REPLYNAME(t_channel *, t_list *, char *);
t_channel		*find_by_name(t_channel *, char *);
int			s_send(int, char *, t_list *);
void			reply_join(int, t_channel *, t_list *, char *);
t_list			*find_by_id(t_list *, int);
void			change_nick(int fd, char *, t_list *, t_channel *);
int			analyze(int fd, t_parse *, t_channel **chan, t_list **);
int			size_list(t_list *);
t_list			*add_list(t_list *, int);
t_list			*rm_list(t_list *, int);
t_list			*get_last(t_list *);
t_list			*free_list(t_list *);
int			server(int);
int			fd_max(t_list *);
t_list			*get_list_at(t_list *, int);
int			fd_max(t_list *);
t_channel		*find_chan_by_id(int, t_channel *);
t_list			*rm_it(t_list *, int, t_channel *);
t_channel		*add_client(t_channel *, char *, int);
t_channel		*remove_client(t_channel *, char *, int);
int			my_socket(int);
int			privmsg(int, t_channel *, t_list *, t_parse *);
int			existant_channel(t_channel *, int, char *, t_list *);

#endif /* !MYIRC_H_ */
