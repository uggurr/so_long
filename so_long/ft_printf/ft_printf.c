/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:57:06 by uguyildi          #+#    #+#             */
/*   Updated: 2022/10/31 14:57:18 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_word_check(va_list ag, const char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ag, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ag, char *));
	else if (c == 'p')
	{
		i += write(1, "0x", 2);
		ft_void_pointer(va_arg(ag, unsigned long), &i);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ag, int), &i);
	else if (c == 'u')
		ft_unsigned(va_arg(ag, unsigned int), &i);
	else if (c == 'x')
		ft_low_x(va_arg(ag, unsigned int), &i);
	else if (c == 'X')
		ft_upp_x(va_arg(ag, unsigned int), &i);
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	ag;
	int		i;
	int		len;

	va_start (ag, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i])
		{
			i++;
			len += ft_word_check(ag, s[i]);
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(ag);
	return (len);
}
