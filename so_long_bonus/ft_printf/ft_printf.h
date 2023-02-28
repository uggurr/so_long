/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:00:47 by uguyildi          #+#    #+#             */
/*   Updated: 2022/10/31 15:00:49 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr(int nbr, int *i);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_void_pointer(unsigned long nbr, int *i);
int		ft_unsigned(unsigned int nbr, int *i);
int		ft_low_x(unsigned int nbr, int *i);
void	ft_upp_x(unsigned int nbr, int *i);

#endif
