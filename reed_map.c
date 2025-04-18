/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reed_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:02:37 by biniesta          #+#    #+#             */
/*   Updated: 2025/04/17 09:20:48 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// ESTA FUNCION HAY QUE ACTUALIZARLA Y HACERLA MUCHO MEJOR
static void	count_map(t_map *map, int fd, int *columnas, int *filas)
{
	char	*line;
	char	*temp;
	char	*new_line_pos;

	line = get_next_line(fd);
	if (!line)
		the_error("empty file", map);
	temp = NULL;
	while (line != NULL)
	{
		new_line_pos = ft_strchr(line, '\n');
		if (new_line_pos != NULL)
			*new_line_pos = '\0';
		check_map(map, line, columnas, *filas);
		(*filas)++;
		free(temp);
		temp = ft_strcpy_free(map, line);
		line = get_next_line(fd);
	}
	check_last_line(map, temp);
	free(temp);
}

static void	crate_memory_for_matriz(t_map *map)
{
	int	i;

	map->map = (char **)malloc(sizeof(char *) * (map->filas + 1));
	if (map->map == NULL)
		the_error("malloc fails in: crate_memory_for_matriz", map);
	i = 0;
	while (i < map->filas)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->columnas + 1));
		if (map->map[i] == NULL)
			the_error("malloc fails in: crate_memory_for_matriz", map);
		i++;
	}
}

static void	write_matriz(t_map *map, int x, int y)
{
	char	*temp;

	lseek(map->fd, 0, SEEK_SET);
	temp = get_next_line(map->fd);
	while (temp != NULL && x < map->filas)
	{
		y = 0;
		while (temp[y] != '\0' && y < map->columnas)
		{
			map->map[x][y] = temp[y];
			get_obj_info(x, y, map);
			if (map->map[x][y] == PLAYER)
			{
				map->obj->npc->pos->x = 50 * y;
				map->obj->npc->pos->y = 50 * x;
			}
			y++;
		}
		map->map[x][y] = '\0';
		free(temp);
		temp = get_next_line(map->fd);
		x++;
	}
	free(temp);
}

t_map	*create_map_with_info(t_map *map)
{
	count_map(map, map->fd, &map->columnas, &map->filas);
	if (map->columnas < map->filas)
		the_error("the map is not rectangular", map);
	crate_memory_for_matriz(map);
	write_matriz(map, 0, 0);
	return (map);
}
