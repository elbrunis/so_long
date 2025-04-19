/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:22:49 by biniesta          #+#    #+#             */
/*   Updated: 2025/04/04 13:01:33 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_line(t_map *map, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != WALL)
		{
			free(str);//
			the_error("the first line have an invalid char", map);//
		}
		i++;
	}
	return (i);
}

int	check_last_line(t_map *map, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != WALL)
		{
			free(str);//
			the_error("the last line have an invalid char", map);//
		}
		i++;
	}
	return (0);
}
void check_invalid_char(t_map *map, char *str, int *columnas)
{
	int	i;

	i = 0;
	while (i < *columnas && str[i] != '\0')
	{
		if (str[i] != WALL && str[i] != FLOOR && str[i] != COINS
			&& str[i] != PLAYER && str[i] != EXIT)
		{
			free(str);//
			the_error("there is an invalid char", map);//
		}
		i++;
	}
	if (str[1] != WALL && str[*columnas - 1] != WALL) //posible error
	{
		free(str);//
		the_error("the map is not surrounded by walls.", map);//
	}
}

//faltan chequeos
 