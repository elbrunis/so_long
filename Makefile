NAME = hola

CC = gcc
CFLAGS =  -Werror -Wextra -Wall 
SRC = init.c free.c error.c so_long.c reed_map.c put_map.c move.c get_info.c
OBJ = $(SRC:.c=.o)

# Rutas a las bibliotecas
DIR_LIBFT = libraries/mylibft
DIR_MLX = libraries/minilibx-linux

# Archivos de las bibliotecas
LIBFT = $(DIR_LIBFT)/libft.a
MLX = $(DIR_MLX)/libmlx.a

# Incluir cabeceras
INCLUDE = -I$(DIR_LIBFT) -I$(DIR_MLX)

# Reglas
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C $(DIR_LIBFT)

$(MLX):
	make -C $(DIR_MLX)

clean:
	rm -f $(OBJ)
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_MLX)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIBFT)

re: fclean all

.PHONY: all clean fclean re
