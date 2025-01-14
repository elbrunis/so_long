#include "so_long.h"

int press_x(void)
{
    ft_printf("bien hecho cabronzete\n");
    exit(0);
    return(0);
}
int	main(void)
{
	void	*mlx;
	void	*window;
	void	*image;
	int width, height;
	int fila, columna;
	
	fila = 0;
	columna = 0;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "ventana");
	
 	
	mlx_hook(window, 17, 0, press_x, NULL);
	for (int i = 0; i < 20; i++)
	{
		image = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &width, &height);
		mlx_put_image_to_window(mlx, window, image, fila , columna);// fila, columna
		columna += 50;

	}
	ft_printf("alto: %i\nancho: %i\n", height, width);

	mlx_loop(mlx);
	return (0);
}
