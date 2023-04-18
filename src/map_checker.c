/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:29:41 by agserran          #+#    #+#             */
/*   Updated: 2023/04/17 17:07:44 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	height(t_map *map, int fd)
{
	char	*lane;
	int		i;

	i = 1;
	lane = get_next_line(fd);
	while (lane)
	{
		free(lane);
		lane = get_next_line(fd);
		i++;
	}
	map->height = i - 1;
	free(lane);
	close(fd);
}

void	len_checker(t_map *map)
{
	int		i;

	i = 0;
	map->wide = ft_strlen(map->matrix[0]);
	while (i < map->height)
	{
		if (map->wide != (int)ft_strlen(map->matrix[i]))
		{
			ft_strerror("THE MAP HAVE TO BE RECTANGULAR.\n");
		}
		i++;
	}
}

void	mapa(int fd, t_map *map)
{
	int		i;
	char	*file;
	char	*line;

	line = get_next_line(fd);
	i = 0;
	file = ft_calloc(1, 1);
	while (line)
	{
		file = ft_strjoin(file, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->matrix = ft_split(file, '\n');
	map->copy = ft_split(file, '\n');
	free(file);
	close(fd);
}

void	side_checker(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map->matrix[y])
	{
		while (map->matrix[y][x])
		{
			if (map->matrix[0][x] != '1'
				|| map->matrix[map->height - 1][x] != '1' )
			{
				ft_strerror("MAP HAVE TO BE CLOSED BY WALLS.\n");
			}
			if (map->matrix[y][map->wide - 1] != '1'
				|| map->matrix[y][0] != '1')
			{
				ft_strerror("MAP HAVE TO BE CLOSED BY WALLS.\n");
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_matrix(char **matrix, t_map *map, char *prueba)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s, %s\n", matrix[i], prueba);
		i++;
	}
}
