#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 2000, 2000, "ventana");
	return (0);
}
