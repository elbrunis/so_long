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
static void	check_extension(char *argumento)
{
	int len;

	len = 0;
	while (argumento[len])
		len++;
	if(argumento[len - 1] != 'r' || argumento[len - 2] != 'e' || 
			argumento[len - 3] != 'b')
		the_error("check map extension: map/<name_of_map>.ber", NULL);
}

static int	open_fd(char *argumento)
{
	int	fd;

	check_extension(argumento);
	fd = open(argumento, O_RDONLY);
	if (fd <= 0)
		the_error("check the file: map/<name_of_map>.ber", NULL);
	
	return (fd);
}

int	exit_game(t_map *map)
{
	free_game(map);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	void	*mlx;
	t_map	*map;

	if (argc != 2)
		the_error("check arguments: map/<name_of_map>.ber", NULL);
	else
		fd = open_fd(argv[1]);
	mlx = mlx_init();
	map = init_game_mem(mlx);
	if (!map)
		the_error("game memory failed: check values", map);
	map->fd = fd;
	map = create_map_with_info(map);
	map->window = mlx_new_window(map->mlx, (map->columnas * 50), (map->filas
				* 50), "so_long");
	es_jugable(map, map->map_info);
	print_map(map);
	mlx_hook(map->window, 2, 1L << 0, move_img, map);
	mlx_hook(map->window, 17, 0, exit_game, map);
	mlx_loop(map->mlx);	
	return (0);
}
