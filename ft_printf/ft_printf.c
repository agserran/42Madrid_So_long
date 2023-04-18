/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:43:31 by agserran          #+#    #+#             */
/*   Updated: 2022/09/19 17:30:50 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	get_type(va_list arguments, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i = i + ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		i = i + ft_putstr(va_arg(arguments, char *));
	else if (format == 'p')
		i = i + ft_pointer(va_arg(arguments, void *));
	else if (format == 'X')
		i = i + ft_putnbr_base(va_arg(arguments, int), "0123456789ABCDEF");
	else if (format == 'i' || format == 'd')
		i = i + ft_putnbr(va_arg(arguments, int));
	else if (format == 'x')
		i = i + ft_putnbr_base(va_arg(arguments, int), "0123456789abcdef");
	else if (format == '%')
		i = ft_putchar('%');
	else if (format == 'u')
		i = i + ft_putnbr_base(va_arg(arguments, int), "0123456789");
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(arguments, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += get_type(arguments, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arguments);
	return (len);
}
