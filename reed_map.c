# include "so_long.h"
// contamos filas y columnas para guardar el alto y el ancho de el mapa
void    count_map(int fd, int *columnas, int *filas)
{
    char    *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        *filas = *filas + 1;
        *columnas = ft_strlen(line);
        free(line);
    }
}
// creamos matriz para guardar el mapa
void	crate_memory_for_matriz(t_map *map)
{
    int     i;

    map->map = (char **)malloc(sizeof(char *) * map->filas);
    if (map->map == NULL)
    {
        ft_printf("no se asigno memoria para filas");
        exit(-1);
    }

    i = 0;
    while (i < map->filas)
    {
        map->map[i] = (char *)malloc(sizeof(char) * (map->columnas + 1));
        if(map->map[i] == NULL)
        {
            ft_printf("no se asigno memoria para columnas");
            exit(-1);
        }
        i++;
    }
}

void    write_matriz(char **map, int columnas, int filas, int fd)
{
    char    *temp;
    int     x;// Fila
    int     y;// Columna

    x = 0;
    lseek(fd, 0, SEEK_SET);

    while((temp = get_next_line(fd)) != NULL)
    {
        y = 0;
        while(temp[y] != '\0')
        {
            map[x][y] = temp[y];
            ft_printf("%c", map[x][y]);
            y++;
        }
        map[x][y] = '\0';
        free(temp);
        x++;
    }
    ft_printf("\n");
}

t_map	*init_t_map(void)
{
	t_map	*map;
	map = (t_map *)malloc(sizeof(t_map));
	if(!map)
	{
		ft_printf("no se ha asignado correctamente map");
		exit(-1);
	}
	map->mlx = NULL;
	map->window = NULL;
	map->map = NULL;
	map->filas = 0;
	map->columnas = 0;
    map->n = '\0';
    map->img = NULL;
    map->pos.x = 0;
    map->pos.y = 0;
	return (map);
}

t_map	*return_map(int fd)
{
	t_map *map;

	map = init_t_map();
    count_map(fd, &map->columnas, &map->filas);

	crate_memory_for_matriz(map);

    write_matriz( map->map, map->columnas, map->filas, fd);
    return (map);
}

