#ifndef CHEQ_H
#define CHEQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define ALTO 10
# define ANCHO 10

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map_info
{
    char map[ALTO][ANCHO];
    int         **check;
	int			n_coins;
	t_position	*start_pos;
	t_position	*finish_pos;
}				t_map_info;
// // Declaración de la función create_map_mem
// char** create_map_mem(int rows, int cols);

// // Declaración de la función check_map
// int check_map(char** map, int rows, int cols);

#endif // CHEQ_H