/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:39:18 by agserran          #+#    #+#             */
/*   Updated: 2023/04/17 19:48:49 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>

# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define FONDO  "./sprites/fondo.xpm"
# define FLOOR  "./sprites/swamp.xpm"
# define CHARACTER  "./sprites/character.xpm"
# define FOOD  "./sprites/seerdo.xpm"
# define DOOR  "./sprites/door.xpm"
# define CROSS 17

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_collectables
{
	int	x;
	int	y;
}	t_collectables;

typedef struct s_exit
{
	int	x;
	int	y;
}	t_exit;

typedef struct img
{
	void	*wall;
	void	*floor;
	void	*food;
	void	*exit;
	void	*character;
	int		y;
	int		x;
	void	*mlx;
	void	*wnd;
}	t_img;

typedef struct s_copy
{
	int	exits;
	int	player;
	int	collect;
}	t_copy;

typedef struct s_map
{
	int				height;
	int				wide;
	char			**matrix;
	char			**copy;
	int				exits;
	int				player;
	int				collect;
	t_player		p;
	t_exit			e;
	t_collectables	c;
	t_copy			co;
	t_img			ph;
}	t_map;

void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *stash, char *buffer);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**checker(char **str);
char	**ft_split(char const *s, char c);
void	ft_putstr_error(char	*s);
void	side_checker(t_map *map);
void	mapa(int fd, t_map *map);
void	len_checker(t_map *map);
void	height(t_map *map, int fd);
void	ichecker(t_map *map);
void	ichecker_copy(t_map *map);
void	*ft_memset(void *s, int c, size_t n);
void	ft_strerror(char *str);
void	itemsmax(t_map *map);
void	map_parser(t_map *map);
void	ber_check(char *argv);

void	reachercheck(t_map *map, int y, int x);
void	last_check(t_map *map);
void	positions(t_map *map);
void	things_check(t_map *map);
void	print_matrix(char **matrix, t_map *map, char *prueba);

# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2
# define UP			126
# define LEFT		123
# define DOWN		125
# define RIGHT		124

void	win(void);
int		moves(int key, t_map *map);
void	up(t_map *map);
void	down(t_map *map);
void	right(t_map *map);
void	left(t_map *map);

int		fill(t_map *map);
void	images(t_map *map);
void	choose(t_map *map, int y, int x);
int		ft_destroy(void);

#endif
