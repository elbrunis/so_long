
#include "cheq.h"

static int	check_map(char *str, int *columnas, int filas)
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
                return (1); // si la primera fila no es toda pared retorna 1
            i++;
        }
		*columnas = i; // guarda la longitud de la primera fila
        return (0); 
    }
	else if (*columnas != (temp = strlen(str)))
		return (1);
    // verifica que los caracteres sean validos
    i = 0;    
    while (i < *columnas && str[i] != '\0') 
	{
		if (str[i] != WALL && str[i] != FLOOR && str[i] != COINS
			&& str[i] != PLAYER && str[i] != EXIT)
			return (1);
		i++;
	}
    // verifica que la primera y ultima columna sean todas paredes
    if(str[1] != WALL && str[*columnas - 1] != WALL)
        return (1);

	return (0);
}

static void	count_map(int fd, int *columnas, int *filas)
{
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{   
        char *newline_pos = strchr(line, '\n');
        if (newline_pos != NULL)
            *newline_pos = '\0';
        if(check_map(line, columnas, *filas) == 1)
        {
            printf("%s\n", line);
            printf("%d\n", *filas);
            printf("Error\n");
            return;
        }
        (*filas)++;
		free(line);
	}
}

int main(void)
{
    int fd;
    int columnas;
    int filas;

    columnas = 0;
    filas = 0;
    fd = open("mapa1.ber", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    count_map(fd, &columnas, &filas);

    close(fd);

    return 0;
}
