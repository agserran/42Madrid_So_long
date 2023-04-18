/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:47:13 by agserran          #+#    #+#             */
/*   Updated: 2023/04/17 17:29:36 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_putchar(int c);
int			ft_strlen(char	*str);
int			ft_putstr(char	*str);
int			ft_putnbr(int nb);
int			ft_putnbr_base(int nb, char *b);
static int	type(va_list arguments, char format);
int			ft_pointer(void *p);

#endif
