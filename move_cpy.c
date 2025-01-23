# include "so_long.h"

// X->fila   Y->columna
static void	move_npc(t_map *map, int x, int y, void *img1, void *img2)
{
	mlx_put_image_to_window(map->mlx, map->window, map->obj->floor, map->obj->npc->pos->x, map->obj->npc->pos->y); //Se pone aqui para que se haga solamente si se cumple las condiciones de la funcion anterior

    map->obj->npc->pos->x += x;
    map->obj->npc->pos->y += y;
    if (map->obj->npc->i == 1)
    {
        mlx_put_image_to_window(map->mlx, map->window, img2, map->obj->npc->pos->x, map->obj->npc->pos->y);
       map->obj->npc->i = 0;
    }
    else
    {
        mlx_put_image_to_window(map->mlx, map->window, img1, map->obj->npc->pos->x, map->obj->npc->pos->y);
        map->obj->npc->i = 1;
    }
}

static void	move_key(int key, t_map *map)
{
	if (key == ESC)
		mlx_destroy_window(map->mlx, map->window);
    if (key == W || key == UP)
        move_npc(map, 0, -50, map->obj->npc->back, map->obj->npc->backmv);
    if (key == S || key == DOWN)
        move_npc(map, 0, 50, map->obj->npc->front, map->obj->npc->frontmv);
    if (key == D || key == RIGHT)
        move_npc(map, 50, 0, map->obj->npc->right, map->obj->npc->rightmv);
    if (key == A  || key == LEFT)
        move_npc(map, -50, 0, map->obj->npc->left, map->obj->npc->leftmv);
}


int move_img(int keycode, void *param)
{
    t_map  *map;

    map = (t_map *)param;
	move_key(keycode, map);
    return (0);
}

// int	main(void)
// {
// 	mlx_hook(map->window, 2, 1L << 0, move_img, move);
// 	mlx_loop(map->mlx);
// 	return (0);
// }