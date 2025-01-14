#include "so_long.h"

t_objet	*init_obj(void *mlx)
{
	t_objet	*obj;

	obj = (t_objet *)malloc(sizeof(t_objet));
	if(!obj)
	{
		ft_printf("no se ha asignado correctamente map info");
		exit(1);
	}
	obj->width = 0;
	obj->height = 0;
	obj->floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &obj->width, &obj->height);
	obj->wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &obj->width, &obj->height);
	obj->coin = mlx_xpm_file_to_image(mlx, "textures/coin.xpm", &obj->width, &obj->height);
	obj->exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &obj->width, &obj->height);
	if (!obj->floor || !obj->wall || !obj->coin || !obj->exit)
	{
    ft_printf("Error: failed to load textures.\n");
	free(obj);
    exit(1);
	}
	return(obj);
}
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

	x = 0;
	while(map->map[x] && x < map->filas)
	{
		y = 0;
		while(map->map[x][y] != '\0' && y < map->columnas)
		{
			map->pos.y = y * 50;
			map->pos.x = x * 50;
			map->n = map->map[x][y];  //n = tipo de imagen es decir lo que representa en el mapa: 1, 0, E.
			print_image(map);
			y++;
		}
		x++;
	}
}
void free_map(t_map *map)
{
    int i;

    if (!map || !map->map)
        return;
    for (i = 0; i < map->filas; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
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
	free_map(map);
	
	mlx_loop(map->mlx);
}