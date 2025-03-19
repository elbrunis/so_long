/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:58:34 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/19 21:46:34 by biniesta         ###   ########.fr       */
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

static void	ft_algoritmo(t_map_info *map_info, char **map, int x, int y,
		int *si_o_no)
{
	if (x < 0 || y < 0)
		return ;
	if (map_info->n_coins == 0 && *si_o_no == 1)
		return ;
	if (map[x][y] == WALL || map_info->check[x][y] == 1)
		return ;
	if (map[x][y] == FLOOR || map_info->check[x][y] != 1)
	{
		map_info->check[x][y] = 1;
		if (map[x][y] == COINS || map[x][y] == EXIT)
			map_info->n_coins--;
		if (map[x][y] == EXIT)
		{
			*si_o_no = 1;
		}
		ft_algoritmo(map_info, map, x + 1, y, si_o_no);
		ft_algoritmo(map_info, map, x - 1, y, si_o_no);
		ft_algoritmo(map_info, map, x, y + 1, si_o_no);
		ft_algoritmo(map_info, map, x, y - 1, si_o_no);
	}
}

// static void print_check_map(t_map_info *map_info, t_map *map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < map->filas)
// 	{
// 		j = 0;
// 		while (j < map->columnas)
// 		{
// 			ft_printf("%d", map_info->check[i][j]);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }

// static void the_print_map(t_map *map)
// {
// 	int x;
// 	int y;

// 	if (!map || !map->map)
// 		return ;
// 	x = 0;
// 	while (map->map[x] != NULL && x < map->filas)
// 	{
// 		y = 0;
// 		while (map->map[x][y] != '\0' && y < map->columnas)
// 		{
// 			ft_printf("%c", map->map[x][y]);
// 			y++;
// 		}
// 		ft_printf("\n");
// 		x++;
// 	}
// }
void	es_jugable(t_map *map, t_map_info *map_info)
{
	int	i;
	int	n_coins;

	i = 0;
	n_coins = map_info->n_coins;
	map_info->check = check_map_mem(map->filas, map->columnas);
	print_check_map(map_info, map);
	the_print_map(map);
	ft_algoritmo(map_info, map->map, map_info->start_pos->x,
		map_info->start_pos->y, &i);
	map_info->n_coins = n_coins;
	ft_printf("i: %d\n", i);
	print_check_map(map_info, map);
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
