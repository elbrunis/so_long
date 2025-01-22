#include "so_long.h"

int	open_fd(void)
{
	int	fd;

	fd = open("map/map2.ber", O_RDONLY);
	if (fd <= 0)
		ft_error("fd");
	return (fd);
}

int	main(int ac, char **av)
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
	mlx_loop(map->mlx);
	return (0);
}
