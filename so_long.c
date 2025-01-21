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
	int	fd;

	fd = open_fd();
	init_mlx(fd);
	return (0);
}
