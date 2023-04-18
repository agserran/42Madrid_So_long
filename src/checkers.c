/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:54:59 by agserran          #+#    #+#             */
/*   Updated: 2023/04/17 20:05:28 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	things_check(t_map *map)
{
	map_parser(map);
	len_checker(map);
	side_checker(map);
	itemsmax(map);
	positions(map);
	last_check(map);
}

void	ber_check(char *argv)
{
	int	max;

	max = ft_strlen(argv);
	if (argv[max - 1] != 'r' || argv[max - 2] != 'e'
		|| argv[max - 3] != 'b' || argv[max - 4] != '.')
		ft_strerror("INVALID MAP FORMAT, ONLY .BER IS VALID.\n");
}
