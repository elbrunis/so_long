/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:22:49 by biniesta          #+#    #+#             */
/*   Updated: 2025/04/04 13:01:33 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != WALL)
			the_error("la primera fila tiene un caracter que no es muro");
		i++;
	}
	return (i);
}

int	check_last_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != WALL)
			the_error("error en la ultima columna, hay un caracter no valido");
		i++;
	}
	return (0);
}
 