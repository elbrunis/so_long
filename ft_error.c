/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:01:28 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/07 14:02:21 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	the_error(char *str, t_map *map)
{
	if (map)
		free_game(map);
	ft_printf("Error\n%s\n", str);
	exit(1);
}
