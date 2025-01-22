#include "so_long.h"
static int    compara(char *str1, char *str2)
{
    int i;

    i = 0;
    if(ft_strlen(str1) != ft_strlen(str2))
    	return(0);
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            return(0);
		i++;
    }
    return(1);
}

static int	put_error(int check, char *str, char *error, char *mensaje)
{
	if(str[0] != '\0')
	{
		if((check = compara(str, error)) == 1)
			ft_printf("Error: %s\n", mensaje);
	}
	return (check);
}
static void	check_if_ok(int check)
{
	// if(check == 0)
	// {
	// 	ft_printf("Error: No has definido bien el error\n");
	// }
	/*else*/if(check /*!= 1*/)
		ft_printf("Error: No has puesto ningun mensaje para este error\n");
}

void    ft_error(char *str)
{
	int check;
	
	check = 0;
	//error para el file descriptor
	check = put_error(check, str, "fd", "El mapa no se abrio correctamente, revisa que este bien escrito y sea .ber");

	// errores para el npc
	check = put_error(check, str, "mem_npc", "La memoria para asignar las imágenes de los NPC no se asigno correctamente");
	check = put_error(check, str, "npc", "No se han asignado correctamente las imágenes de los NPC");

	// errores para las texturas
	check = put_error(check, str, "mem_obj", "No se ha asignado correctamente la memoria para map info");
	check = put_error(check, str, "texturas", "No se han asignado correctamente las texturas");

	// errores para map
	check = put_error(check, str, "mem_map", "No se asignó correctamente la memoria de map");
	check = put_error(check, str, "m_m_filas", "No se pudo asignar memoria para las filas");
	check = put_error(check, str, "m_m_columnas", "No se pudo asignar memoria para las columnas correctamente");

	check_if_ok(check);

	exit(1);
}
// check = put_error(check, str, "", "");