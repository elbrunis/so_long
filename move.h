#ifndef MOVE_H
# define MOVE_H

#include "libraries/minilibx-linux/mlx.h"
#include "libraries/mylibft/libft.h"
#include <fcntl.h>
#include <unistd.h>

# define W 119
# define S 115
# define D 100
# define A 97

# define UP 65362
# define DOWN 65364
# define LEFT 65361 
# define RIGHT 65363 

# define ESC 65307

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

typedef struct s_move
{
	void	*mlx;
	void	*window;
	void	*floor;
	int		width;
	int		height;
	int		x;
	int		y;
	int		i; // para verificar si hay que poner el mv o el normal
	t_npc	*npc;

} 				t_move;


#endif
