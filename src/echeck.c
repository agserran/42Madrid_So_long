/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echeck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:40:37 by agserran          #+#    #+#             */
/*   Updated: 2023/04/17 17:05:32 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ichecker(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->wide)
		{
			if (map->matrix[y][x] == 'P')
					map->player++;
			if (map->matrix[y][x] == 'C')
					map->collect++;
			if (map->matrix[y][x] == 'E')
					map->exits++;
			x++;
		}
		y++;
	}
}

void	ichecker_copy(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->wide)
		{
			if (map->copy[y][x] == 'P')
				map->co.player++;
			if (map->copy[y][x] == 'C')
				map->co.collect++;
			if (map->copy[y][x] == 'E')
				map->co.exits++;
			x++;
		}
		y++;
	}
}

void	itemsmax(t_map *map)
{
	ichecker(map);
	if ((map->exits != 1) || (map->player != 1))
		ft_putstr_error("THERE HAVE TO BE 1 PLAYER AND 1 EXIT.\n");
	if ((map->collect < 1))
		ft_putstr_error("THERE HAVE TO BE AT LEAST 1 COLLECTABLE.\n");
}

void	reachercheck(t_map *map, int y, int x)
{
	map->copy[y][x] = 'P';
	if (map->copy[y - 1][x] == 'E' || map->copy[y - 1][x] == 'C'
		|| map->copy[y - 1][x] == '0')
		reachercheck(map, y - 1, x);
	if (map->copy[y + 1][x] == 'E' || map->copy[y + 1][x] == 'C'
		|| map->copy[y + 1][x] == '0')
		reachercheck(map, y + 1, x);
	if (map->copy[y][x - 1] == 'E' || map->copy[y][x - 1] == 'C'
		|| map->copy[y][x - 1] == '0')
		reachercheck(map, y, x - 1);
	if (map->copy[y][x + 1] == 'E' || map->copy[y][x + 1] == 'C'
		|| map->copy[y][x + 1] == '0')
		reachercheck(map, y, x + 1);
}

void	last_check(t_map *map)
{
	positions(map);
	reachercheck(map, map->p.y, map->p.x);
	ichecker_copy(map);
	if (map->co.collect != 0 || map->co.exits != 0)
		ft_putstr_error("YOU HAVE TO BE ABLE TO REACH ALL THINGS.\n");
}
