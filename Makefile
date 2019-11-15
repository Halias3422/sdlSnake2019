NAME= snake

SOURCES= main.c
OBJ_NAME = $(SOURCES:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all:
	make $(NAME)

$(NAME): $(OBJ) Makefile
	gcc -Wall -Werror -Wextra -o ${NAME} $(OBJ) -I . -lSDL

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}
