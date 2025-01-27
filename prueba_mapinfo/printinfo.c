#include "map_info.h"

void print_map_info(t_map_info *info)
{
    if (info == NULL)
    {
        printf("Error: t_map_info is NULL.\n");
        return;
    }

    printf("Character: %c\n", info->c);
    printf("Number of coins: %d\n", info->n_coins);
    printf("Number of players: %d\n", info->n_player);
    printf("Number of exits: %d\n", info->n_exit);

    if (info->start_pos)
    {
        printf("Start position: (%d, %d)\n", info->start_pos->x, info->start_pos->y);
    }
    else
    {
        printf("Start position: NULL\n");
    }

    if (info->finish_pos)
    {
        printf("Finish position: (%d, %d)\n", info->finish_pos->x, info->finish_pos->y);
    }
    else
    {
        printf("Finish position: NULL\n");
    }
}