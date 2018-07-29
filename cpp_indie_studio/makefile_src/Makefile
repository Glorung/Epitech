##
## Makefile for make_scr in /home/glorung/Project/my_move/makefile_scr
## 
## Made by Glorung
## Login   <glorung@epitech.net>
## 
## Started on  Mon Apr  4 13:27:11 2016 Glorung
## Last update Mon Apr  4 19:44:02 2016 Glorung
##

NAME =	make_display

SRC =	make_src.c

OBJ =	$(SRC:.c=.o)

.SILENT:

all :		$(NAME)

$(NAME) :	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I.

clean :
	rm -f $(OBJ)

fclean :	clean
	rm -f $(NAME)

re :		fclean $(NAME)
