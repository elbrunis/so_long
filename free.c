/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:46:23 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/21 10:37:08 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_npc_images(void *mlx, t_npc *npc)
{
	if (npc)
	{
		if (npc->front[0])
			mlx_destroy_image(mlx, npc->front[0]);
		if (npc->front[1])
			mlx_destroy_image(mlx, npc->front[1]);
		if (npc->left[0])
			mlx_destroy_image(mlx, npc->left[0]);
		if (npc->left[1])
			mlx_destroy_image(mlx, npc->left[1]);
		if (npc->right[0])
			mlx_destroy_image(mlx, npc->right[0]);
		if (npc->right[1])
			mlx_destroy_image(mlx, npc->right[1]);
		if (npc->back[0])
			mlx_destroy_image(mlx, npc->back[0]);
		if (npc->back[1])
			mlx_destroy_image(mlx, npc->back[1]);
		free(npc);
	}
}

static void	free_images(void *mlx, t_objet *obj)
{
	if (obj)
	{
		if (obj->floor)
			mlx_destroy_image(mlx, obj->floor);
		if (obj->wall)
			mlx_destroy_image(mlx, obj->wall);
		if (obj->coin)
			mlx_destroy_image(mlx, obj->coin);
		if (obj->exit)
			mlx_destroy_image(mlx, obj->exit);
		free_npc_images(mlx, obj->npc);
		free(obj);
	}
}

static void	free_map_struct(t_map *map)
{
	int	x;

	x = 0;
	if (!map || !map->map)
		return ;
	while (x < map->filas)
		free(map->map[x++]);
	free(map->map);
	mlx_destroy_window(map->mlx, map->window);
	mlx_destroy_display(map->mlx);
	free(map);
}

void	free_game(t_map *map)
{
	free_images(map->mlx, map->obj);
	free_map_struct(map);
}
