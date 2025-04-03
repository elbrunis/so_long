/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:48:03 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/23 15:04:51 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_fd(char *argumento)
{
	int	fd;

	fd = open(argumento, O_RDONLY);
	if (fd <= 0)
		the_error("no se pudo abrir el archivo");
	return (fd);
}

static int	press_x(void)
{
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	void	*mlx;
	t_map	*map;

	if (argc != 2)
		the_error("no has pasado el archivo .ber");
	else
		fd = open_fd(argv[1]);
	mlx = mlx_init();
	map = init_game_mem(mlx);
	map->fd = fd;
	map = create_map_with_info(map);
	map->window = mlx_new_window(map->mlx, (map->columnas * 50), (map->filas
				* 50), "so_long");
	es_jugable(map, map->map_info);
	print_map(map);
	mlx_hook(map->window, 2, 1L << 0, move_img, map);
	mlx_hook(map->window, 17, 0, press_x, NULL);
	mlx_loop(map->mlx);
	free_game(map);
	return (0);
}
