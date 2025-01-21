#include "so_long"

t_map	*init_map(void)
{
	t_map	*map;
	map = (t_map *)malloc(sizeof(t_map));
	if(!map)
	{
		ft_printf("no se ha asignado correctamente map");
		exit(-1);
	}
    map->fd = 0;
	map->mlx = NULL;
	map->window = NULL;
	map->map = NULL;
	map->filas = 0;
	map->columnas = 0;
    map->n = '\0';
    map->img = NULL;
    map->pos.x = 0;
    map->pos.y = 0;
	return (map);
}

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
	obj->player = mlx_xpm_file_to_image(mlx, "textures/npc.xpm", &obj->width, &obj->height);
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
