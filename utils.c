/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:52:24 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/07 14:00:14 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy_free(char *str)
{
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * len);
	if (new == NULL)
		the_error("esta en utils el error");
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}
