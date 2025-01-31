
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'

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

// X->fila   Y->columna
void check_map(t_map *map_info, int x, int y)
{
    if(map_info->coins == 0)
        return;

    if(map_info->map[x][y] == FLOOR || map_info->check[x][y] != 0)
    {
        check[x][y] == 1;

        if(map_info->map[x][y] == COINS || map_info->map[x][y] == EXIT)
            map_info->n_coins--;

        if(map_info->map[x][y] == EXIT)
            return;
        check_map(map_info, x + 1, y) //abajo
        check_map(map_info, x, y + 1) //derecha
        check_map(map_info, x , y - 1) //izquierda
        check_map(map_info, x - 1, y) //arriba
    }
}

int main()
{
    char map[ALTO][ANCHO] = 
    {{'1', '1', '1', '1', '1'},
     {'1', 'C', '0', 'E', '1'},
     {'1', '0', '1', '0', '1'},
     {'1', '0', 'C', '0', '1'},
     {'1', '1', '1', '1', '1'}};

}