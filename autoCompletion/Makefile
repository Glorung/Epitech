
NAME = autoCompletion

SRCDIR = ./src/

SRCFILE = 	main.cpp \
		exec.cpp \
		string_utils.cpp \
		autoCompletionTown.cpp \
		autoCompletionStreet.cpp \
		getEntry.cpp

SRC = $(foreach file, $(SRCFILE), $(SRCDIR)$(file))

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -g $(IFLAGS)
IFLAGS = -I ./header/

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
