# Makefile #

NAME	=	MyGKrellM

SRC	=	src/CPURAMInfo		\
		src/Data		\
		src/DataCPU		\
		src/DataRAM		\
		src/Graph		\
		src/Informations	\
		src/main		\
		src/MainWindows		\
		src/RAMInfo		\
		src/WrapGraph		\
		src/WrapRam		\
		src/Koala		\
		src/displayMonitor	\

SRC_CPP	=	$(foreach file, $(SRC), $(file).cpp)

CPPFLAGS	+=	-std=c++11 -lncurses
CPPFLAGS	+=	-W -I./include -I.
CPPFLAGS	+=	-Wall
CPPFLAGS	+=	-Wextra
#CPPFLAGS	+=	-Werror -lncurses
CPPFLAGS	+=	`pkg-config gtkmm-3.0 --cflags --libs`

OBJ		=	$(SRC_CPP:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) $(CPPFLAGS)

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean	all
