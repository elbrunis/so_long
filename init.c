#include "so_long.h"
static t_map_info *init_map_info()
{
    t_map_info *map_info;

    map_info = (t_map_info*)malloc(sizeof(t_map_info));

    if (map_info == NULL) 
        return (NULL);
    map_info->c = 0;
    map_info->n_coins = 0;
    map_info->n_player = 0;
    map_info->n_exit = 0;

    map_info->start_pos = (t_position *)malloc(sizeof(t_position));
    map_info->finish_pos = (t_position *)malloc(sizeof(t_position));

    if (map_info->start_pos == NULL || map_info->finish_pos == NULL) 
    {
        ft_printf("Error al asignar memoria para las posiciones");
        exit(1);
    }

    map_info->start_pos->x = 0;
    map_info->start_pos->y = 0;
    map_info->finish_pos->x = 0;
    map_info->finish_pos->y = 0;
    return(map_info);
}

static t_map	*init_map(void *mlx)
{
	t_map	*map;
	map = (t_map *)malloc(sizeof(t_map));
	if(!map)
		ft_error("mem_map");
    map->fd = 0;
	map->mlx = mlx;
	map->window = NULL;
	map->map = NULL;
	map->filas = 0;
	map->columnas = 0;
    map->n = '\0';
    map->obj = NULL;
    map->pos.x = 0;
    map->pos.y = 0;
	map->map_info = init_map_info();
	return (map);
}

static t_npc  *init_npc(void *mlx, t_objet *obj) 
{
	t_npc *npc;
	t_position *pos;

	npc = (t_npc *)malloc(sizeof(t_npc));
	if (!npc)
		ft_error("mem_npc");
	pos = (t_position *)malloc(sizeof(t_position));
	if (!pos)
		ft_error("mem_npc");
	npc->pos = pos;
	npc->pos->x = 0;
   	npc->pos->y = 0;
	npc->i = 0; //contador para poner mv o normal
    npc->front = mlx_xpm_file_to_image(mlx, "textures/npc/npc.xpm", &obj->width, &obj->height);
    npc->frontmv = mlx_xpm_file_to_image(mlx, "textures/npc/npcmv.xpm",  &obj->width, &obj->height);
    npc->left = mlx_xpm_file_to_image(mlx, "textures/npc/npcleft.xpm",  &obj->width, &obj->height);
    npc->leftmv = mlx_xpm_file_to_image(mlx, "textures/npc/npcleftmv.xpm",  &obj->width, &obj->height);
    npc->right = mlx_xpm_file_to_image(mlx, "textures/npc/npcright.xpm",  &obj->width, &obj->height);
    npc->rightmv = mlx_xpm_file_to_image(mlx, "textures/npc/npcrightmv.xpm",  &obj->width, &obj->height);
    npc->back = mlx_xpm_file_to_image(mlx, "textures/npc/npcback.xpm",  &obj->width, &obj->height);
    npc->backmv = mlx_xpm_file_to_image(mlx, "textures/npc/npcbackmv.xpm",  &obj->width, &obj->height);
	if (!npc->front || !npc->frontmv || !npc->left || !npc->leftmv ||
        !npc->right || !npc->rightmv || !npc->back || !npc->backmv)
		ft_error("npc");
	
	return (npc);
}

static t_objet	*init_obj(void *mlx)
{
	t_objet	*obj;

	obj = (t_objet *)malloc(sizeof(t_objet));
	if(!obj)
		ft_error("mem_obj");
	obj->width = 0;
	obj->height = 0;
	obj->floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &obj->width, &obj->height);
	obj->wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &obj->width, &obj->height);
	obj->coin = mlx_xpm_file_to_image(mlx, "textures/coin.xpm", &obj->width, &obj->height);
	obj->exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &obj->width, &obj->height);

	obj->npc = init_npc(mlx, obj);
	if (!obj->floor || !obj->wall || !obj->coin || !obj->exit)
		ft_error("texturas");
	return(obj);
}

t_map *init_game_mem(void *mlx)
{
	t_map	*map;
	
	map = init_map(mlx);
	
	map->obj = init_obj(mlx);

	return(map);
}

// int main()
// {
// 	t_map	*map;
// 	void	*mlx;
// 	void	*window;

	
// 	mlx = mlx_init();
// 	window = mlx_new_window(mlx, 1000, 1000, "ventana");
// 	map = init_game(mlx);
// 	mlx_put_image_to_window(mlx, window, map->obj->floor, 0 , 0);
	
// 	map->fd = 23;

// 	ft_printf("pareze que funciona jeje, :%d\n",map->fd);
// 	free_game(map);
// 	mlx_loop(mlx);
// 	return(0);
// }