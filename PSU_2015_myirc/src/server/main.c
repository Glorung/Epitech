/*
** main.c for src in /home/parria_m/rendu/Tech2/PSU_2015_myirc/src
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Tue May 17 16:10:45 2016 Maxime
** Last update Apr Jun 1 02:07:33 2016
*/

#include "myirc.h"

int		my_socket(int port)
{
  int			fd;
  struct protoent	*pe;
  struct sockaddr_in	addr_in;

  addr_in.sin_family = AF_INET;
  addr_in.sin_port = htons(port);
  addr_in.sin_addr.s_addr = INADDR_ANY;
  if ((pe = getprotobyname("TCP")) == NULL)
    return (-1);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      close(fd);
      return (-1);
    }
  if (bind(fd, (const struct sockaddr *)&addr_in, sizeof(addr_in)) == -1)
    {
      close(fd);
      return (-1);
    }
  if (listen(fd, 100) == -1)
    {
      close(fd);
      return (-1);
    }
  return (fd);
}

void		usage()
{
  printf("Usage : ./server port\n");
  exit(1);
}

int		is_number(char *arg)
{
  while (*arg)
    {
      if (*arg < '0' || *arg > '9')
	return (1);
      arg = arg + 1;
    }
  return (0);
}

void		initial_check(char **argv)
{
  if (is_number(argv[1]) == 1)
    usage();
}

int		main(int argc, char **argv)
{
  if (argc != 2)
    usage();
  initial_check(argv);
  server(atoi(argv[1]));
  return (0);
}
