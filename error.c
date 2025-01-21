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

void    ft_error(char *str)
{
	int check;

	check = 0;
    if(str[0] != '\0')
	{
		if((check = compara("fd", str)) == 1)
        	ft_printf("Error: El mapa no se abrio correctamente, revisa que este bien escrito y sea .ber\n");
		if(check == 0)
			ft_printf("Error: No has definido bien el error\n");
	}
	else
		ft_printf("Error: No has puesto ningun mensaje para este error\n");
	exit(1);
}