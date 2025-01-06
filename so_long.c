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
char    **crate_memory_for_matriz(int columnas, int filas)
{
    char    **map;
    int     i;

    map = (char **)malloc(sizeof(char *) * filas);
    if (map == NULL)
    {
        ft_printf("no se asigno memoria para filas");
        exit(-1);
    }

    i = 0;
    while (i < filas)
    {
        map[i] = (char *)malloc(sizeof(char) * (columnas + 1));
        if(map[i] == NULL)
        {
            ft_printf("no se asigno memoria para columnas");
            exit(-1);
        }
        i++;
    }
    return (map);
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



int     main(int ac, char **av)
{
    int fd;
    int columnas;
    int filas;
    char   **mapa;

    fd = open("map/map1.ber", O_RDONLY);
    if(fd <= 0)
    {
        ft_printf("el mapa no se abrio correctamente");
        return (0);
    }
    columnas = 0;
    filas = 0;
    count_map(fd, &columnas, &filas);

    ft_printf(" numero filas: %i\n numero columnas: %i\n", filas, columnas);

    mapa = crate_memory_for_matriz(columnas, filas);
    write_matriz(mapa, columnas, filas, fd);

    return (0);
}