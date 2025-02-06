#include "so_long.h"


// void ft_algoritmo(t_map_info *map_info, int x, int y, int *i, char *dir)
// {
//     if(x < 0 || y < 0 || x >= ALTO || y >= ANCHO)
//         return;
//     if(map_info->n_coins == 0)
//         return;
//     if (map_info->map[x][y] == WALL || map_info->check[x][y] != 0)
//     {
//         printf("pared x: %d,  y: %d %s\n", x, y,dir);
//         return;
//     }
//     if(map_info->map[x][y] == FLOOR || map_info->check[x][y] == 0)
//     {
//         printf("SUELO X: %d, Y: %d %s\n", x, y, dir);
//         map_info->check[x][y] = 1;

//         if(map_info->map[x][y] == COINS || map_info->map[x][y] == EXIT)
//         {
//             map_info->n_coins--;
//             printf("encontro monedas o salida: %d\n", map_info->n_coins);
//         }

//         if(map_info->map[x][y] == EXIT)
//         {
//             *i = 1;
//             printf("llego a la salida y escribio en i%d\n", *i);
//         }
//         check_map(map_info, x + 1,   y, i, "abajo"); //abajo
//         check_map(map_info, x,       y + 1, i, "derecha"); //derecha
//         check_map(map_info, x ,      y - 1, i, "izquierda"); //izquierda
//         check_map(map_info, x - 1,   y, i, "arriba"); //arriba
//     }
// }

int	check_map(char *str, int *columnas, int filas)
{
    int temp;
    int i;

    temp = 0;
    i = 0;
    // verifica que la primera fila sea toda pared y que la longitud sea igual a la longitud de las demas filas
    if (filas == 0)
    {
        while (str[i] != '\0') // se le pone -1 para que no cuente el salto de linea
        {
            if(str[i] != WALL)
                the_error("la primera fila tiene un caracter que no es muro"); //aqui va un error
            i++;
        }
		*columnas = i; // guarda la longitud de la primera fila
        return (0); 
    }
	else if (*columnas != (temp = strlen(str)))
		the_error("las filas no miden lo mismo"); //aqui va un error
    // verifica que los caracteres sean validos
    i = 0;    
    while (i < *columnas && str[i] != '\0') 
	{
		if (str[i] != WALL && str[i] != FLOOR && str[i] != COINS
			&& str[i] != PLAYER && str[i] != EXIT)
			the_error("hay un caracter invalido"); // aqui va un error
		i++;
	}
    // verifica que la primera y ultima columna sean todas paredes
    if(str[1] != WALL && str[*columnas - 1] != WALL)
        the_error("el mapa no esta rodeado por muros"); //aqui va un error
    return (0);
}