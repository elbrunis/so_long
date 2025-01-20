#ifndef MOVE_H
# define MOVE_H

#include "libraries/minilibx-linux/mlx.h"
#include "libraries/mylibft/libft.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct s_move
{
	void	*mlx;
	void	*window;
	void	*image;
	int		width;
	int		height;
	int		x;
	int		y;
} 				t_move;

#endif
