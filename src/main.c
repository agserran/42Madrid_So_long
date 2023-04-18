/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:41:53 by agserran          #+#    #+#             */
/*   Updated: 2023/04/17 19:43:26 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	t_map	map;

	if (argc != 2)
		ft_strerror("ONLY ONE ARGUMENT!\n");
	ber_check(argv[1]);
	ft_memset(&map, 0, sizeof(t_map));
	map.ph.mlx = mlx_init();
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		ft_strerror("INVALID ARGUMENT!\n");
	height(&map, fd1);
	mapa(fd2, &map);
	things_check(&map);
	map.ph.wnd = mlx_new_window(map.ph.mlx, map.wide * 64,
			map.height * 64, "juego");
	fill(&map);
	mlx_key_hook (map.ph.wnd, moves, &map);
	mlx_hook(map.ph.wnd, CROSS, 0, ft_destroy, &map.ph);
	mlx_loop(map.ph.mlx);
	return (0);
}
