#include "so_long.h"

void free_objet(t_objet *objet)
{
    if (objet)
    {
        if (objet->floor)
            free(objet->floor);
        if (objet->wall)
            free(objet->wall);
        if (objet->coin)
            free(objet->coin);
        if (objet->exit)
            free(objet->exit);
        if (objet->player)
            free(objet->player);
        free(objet);
    }
}
void free_map(t_map *map)
{
    int i;

    if (!map || !map->map)
        return;
    for (i = 0; i < map->filas; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
}