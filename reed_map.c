# include "so_long.h"
// contamos filas y columnas para guardar el alto y el ancho de el mapa
// ESTA FUNCION HAY QUE ACTUALIZARLA Y HACERLA MUCHO MEJOR
static void    count_map(int fd, int *columnas, int *filas)
{
    char    *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        (*filas)++;
        *columnas = ft_strlen(line);
        free(line);
    }
}
// creamos matriz para guardar el mapa
static void	crate_memory_for_matriz(t_map *map)
{
    int     i;

    map->map = (char **)malloc(sizeof(char *) * map->filas);
    if (map->map == NULL)
        ft_error("m_m_filas");

    i = 0;
    while (i < map->filas)
    {
        map->map[i] = (char *)malloc(sizeof(char) * (map->columnas + 1));
        if(map->map[i] == NULL)
            ft_error("m_m_columnas");
        i++;
    }
}

static void    write_matriz(t_map *map)
{
    char    *temp;
    int     x;// Fila
    int     y;// Columna

    x = 0;
    lseek(map->fd, 0, SEEK_SET);
    while((temp = get_next_line(map->fd)) != NULL && x < map->filas)
    {
        y = 0;
        while(temp[y] != '\0' && y < map->columnas)
        {
            map->map[x][y] = temp[y];
            ft_printf("%c", map->map[x][y]);
            y++;
        }
        map->map[x][y] = '\0';
        ft_printf("\n");
        free(temp);
        x++;
    }
}

t_map	*create_map_with_info(t_map *map)
{
    count_map(map->fd, &map->columnas, &map->filas);

	crate_memory_for_matriz(map);
    write_matriz(map);
    return (map);
}

