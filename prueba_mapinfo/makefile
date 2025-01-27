NAME = programa

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = init_info.c free_info.c map_info.c printinfo.c
OBJ = $(SRC:.c=.o)

# Regla para compilar el programa
all: $(NAME)

# Regla para crear el ejecutable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Regla para compilar los archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJ)

# Regla para limpiar todo, incluyendo el ejecutable
fclean: clean
	rm -f $(NAME)

# Regla para recompilar desde cero
re: fclean all

.PHONY: all clean fclean re
