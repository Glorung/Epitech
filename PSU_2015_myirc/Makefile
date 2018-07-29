##
## Makefile for Makefile in /home/parria_m/rendu/Tech2/PSU_2015_myftp
##
## Made by Maxime Parriaux
## Login   <parria_m@epitech.net>
##
## Started on  Tue May  3 13:19:13 2016 Maxime Parriaux
## Last update May Jun 2 14:34:02 2016
##

SRC=				src/server/main.c	\
				src/server/list.c	\
				src/server/list2.c	\
				src/server/server.c	\
				src/server/channel.c	\
				src/server/parsing.c	\
				src/server/generic.c	\
				src/server/nick.c	\
				src/server/join.c	\
				src/server/error_code.c \
				src/server/parser.c	\
				src/server/cmd_USERS.c	\
				src/server/cmd_PRIVMSG.c

SRCC=                           src/client/client.c     \
                                src/client/error.c      \
                                src/client/init.c       \
                                src/client/init2.c      \
                                src/client/main.c       \
                                src/client/server.c     \
                                src/client/accept.c     \
                                src/client/connect.c    \
                                src/client/join.c       \
                                src/client/list.c       \
                                src/client/msg.c        \
                                src/client/msg_send.c   \
                                src/client/names.c      \
                                src/client/nick.c       \
                                src/client/leave.c      \
                                src/client/pong.c       \
                                src/client/notice.c     \
                                src/client/send.c       \
                                src/client/users.c      \
                                src/client/lib/get_next_line.c  \
                                src/client/lib/malloc.c         \
                                src/client/lib/ischar.c         \
                                src/client/lib/my_free_tab.c    \
                                src/client/lib/my_malloc_tab.c  \
                                src/client/lib/epur_str.c       \
                                src/client/lib/my_strtotab.c

SRCQ=                           ./client_bugue/client.c     \
                                ./client_bugue/error.c      \
                                ./client_bugue/init.c       \
                                ./client_bugue/init2.c      \
                                ./client_bugue/main.c       \
                                ./client_bugue/server.c     \
                                ./client_bugue/accept.c     \
                                ./client_bugue/connect.c    \
                                ./client_bugue/join.c       \
                                ./client_bugue/list.c       \
                                ./client_bugue/msg.c        \
                                ./client_bugue/msg_send.c   \
                                ./client_bugue/names.c      \
                                ./client_bugue/nick.c       \
                                ./client_bugue/leave.c      \
                                ./client_bugue/pong.c       \
                                ./client_bugue/notice.c     \
                                ./client_bugue/send.c       \
                                ./client_bugue/users.c      \
                                ./client_bugue/lib/get_next_line.c  \
                                ./client_bugue/lib/malloc.c         \
                                ./client_bugue/lib/ischar.c         \
                                ./client_bugue/lib/my_free_tab.c    \
                                ./client_bugue/lib/my_malloc_tab.c  \
                                ./client_bugue/lib/epur_str.c       \
                                ./client_bugue/lib/my_strtotab.c    \
                                ./client_bugue/ncurses/display_window.c     \
                                ./client_bugue/ncurses/get_entry.c          \
                                ./client_bugue/ncurses/get_entry_tools.c

OBJQ=				$(SRCQ:.c=.o)

OBJC=				$(SRCC:.c=.o)

OBJ=				$(SRC:.c=.o)

CFLAGS=				-W -Wall -Werror -Wextra -I./include

NAME=				server

all:			server client

server:			$(OBJ)
			gcc -o $(NAME) $(CFLAGS) $(OBJ)

client:			$(OBJC)
			gcc -o client $(CFLAGS) $(OBJC)

tar:
			tar zxvf ./src/client_bugue.tar.gz
pitch:			tar $(OBJQ)
			gcc -o client $(CFLAGS) $(OBJQ) -lncurses
			rm -rf ./client_bugue
clean:
			rm -rf $(OBJ)
			rm -rf $(OBJC)

fclean:			clean
			rm -rf $(NAME)
			rm -rf client

re:			fclean all
