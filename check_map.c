/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:58:34 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/07 17:55:13 by biniesta         ###   ########.fr       */
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
		while (check_map[i - 1][j])
			check_map[i - 1][j++] = 0;
	}
	return (check_map);
}

static void	ft_algoritmo(t_map_info *map_info, char **map, int x, int y,
		int *si_o_no, int n_coins)
{
	if (x < 0 || y < 0)
		return ;
	if (map_info->n_coins == 0)
		return ;
	if (map[x][y] == WALL || map_info->check[x][y] != 0)
		return ;
	if (map[x][y] == FLOOR || map_info->check[x][y] == 0)
	{
		map_info->check[x][y] = 1;
		if (map[x][y] == COINS || map[x][y] == EXIT)
			n_coins--;
		if (map[x][y] == EXIT)
			*si_o_no = 1;
		ft_algoritmo(map_info, map, x + 1, y, si_o_no, n_coins);
		ft_algoritmo(map_info, map, x, y + 1, si_o_no, n_coins);
		ft_algoritmo(map_info, map, x, y - 1, si_o_no, n_coins);
		ft_algoritmo(map_info, map, x - 1, y, si_o_no, n_coins);
	}
}

void	es_jugable(t_map *map, t_map_info *map_info)
{
	int	i;
	int	n_coins;

	i = 0;
	n_coins = map_info->n_coins;
	map_info->check = check_map_mem(map->filas, map->columnas);
	ft_algoritmo(map_info, map->map, map_info->start_pos->x,
		map_info->start_pos->y, &i, n_coins);
	if (i == 0)
		the_error("el mapa no tiene ningun camino valido");
}

int	check_map(char *str, int *columnas, int filas)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	if (filas == 0)
	{
		while (str[i] != '\0')
		{
			if (str[i] != WALL)
				the_error("la primera fila tiene un caracter que no es muro");
			i++;
		}
		*columnas = i;
		return (0);
	}
	else if (*columnas != (temp = strlen(str)))
		the_error("las filas no miden lo mismo");
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

int	check_last_line(char *str)
{
	int	i;

	while (str[i])
	{
		if (str[i] != WALL)
			the_error("error en la ultima columna, hay un caracter no valido");
		i++;
	}
	return (0);
}
