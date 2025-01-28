#include "so_long.h"

int	open_fd(void)
{
	int	fd;

	fd = open("map/map1.ber", O_RDONLY);
	if (fd <= 0)
		ft_error("fd");
	return (fd);
}

int	main()
{
	int		fd;
	void	*mlx;
	t_map	*map;

	fd = open_fd();
	mlx = mlx_init();
	map = init_game_mem(mlx);
	map->fd = fd;
	map = create_map_with_info(map);
	
	map->window = mlx_new_window(map->mlx, (map->columnas * 50), (map->filas * 50), "so_long");
	print_map(map);
	mlx_hook(map->window, 2, 1L << 0, move_img, map);
	mlx_loop(map->mlx);
	free_game(map);
	return (0);
}
