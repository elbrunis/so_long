/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:53:45 by biniesta          #+#    #+#             */
/*   Updated: 2025/04/06 15:13:12 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_images(t_map *map)
{
	if (WALL == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->obj->wall,
			map->pos.x, map->pos.y);
	if (FLOOR == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->obj->floor,
			map->pos.x, map->pos.y);
	if (COINS == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->obj->coin,
			map->pos.x, map->pos.y);
	if (PLAYER == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->obj->npc->front[0],
			map->pos.x, map->pos.y);
	if (EXIT == map->n)
		mlx_put_image_to_window(map->mlx, map->window, map->obj->exit,
			map->pos.x, map->pos.y);
}

void	print_map(t_map *map)
{
	int	x;
	int	y;

	if (!map || !map->map || !map->obj || !map->mlx || !map->window)
		return ;
	x = 0;
	while (x < map->filas && map->map[x] != NULL)
	{
		y = 0;
		while (y < map->columnas && map->map[x][y] != '\0' )
		{
			map->pos.y = x * 50;
			map->pos.x = y * 50;
			map->n = map->map[x][y];
			put_images(map);
			y++;
		}
		x++;
	}
}
