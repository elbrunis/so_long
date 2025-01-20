#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/mylibft/libft.h"
# include "libraries/minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>

// size of image
# define IMG_HEIGHT 50
# define IMG_WIDTH 50
// objets
# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'

// X->fila   Y->columna
typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_objet
{
	int			width;
	int			height;
	void		*floor;
	void		*wall;
	void		*coin;
	void		*exit;
	void		*player;
}				t_objet;

typedef	struct s_map
{
	void		*mlx;
	void		*window;
	char		**map;
	int			filas;
	int			columnas;
	int 		n; //n = tipo de imagen es decir lo que representa en el mapa: 1, 0, E.
	t_objet 	*img;
	t_position	pos;
	
}				t_map;

// typedef struct s_npc
// {
// 	void		*front;
// 	void		*left;
// 	void		*right;
// 	void		*back;
// }				s_npc;

void    count_map(int fd, int *columnas, int *filas);
void	crate_memory_for_matriz(t_map *map);
void    write_matriz(t_map *map, int fd);
t_map	*init_t_map(void);
t_map	*return_map(int fd);
void	init_mlx(int fd);
t_objet	*init_obj(void *mlx);
void	print_map(t_map *map);
void	print_image(t_map *map);
void p(void);


#endif