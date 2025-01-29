#include "so_long.h"

static int	open_fd(char *argumento)
{
	int	fd;

	fd = open(argumento, O_RDONLY);
	if (fd <= 0)
		ft_error("fd");
	return (fd);
}
static int press_x(void)
{
    ft_printf("bien hecho cabronzete\n");
    exit(0);
    return(0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	void	*mlx;
	t_map	*map;

	if (argc != 2)
		ft_error("texturas");
	else
		fd = open_fd(argv[1]);
	mlx = mlx_init();
	map = init_game_mem(mlx);
	map->fd = fd;
	map = create_map_with_info(map);
	
	map->window = mlx_new_window(map->mlx, (map->columnas * 50), (map->filas * 50), "so_long");
	print_map(map);
	mlx_hook(map->window, 2, 1L << 0, move_img, map);
	mlx_hook(map->window, 17, 0, press_x, NULL); // es para cerrar la ventana
	mlx_loop(map->mlx);
	free_game(map);
	return (0);
}
