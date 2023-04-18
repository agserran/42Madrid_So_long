/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuctions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:05:48 by agserran          #+#    #+#             */
/*   Updated: 2022/09/19 18:35:06 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

unsigned int	ft_strlen_2(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char	*str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	write (1, str, ft_strlen_2(str));
	return (ft_strlen_2(str));
}

int	ft_putnbr(int nb)
{
	static int	i;
	long		nbr;

	nbr = nb;
	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	i++;
	ft_putchar(nbr + '0');
	if (nb < 0)
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned int nb, char *b)
{
	static int		i;
	size_t			nbr;

	nbr = (size_t)nb;
	i = 0;
	if (nbr >= ft_strlen_2(b))
	{
		ft_putnbr_base(nbr / ft_strlen_2(b), b);
		nbr = nbr % ft_strlen_2(b);
	}
	i++;
	ft_putchar(b[nbr]);
	return (i);
}
