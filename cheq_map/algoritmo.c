# include "cheq.h"

#define ALTO 15
#define ANCHO 15
#define WALL '1'
#define FLOOR '0'
#define COINS 'C'
#define EXIT 'E'

typedef struct s_map_info {
    char map[ALTO][ANCHO];
    int check[ALTO][ANCHO];
    int n_coins;
} t_map_info;

int    **check_map_mem(int filas, int columnas)
{
    int **check_map;
    int i;

    check_map = (int **)malloc(sizeof(int *) * filas);
    i = 0;
    while (i < filas)
        check_map[i++] = (int *)malloc(sizeof(int) * columnas);
    return(check_map);
}

// X->fila   Y->columna
void check_map(t_map_info *map_info, int x, int y, int *i, char *dir)
{
    if(x < 0 || y < 0 || x >= ALTO || y >= ANCHO)
        return;
    if(map_info->n_coins == 0)
        return;
    if (map_info->map[x][y] == WALL || map_info->check[x][y] != 0)
    {
        printf("pared x: %d,  y: %d %s\n", x, y,dir);
        return;
    }
    if(map_info->map[x][y] == FLOOR || map_info->check[x][y] == 0)
    {
        printf("SUELO X: %d, Y: %d %s\n", x, y, dir);
        map_info->check[x][y] = 1;

        if(map_info->map[x][y] == COINS || map_info->map[x][y] == EXIT)
        {
            map_info->n_coins--;
            printf("encontro monedas o salida: %d\n", map_info->n_coins);
        }

        if(map_info->map[x][y] == EXIT)
        {
            *i = 1;
            printf("llego a la salida y escribio en i%d\n", *i);
        }
        check_map(map_info, x + 1,   y, i, "abajo"); //abajo
        check_map(map_info, x,       y + 1, i, "derecha"); //derecha
        check_map(map_info, x ,      y - 1, i, "izquierda"); //izquierda
        check_map(map_info, x - 1,   y, i, "arriba"); //arriba
    }
}

int main()
{
    char map[ALTO][ANCHO] = 
    {
        {'1', '1', '1', '1', '1', '1', '1', 'E', '1', '1', '1', '1', '1', '1', '1'},
        {'1', 'C', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1'},
        {'1', '0', '1', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1', '0', '1'},
        {'1', '0', '1', 'C', '0', '1', '0', '0', '0', '1', 'C', '0', '1', '0', '1'},
        {'1', '0', '1', '1', '0', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '1', '0', '1', '1', '0', '0', '0', '0', '1'},
        {'1', 'C', '1', '1', '1', '0', '1', '0', '0', '1', '1', '1', '1', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'}
    };
    t_map_info map_info;
    for (int i = 0; i < ALTO; i++)
        for (int j = 0; j < ANCHO; j++)
            map_info.map[i][j] = map[i][j];
    map_info.n_coins = 2; // Número de monedas en el mapa

    map_info.check = check_map_mem(ALTO, ANCHO);
    int i;

    i = 0 ;
    check_map(&map_info, 1, 1, &i, "inicio");
    if (i == 1)
        printf("dluxe\n");
    else
        printf("lemao\n");
    printf("numero de monedas despues de terminar el algoritmo: %d\n", map_info.n_coins);
    return(0);
} 