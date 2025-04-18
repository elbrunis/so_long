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

	check_map = (int **)malloc(sizeof(int *) * filas);
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
	map_info->n_coins++;
	map_info->check = check_map_mem(map->filas, map->columnas);
	ft_algoritmo(map_info, map->map, map_info->start_pos->x,
		map_info->start_pos->y);
	map_info->check = free_check_mem(map_info->check,map->filas); //
	if (map_info->exit == 0 || map_info->n_coins != 0)
		the_error("no hay camino valido, revisa las salida y las monedas");
	map_info->n_coins = n_coins;
}

int	check_map(char *str, int *columnas, int filas)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	if (filas == 0)
		*columnas = check_first_line(str);
	else
	{
		temp = strlen(str);
		if (*columnas != temp)
			the_error("las filas no miden lo mismo");
	}
	i = 0;
	while (i < *columnas && str[i] != '\0')
	{
		if (str[i] != WALL && str[i] != FLOOR && str[i] != COINS
			&& str[i] != PLAYER && str[i] != EXIT)
			the_error("hay un caracter invalido");
		i++;
	}
	if (str[1] != WALL && str[*columnas - 1] != WALL)
		the_error("el mapa no esta rodeado por muros");
	return (0);
}
