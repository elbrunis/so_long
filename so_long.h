#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "libraries/mylibft/libft.h"

// size of image
# define IMG_HEIGHT	32
# define IMG_WIDTH	32
// objets 
# define WALL		'1'
# define FLOOR 		'0'
# define COINS 		'C'
# define PLAYER		'P'
# define MAP_EXIT  	'E'

typedef struct s_position
{
    int x;
    int y;
}           t_position;

typedef struct s_imagen
{
    void    *xpm_ptr;
    t_position pos;
}              t_imagen;

#endif