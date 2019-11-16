NAME= snake

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SOURCES= main.c generic_sdl_functions.c init_playground_colors.c \
		 print_title_letters.c game_loop.c snake_update_position.c debug.c
INCLUDES= snake.h
OBJ_NAME = $(SOURCES:.c=.o)

INC = $(addprefix $(INC_PATH), $(INCLUDES))
SRC = $(addprefix $(SRC_PATH), $(SOURCES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

FLAG += -Wall -Werror -Wextra -fsanitize=address

all:
	make $(NAME)

$(NAME): $(OBJ) Makefile
	gcc $(FLAG) -o ${NAME} $(OBJ) -I . -lSDL2

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	gcc $(FLAG) -g -I $(INC_PATH) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf ${NAME}
