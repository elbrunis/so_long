/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:59:24 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/07 17:59:25 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// X->fila   Y->columna
// ft_printf("%d\n",map->map_info->start_pos->x);
// ft_printf("%d\n",map->map_info->start_pos->y);
static int	obj_info(t_map *map, int *x, int *y, int x_move, int y_move) // HAY QUE REPARAR ESTA FUNCION
{
	map->map_info->c = map->map[*x + y_move][*y + x_move];
	if (map->map_info->c == COINS)
	{
		map->map[*x + y_move][*y + x_move] = FLOOR;
		map->map_info->n_coins--;
		ft_printf("coin: %d\n", map->map_info->n_coins);
	}
	if (map->map_info->c == WALL)
		return (1);
	if (map->map_info->c == EXIT && map->map_info->n_coins == 0)
		exit(0);
	else if (map->map_info->c == EXIT && map->map_info->n_coins != 0)
		return (1);
	*x += y_move;
	*y += x_move;
	ft_printf("Number of movements: %d\n", map->map_info->n_moves++);
	return (0);
}

static void	move_npc(t_map *map, int x, int y, void *img1, void *img2)
{
	int	i;

	i = 0;
	if (1 == (i = obj_info(map, &map->map_info->start_pos->x,
				&map->map_info->start_pos->y, x, y)))
		return ;
	mlx_put_image_to_window(map->mlx, map->window, map->obj->floor,
		map->obj->npc->pos->x, map->obj->npc->pos->y);
	x *= 50;
	y *= 50;
	map->obj->npc->pos->x += x;
	map->obj->npc->pos->y += y;
	if (map->obj->npc->i == 1)
	{
		mlx_put_image_to_window(map->mlx, map->window, img2,
			map->obj->npc->pos->x, map->obj->npc->pos->y);
		map->obj->npc->i = 0;
	}
	else
	{
		mlx_put_image_to_window(map->mlx, map->window, img1,
			map->obj->npc->pos->x, map->obj->npc->pos->y);
		map->obj->npc->i = 1;
	}
}

static void	move_key(int key, t_map *map)
{
	if (key == ESC)
		mlx_destroy_window(map->mlx, map->window);
	if (key == W || key == UP)
		move_npc(map, 0, -1, map->obj->npc->back, map->obj->npc->backmv);
	if (key == S || key == DOWN)
		move_npc(map, 0, 1, map->obj->npc->front, map->obj->npc->frontmv);
	if (key == D || key == RIGHT)
		move_npc(map, 1, 0, map->obj->npc->right, map->obj->npc->rightmv);
	if (key == A || key == LEFT)
		move_npc(map, -1, 0, map->obj->npc->left, map->obj->npc->leftmv);
}

int	move_img(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	move_key(keycode, map);
	return (0);
}

// int	main(void)
// {
// 	mlx_hook(map->window, 2, 1L << 0, move_img, move);
// 	mlx_loop(map->mlx);
// 	return (0);
// }