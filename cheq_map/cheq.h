#ifndef CHEQ_H
#define CHEQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h> 

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define ALTO 15
# define ANCHO 15

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;


typedef struct s_map_info
{
	char		c;
	unsigned int n_moves; //
	int			n_coins;
	int			n_player;
	int			n_exit;
	t_position	*start_pos;
	t_position	*finish_pos;
}				t_map_info;

typedef	struct s_map
{
	int			fd;
	char		**map; 
	int			filas;
	int			columnas;
	t_map_info *map_info; //
}				t_map;

// Declaración de la función create_map_mem
char** create_map_mem(int rows, int cols);


t_map *init_game_mem();


// fuera
char	*get_next_line(int fd);



#endif // CHEQ_H