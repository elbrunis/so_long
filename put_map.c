#include "so_long.h"

// X->fila   Y->columna
static void	put_images(t_map *map)
{
	if (WALL == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->obj->wall, map->pos.x, map->pos.y);
	if (FLOOR == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->obj->floor,map->pos.x, map->pos.y);
	if (COINS == map->n)
    	mlx_put_image_to_window(map->mlx, map->window, map->obj->coin, map->pos.x, map->pos.y);
	if (PLAYER == map->n)
    	mlx_put_image_to_window(map->mlx, map->window, map->obj->exit, map->pos.x, map->pos.y);//Aqui deberia de ir player
	if (EXIT == map->n)
    	mlx_put_image_to_window(map->mlx, map->window, map->obj->exit, map->pos.x, map->pos.y);
}

// X->fila   Y->columna
void	print_map(t_map *map)
{
	int		x;
	int 	y;

	if (!map || !map->map) // Verifica que el puntero al mapa no sea nulo
	return;
	x = 0;
	while(map->map[x] != NULL && x < map->filas)
	{
		y = 0;
		while(map->map[x][y] != '\0' && y < map->columnas)
		{
			map->pos.y = x * 50;
			map->pos.x = y * 50;
			map->n = map->map[x][y];  //n = tipo de imagen es decir lo que representa en el mapa: 1, 0, E.
			ft_printf("%d ", map->n);
			put_images(map);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}
