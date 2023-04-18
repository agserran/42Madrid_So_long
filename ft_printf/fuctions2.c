/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuctions2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:16:17 by agserran          #+#    #+#             */
/*   Updated: 2022/09/19 18:35:36 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_pointer(void *p)
{
	size_t	n;
	int		len;

	len = 0;
	n = (size_t)p;
	len = write(1, "0x", 2);
	len = len + ft_puthexa(n);
	return (len);
}

int	ft_puthexa(unsigned long int nbr)
{
	char		*base;
	static int	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthexa(nbr / 16);
		nbr = nbr % 16;
	}
	i++;
	ft_putchar(base[nbr]);
	return (i);
}
