#ifndef MAP_INFO_H
# define MAP_INFO_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'

// hay que cambiar los printf a ft_printf o error(personalizado)
typedef struct s_position
{
	int			x;
	int			y;
}				t_position;




//ESTA ES LA IMPORTANTE
typedef struct s_map_info
{
	char		c;
	int			n_coins;
	int			n_player;
	int			n_exit;
	t_position	*start_pos;
	t_position	*finish_pos;
}				t_map_info;

//ESTA ES LA IMPORTANTE




typedef struct s_map
{
    t_map_info *map_info;
}              t_map;

t_map   *init_(void);
void    print_map_info(t_map_info *info);
void    free_(t_map *map);
#endif