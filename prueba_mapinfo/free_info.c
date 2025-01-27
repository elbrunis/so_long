#include "map_info.h"

static void free_map_info(t_map_info *map_info)
{
    if (map_info == NULL)
        return;
    if (map_info->start_pos != NULL) 
    {
        free(map_info->start_pos);
        map_info->start_pos = NULL;
    }

    if (map_info->finish_pos != NULL) 
    {
        free(map_info->finish_pos);
        map_info->finish_pos = NULL;
    }
    free(map_info);
}

void    free_(t_map *map)
{
    free_map_info(map->map_info);
    free(map);
}