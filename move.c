/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:59:24 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/21 10:40:21 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// X->fila   Y->columna

static int	obj_info(t_map *map, int x_move, int y_move)
{
	map->map_info->c = map->map[map->map_info->start_pos->x
		+ y_move][map->map_info->start_pos->y + x_move];
	if (map->map_info->c == COINS)
	{
		map->map[map->map_info->start_pos->x
			+ y_move][map->map_info->start_pos->y + x_move] = FLOOR;
		map->map_info->n_coins--;
	}
	if (map->map_info->c == WALL)
		return (1);
	if (map->map_info->c == EXIT && map->map_info->n_coins == 0)
	{
		free_game(map);
		exit(0);
	}
	map->map_info->start_pos->x += y_move;
	map->map_info->start_pos->y += x_move;
	ft_printf("Number of movements: %d\n", map->map_info->n_moves++);
	return (0);
}

static void move_npc2(t_map *map, void **img1)
{
	if (map->obj->npc->i == 1)
	{
		mlx_put_image_to_window(map->mlx, map->window, img1[0],
			map->obj->npc->pos->x, map->obj->npc->pos->y);
		map->obj->npc->i = 0;
	}
	else
	{
		mlx_put_image_to_window(map->mlx, map->window, img1[1],
			map->obj->npc->pos->x, map->obj->npc->pos->y);
		map->obj->npc->i = 1;
	}
}

static void	move_npc(t_map *map, int x, int y, void **img1)
{
	int	i;

	i = obj_info(map, x, y);
	if (1 == i)
		return ;
	if (map->map_info->is_exit == 1)
	{
		mlx_put_image_to_window(map->mlx, map->window, map->obj->exit,
			map->obj->npc->pos->x, map->obj->npc->pos->y);
		map->map_info->is_exit = 0;
	}
	else
		mlx_put_image_to_window(map->mlx, map->window, map->obj->floor,
			map->obj->npc->pos->x, map->obj->npc->pos->y);
	if (map->map_info->c == EXIT)
		map->map_info->is_exit = 1;
	x *= 50;
	y *= 50;
	map->obj->npc->pos->x += x;
	map->obj->npc->pos->y += y;
	move_npc2(map, img1);
}

static void	move_key(int key, t_map *map)
{
	if (key == ESC)
		exit_game(map);
	if (key == W || key == UP)
		move_npc(map, 0, -1, map->obj->npc->back);
	if (key == S || key == DOWN)
		move_npc(map, 0, 1, map->obj->npc->front);
	if (key == D || key == RIGHT)
		move_npc(map, 1, 0, map->obj->npc->right);
	if (key == A || key == LEFT)
		move_npc(map, -1, 0, map->obj->npc->left);
}

int	move_img(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	move_key(keycode, map);
	return (0);
}
