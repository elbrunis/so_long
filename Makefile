NAME = so_looong

CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = put_map.c so_long.c
OBJ = $(SRC:.c=.o)

INC = -I./minilibx-linux  # Ruta a las cabeceras de MiniLibX
LIBS = -L./minilibx-linux -lmlx -lX11 -lXext -lm  # Librerías necesarias

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIBS) -o $(NAME)  # Vincula MiniLibX

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/ $(NAME) $(NAME_UNAME) *~ core *.core

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
