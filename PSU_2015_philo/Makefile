#####		VARIABLES		#####

###		NAMES		###
NAME		=	philo

###		PATHS		###
PATHSRC		=	./Sources/
PATHHEAD	=	./Headers/

DIRS		=	$(PATHSRC)		\
			$(PATHHEAD)

###		SOURCES		###
SRCPARS		=	$(PATHSRC)parser.c

SRCINIT		=	$(PATHSRC)init.c

SRCACTIONS	=	$(PATHSRC)actions.c

SRCLIST		=	$(PATHSRC)list_create.c	\
			$(PATHSRC)list_utils.c	\
			$(PATHSRC)list_remove.c

SRC		=	main.c			\
			$(SRCPARS)		\
			$(SRCINIT)		\
			$(SRCACTIONS)		\
			$(SRCLIST)

###		OBJECTS		###
OBJ		=	$(SRC:.c=.o)

###		COMPILATION FLAGS		###
CFLAGS  	+=	-W -Wall -Wextra -Werror
CFLAGS  	+=	-I$(PATHHEAD)
CFLAGS  	+=	-std=gnu99
LDFLAGS		+=	-L. -lriceferee -lpthread

###		TOOLBOX		###
GCC		?=	gcc
RM		?=	rm -rf

##.DEFAULT_GOAL	:=	all
.DEFAULT_GOAL	:=	prod

include		mk_colors.mk

#####		RULES		#####

#.SILENT:

$(NAME):	$(OBJ) $(NAMELIB)
		$(GCC) -o $(NAME) $(OBJ) $(LDFLAGS)
		for srcs in $(SRC) ; \
			do echo '┃\t\t✓  '$$srcs ; \
		done

all:		$(NAME)

create:
		for dirs in $(DIRS) ;		\
			do mkdir $$dirs ;	\
		done

debug:		re
debug:		CFLAGS += -g

prod:		all
prod:		CFLAGS += -O2 -Os

clean:
		@echo -e '\n'
		@echo -e '┃'
		@echo -e '┃\t'$(PBLU)$(GRAS)'Suppression of the compiled files...'$(RESET)
		for objs in $(OBJ) ; \
			do echo '┃\t\t♻  '$$objs ; \
		done
		$(RM) $(OBJ) $(OBJLIB)
		@echo -e '┃\t'$(PGRE)'Done !'$(RESET)
		@echo -e '┃'
		@echo -e '┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━'

fclean:		clean
		@echo -e '\n'
		@echo -e '┃'
		@echo -e '┃\tSuppression of the $(NAME) executable...'$(RESET)
		$(RM) $(NAME)
		@echo -e '┃\t\t♻  $(NAME)'$(RESET)
		@echo -e '┃\t'$(PGRE)'Done!'$(RESET)
		@echo -e '┃'
		@echo -e '┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━'

##re:		fclean all
re:		fclean prod

.PHONY:		all prod clean fclean re
