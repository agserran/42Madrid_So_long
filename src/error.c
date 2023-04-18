/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:40:42 by agserran          #+#    #+#             */
/*   Updated: 2023/04/17 19:48:02 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_strerror(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	ft_destroy(void)
{
	exit(0);
	return (0);
}

void	map_parser(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->matrix[y])
	{
		x = 0;
		while (map->matrix[y][x])
		{
			if (map->matrix[y][x] != '0' && map->matrix[y][x] != 'E'
				&& map->matrix[y][x] != 'C' && map->matrix[y][x] != '1'
				&& map->matrix[y][x] != 'P')
				ft_strerror("INVALID MAP.\n");
			x++;
		}
		y++;
	}
}
