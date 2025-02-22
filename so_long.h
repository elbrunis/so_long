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

typedef struct s_map_info
{
	char		c;
	int			**check;
	unsigned int n_moves; //
	int			n_coins;
	int			n_player;
	int			n_exit;
	t_position	*start_pos;
	t_position	*finish_pos;
}				t_map_info;

typedef struct s_npc
{
	int			i; //es el contador para el movimiento del npc
	t_position	*pos;
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
	t_objet 	*obj;
	t_position	pos;
	t_map_info *map_info; //
}				t_map;

void	print_map(t_map *map);
//mensajes de error
void    ft_error(char *str);
int the_error(char *str); //nuevo error
//memory
void	free_game(t_map *map);
t_map	*init_game_mem(void *mlx);
t_map	*create_map_with_info(t_map *map);
//move key
int move_img(int keycode, void *param);
// get info
int	get_obj_info(int x, int y, t_map *map);
//check map
int	check_map(char *str, int *columnas, int filas);
void es_jugable(t_map *map, t_map_info *map_info);


#endif