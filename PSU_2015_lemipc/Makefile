##
## Makefile for lemipc in /home/rebour_j/sysunix/PSU_2015_lemipc
## 
## Made by Jonathan Rebourt
## Login   <rebour_j@epitech.net>
## 
## Started on  Thu Mar 17 12:02:50 2016 Jonathan Rebourt
## Last update Sun Mar 27 13:12:37 2016 Jonathan Rebourt
##

CC	= gcc

CFLAGS	+= -W
CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -I ./incs/
CFLAGS	+= -I .
CFLAGS	+= -lncurses
CFLAGS	+= -lpthread
CFLAGS	+= -g

RM	= rm -f

NAME	= lemipc

SRCS	= srcs/main.c			\
	  srcs/game.c			\
	  srcs/display.c		\
	  srcs/surround.c		\
	  srcs/lemipc.c			\
	  srcs/players.c		\
	  srcs/bot.c			\
	  srcs/move.c			\
	  srcs/ncurses/ncurses.c	\
	  srcs/ncurses/ncurses_draw.c	\
	  srcs/list/list_create.c	\
	  srcs/list/list_remove.c	\
	  srcs/list/list_utils.c

OBJS	= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

all: $(NAME)

clean:
	find -name "*#" -delete
	find -name "*~" -delete
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
