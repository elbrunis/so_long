/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:58:34 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/20 18:01:01 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	**check_map_mem(int filas, int columnas)
{
	int	**check_map;
	int	i;
	int	j;

	if (filas <= 0 || columnas <= 0)
		return (NULL);
	check_map = (int **)malloc(sizeof(int *) * filas);
	if (!check_map)
		return (NULL);
	i = 0;
	while (i < filas)
	{
		check_map[i++] = (int *)malloc(sizeof(int) * columnas);
		j = 0;
		while (j < columnas)
			check_map[i - 1][j++] = 0;
	}
	return (check_map);
}

static int **free_check_mem(int **array, int filas)
{
	int i;

	i = 0;
	if (!array)
		return (NULL);
	while (i < filas)
		free(array[i++]);
	free(array);
	return (NULL);
}

static void	ft_algoritmo(t_map_info *map_info, char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (map_info->n_coins == 0 && map_info->n_coins == 1)
		return ;
	if (map[x][y] == WALL || map_info->check[x][y] == 1)
		return ;
	if (map[x][y] == FLOOR || map_info->check[x][y] != 1)
	{
		map_info->check[x][y] = 1;
		if (map[x][y] == COINS || map[x][y] == EXIT)
			map_info->n_coins--;
		if (map[x][y] == EXIT)
			map_info->exit = 1;
		ft_algoritmo(map_info, map, x + 1, y);
		ft_algoritmo(map_info, map, x - 1, y);
		ft_algoritmo(map_info, map, x, y + 1);
		ft_algoritmo(map_info, map, x, y - 1);
	}
}

void	es_jugable(t_map *map, t_map_info *map_info)
{
	int	n_coins;

	n_coins = map_info->n_coins;
	if (n_coins <= 0)
		the_error("there are no coins", map);
	map_info->n_coins++;
	map_info->check = check_map_mem(map->filas, map->columnas);
	if (!map_info->check)
		the_error("mem_check failed: check_map.c", map);
	ft_algoritmo(map_info, map->map, map_info->start_pos->x,
		map_info->start_pos->y);
	map_info->check = free_check_mem(map_info->check,map->filas); //
	if (map_info->exit == 0 || map_info->n_coins != 0)
		the_error("there is not valid path", map); //
	if (1 < map_info->n_player || 1 < map_info->n_exit)
		the_error("Duplicate item: You need <1 exit> <1 player>", map);
	map_info->n_coins = n_coins;
}

int	check_map(t_map *map, char *str, int *columnas, int filas)
{
	int	temp;

	temp = 0;
	if (filas == 0)
		*columnas = check_first_line(map, str);
	else
	{
		temp = ft_strlen(str);
		if (*columnas != temp)
		{
			free(str);//
			the_error("rows does not have the same length", map); //
		}
	}
	check_invalid_char(map, str, columnas);//
	return (0);
}
