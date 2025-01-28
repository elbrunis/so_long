#include "so_long.h"

static void	find_cordenadas(t_position *pos, int x, int y, int n)
{
	if (n > 2)
	{
		ft_printf("hay mas de una salida o un jugador, revise el mapa");
		exit(-1);
	}
	pos->x = x; // se invierte por que por alguna razon cuya cual de momento desconozco se imprime el mapa invertido
	pos->y = y; // se multipica la posicion por el tamaño de las imagenes
}
int	get_obj_info(int x, int y, t_map *map)
{
    map->map_info->c = map->map[x][y];
	if (map->map_info->c == COINS)
		map->map_info->n_coins++;
	if (map->map_info->c == PLAYER)
		find_cordenadas(map->map_info->start_pos, x, y,(map->map_info->n_player++));
	if (map->map_info->c == EXIT)
		find_cordenadas(map->map_info->finish_pos, x, y,(map->map_info->n_exit++));
	return (0);
}