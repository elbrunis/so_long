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
// key
# define W 119
# define S 115
# define D 100
# define A 97

# define UP 65362
# define DOWN 65364
# define LEFT 65361 
# define RIGHT 65363 

# define ESC 65307

// X->fila   Y->columna
typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_npc
{
	void		*front;
	void		*frontmv;
	void		*left;
	void		*leftmv;
	void		*right;
	void		*rightmv;
	void		*back;
	void		*backmv;
}				t_npc;

typedef struct s_objet
{
	int			width;
	int			height;
	void		*floor;
	void		*wall;
	void		*coin;
	void		*exit;
	t_npc		*npc;
}				t_objet;

typedef	struct s_map
{
	int			fd;
	void		*mlx;
	void		*window;
	char		**map;
	int			filas;
	int			columnas;
	int 		n; //n = tipo de imagen es decir lo que representa en el mapa: 1, 0, E.
	t_objet 	*img;
	t_position	pos;
	
}				t_map;

void    count_map(int fd, int *columnas, int *filas);
void	crate_memory_for_matriz(t_map *map);
void    write_matriz(t_map *map, int fd);
t_map	*init_map(void);
t_map	*return_map(int fd);
void	init_mlx(int fd);
t_objet	*init_obj(void *mlx);
void	print_map(t_map *map);
void	print_image(t_map *map);
void    ft_error(char *str);


#endif