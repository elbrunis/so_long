#include "so_long.h"

int     main(int ac, char **av)
{
    int     fd;

    fd = open("map/map2.ber", O_RDONLY);
    if(fd <= 0)
    {
        ft_printf("el mapa no se abrio correctamente");
        return (0);
    }
    init_mlx(fd);
    return (0);
}
