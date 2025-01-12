#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/mylibft/libft.h"
# include "libraries/minilibx-linux/mlx.h"
# include <unistd.h>

// size of image
# define IMG_HEIGHT 32
# define IMG_WIDTH 32
// objets
# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_imagen
{
	void		*xpm_ptr;
	t_position	pos;
}				t_imagen;

typedef struct s_matriz
{
	int			fila;
	int			columna;
}				t_matriz;

#endif