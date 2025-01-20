# include "move.h"
// prees_key()
// {
// }
// X->fila   Y->columna
int move_img(int keycode, void *param)
{
    t_move  *move;

	ft_printf("Keycode: %d\n", keycode);
    move = (t_move *)param;
    if (keycode == 119) // W key
        move->y -= 50; // Mover hacia arriba
    if (keycode == 115) // S key
        move->y += 50; // Mover hacia abajo
    if (keycode == 100) // D key
        move->x += 50; // Mover hacia la derecha
    if (keycode == 97) // A key
        move->x -= 50; // Mover hacia la izquierda

    // Limpiar la ventana y redibujar la imagen en la nueva posición
    mlx_clear_window(move->mlx, move->window);
    mlx_put_image_to_window(move->mlx, move->window, move->image, move->x, move->y);

    return (0);
}
t_move	*init_move(void)
{
	t_move	*move;

	move = (t_move *)malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	move->mlx = NULL;
	move->window = NULL;
	move->image = NULL;
	move->width = 0;
	move->height = 0;
	move->x = 0;
	move->y = 0;
	return (move);
}
int	main(void)
{
	t_move *move;
	
	// init
	move = init_move();
	move->mlx = mlx_init();
	move->image = mlx_xpm_file_to_image(move->mlx, "textures/npc.xpm", &move->width, &move->height);
	move->window = mlx_new_window(move->mlx, 1000, 700, "ventana");
	mlx_put_image_to_window(move->mlx, move->window, move->image, move->x , move->y);
	// fin init

	// functions
	mlx_hook(move->window, 2, 1L << 0, move_img, move);
	mlx_loop(move->mlx);
	return (0);
}