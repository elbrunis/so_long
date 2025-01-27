#include "map_info.h"
// IMPORTANTE
static t_map_info *init_map_info()
{
    t_map_info *map_info;

    map_info = (t_map_info*)malloc(sizeof(t_map_info));

    if (map_info == NULL) 
        return (NULL);
    map_info->c = 0;
    map_info->n_coins = 0;
    map_info->n_player = 0;
    map_info->n_exit = 0;

    map_info->start_pos = (t_position *)malloc(sizeof(t_position));
    map_info->finish_pos = (t_position *)malloc(sizeof(t_position));

    if (map_info->start_pos == NULL || map_info->finish_pos == NULL) 
    {
        printf("Error al asignar memoria para las posiciones");
        exit(1);
    }

    map_info->start_pos->x = 0;
    map_info->start_pos->y = 0;
    map_info->finish_pos->x = 0;
    map_info->finish_pos->y = 0;
    return(map_info);
}
// IMPORTANTE





t_map *init_(void)
{
    t_map *map;

    map = (t_map*)malloc(sizeof(t_map));
    if(map == NULL)
    {
        printf("no se pudo asignar memoria para t_map");
        return(0);
    }

    map->map_info = init_map_info();

    return(map);
}