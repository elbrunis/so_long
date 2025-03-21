/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:39:08 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/21 10:51:33 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map_info	*init_map_info(void)
{
	t_map_info	*map_info;

	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (map_info == NULL)
		return (NULL);
	map_info->c = 0;
	map_info->n_moves = 0;
	map_info->n_coins = 0;
	map_info->n_player = 0;
	map_info->n_exit = 0;
	map_info->exit = 0;
	map_info->check = NULL;
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
	return (map_info);
}

static void	npc_continue(t_npc *npc, void *mlx, t_objet *obj)
{
	npc->front[0] = mlx_xpm_file_to_image(mlx, "textures/npc/npc.xpm",
			&obj->width, &obj->height);
	npc->front[1] = mlx_xpm_file_to_image(mlx, "textures/npc/npcmv.xpm",
			&obj->width, &obj->height);
	npc->left[0] = mlx_xpm_file_to_image(mlx, "textures/npc/npcleft.xpm",
			&obj->width, &obj->height);
	npc->left[1] = mlx_xpm_file_to_image(mlx, "textures/npc/npcleftmv.xpm",
			&obj->width, &obj->height);
	npc->right[0] = mlx_xpm_file_to_image(mlx, "textures/npc/npcright.xpm",
			&obj->width, &obj->height);
	npc->right[1] = mlx_xpm_file_to_image(mlx, "textures/npc/npcrightmv.xpm",
			&obj->width, &obj->height);
	npc->back[0] = mlx_xpm_file_to_image(mlx, "textures/npc/npcback.xpm",
			&obj->width, &obj->height);
	npc->back[1] = mlx_xpm_file_to_image(mlx, "textures/npc/npcbackmv.xpm",
			&obj->width, &obj->height);
}

static t_npc	*init_npc(void *mlx, t_objet *obj)
{
	t_npc		*npc;
	t_position	*pos;

	npc = (t_npc *)malloc(sizeof(t_npc));
	if (!npc)
		the_error("no se pudo asignar memoria para npc");
	pos = (t_position *)malloc(sizeof(t_position));
	if (!pos)
		the_error("no se pudo asignar memoria para npc");
	npc->pos = pos;
	npc->pos->x = 0;
	npc->pos->y = 0;
	npc->i = 0;
	npc_continue(npc, mlx, obj);
	if (!npc->front || !npc->left || !npc->right || !npc->back)
		the_error("no se han asignado correctamente las imágenes de los NPC");
	return (npc);
}

static t_objet	*init_obj(void *mlx)
{
	t_objet	*obj;

	obj = (t_objet *)malloc(sizeof(t_objet));
	if (!obj)
		the_error("no se ha asignado correctamente la memoria para map info");
	obj->width = 0;
	obj->height = 0;
	obj->floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &obj->width,
			&obj->height);
	obj->wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &obj->width,
			&obj->height);
	obj->coin = mlx_xpm_file_to_image(mlx, "textures/coin.xpm", &obj->width,
			&obj->height);
	obj->exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &obj->width,
			&obj->height);
	obj->npc = init_npc(mlx, obj);
	if (!obj->floor || !obj->wall || !obj->coin || !obj->exit)
		the_error("no se han asignado correctamente las texturas");
	return (obj);
}

t_map	*init_game_mem(void *mlx)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		the_error("no se pudo asignar memoria para map");
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
	map->obj = init_obj(mlx);
	return (map);
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