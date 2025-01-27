# include "move.h"



// X->fila   Y->columna
void	move_npc(t_move *move, int x, int y, void *img1, void *img2)
{
	mlx_put_image_to_window(move->mlx, move->window, move->floor, move->x, move->y); //Se pone aqui para que se haga solamente si se cumple las condiciones de la funcion anterior

    move->x += x;
    move->y += y;
    if (move->i == 1)
    {
        mlx_put_image_to_window(move->mlx, move->window, img2, move->x, move->y);
        move->i = 0;
    }
    else
    {
        mlx_put_image_to_window(move->mlx, move->window, img1, move->x, move->y);
        move->i = 1;
    }
}

void	move_key(int key, t_move *move)
{
	if (key == ESC)
		mlx_destroy_window(move->mlx, move->window);
    if (key == W || key == UP)
        move_npc(move, 0, -50, move->npc->back, move->npc->backmv);
    if (key == S || key == DOWN)
        move_npc(move, 0, 50, move->npc->front, move->npc->frontmv);
    if (key == D || key == RIGHT)
        move_npc(move, 50, 0, move->npc->right, move->npc->rightmv);
    if (key == A  || key == LEFT)
        move_npc(move, -50, 0, move->npc->left, move->npc->leftmv);
}


int move_img(int keycode, void *param)
{
    t_move  *move;

    move = (t_move *)param;
	move_key(keycode, move);
    return (0);
}
t_move	*init_move(void)
{
	t_move	*move;

	move = (t_move *)malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	move->npc = NULL;
	move->mlx = NULL;
	move->window = NULL;
	move->floor = NULL;
	move->width = 0;
	move->height = 0;
	move->x = 0;
	move->y = 0;
	return (move);
}
t_npc  *init_npc(t_move*move) 
{
	t_npc *npc;

	npc = (t_npc *)malloc(sizeof(t_npc));
	if (!npc)
		return (NULL);

    npc->front = mlx_xpm_file_to_image(move->mlx, "textures/npc/npc.xpm", &move->width, &move->height);
    npc->frontmv = mlx_xpm_file_to_image(move->mlx, "textures/npc/npcmv.xpm", &move->width, &move->height);
    npc->left = mlx_xpm_file_to_image(move->mlx, "textures/npc/npcleft.xpm", &move->width, &move->height);
    npc->leftmv = mlx_xpm_file_to_image(move->mlx, "textures/npc/npcleftmv.xpm", &move->width, &move->height);
    npc->right = mlx_xpm_file_to_image(move->mlx, "textures/npc/npcright.xpm", &move->width, &move->height);
    npc->rightmv = mlx_xpm_file_to_image(move->mlx, "textures/npc/npcrightmv.xpm", &move->width, &move->height);
    npc->back = mlx_xpm_file_to_image(move->mlx, "textures/npc/npcback.xpm", &move->width, &move->height);
    npc->backmv = mlx_xpm_file_to_image(move->mlx, "textures/npc/npcbackmv.xpm", &move->width, &move->height);
	return (npc);
}
int	main(void)
{
	t_move *move;
	t_npc 	*npc;
	
	// init
	move = init_move();
	move->mlx = mlx_init();
	move->window = mlx_new_window(move->mlx, 1000, 600, "ventana");
	move->floor = mlx_xpm_file_to_image(move->mlx, "textures/floor.xpm", &move->width, &move->height);
	npc = init_npc(move);
	move->npc = npc;
	// fin init

	// functions
	mlx_hook(move->window, 2, 1L << 0, move_img, move);
	mlx_loop(move->mlx);
	return (0);
}