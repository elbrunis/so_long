#include "so_long.h"

// X->fila   Y->columna
void	print_image(t_map *map)
{
	if (WALL == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->img->wall, map->pos.x, map->pos.y);
	if (FLOOR == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->img->floor,map->pos.x, map->pos.y);
	if (COINS == map->n)
    	mlx_put_image_to_window(map->mlx, map->window, map->img->coin, map->pos.x, map->pos.y);
	if (PLAYER == map->n)
    	mlx_put_image_to_window(map->mlx, map->window, map->img->player, map->pos.x, map->pos.y);
	if (EXIT == map->n)
    	mlx_put_image_to_window(map->mlx, map->window, map->img->exit, map->pos.x, map->pos.y);
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
			print_image(map);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}

// width->ancho   height->altura
void	init_mlx(int fd)
{
	t_map	*map;
	t_objet	*obj;

	map = return_map(fd);

	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, (map->columnas * 50), (map->filas * 50), "so_long");

	obj = init_obj(map->mlx);
	map->img = obj;
	print_map(map);

	mlx_loop(map->mlx);
	free_objet(obj);
	free_map(map);
}