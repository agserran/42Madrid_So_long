/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agserran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:47:13 by agserran          #+#    #+#             */
/*   Updated: 2023/04/17 17:29:26 by agserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int						ft_putchar(int c);
unsigned int			ft_strlen_2(char	*str);
int						ft_putstr(char	*str);
int						ft_putnbr(int nb);
int						ft_putnbr_base(unsigned int nb, char *b);
int						ft_pointer(void *p);
int						ft_printf(const char *str, ...);
int						ft_puthexa(unsigned long int nbr);

#endif
