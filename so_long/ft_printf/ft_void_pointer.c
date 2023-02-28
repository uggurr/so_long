/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:00:26 by uguyildi          #+#    #+#             */
/*   Updated: 2022/10/31 15:00:30 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_void_pointer(unsigned long nbr, int *i)
{
	char	*a;

	a = "0123456789abcdef";
	if (nbr < 16)
		*i += ft_putchar(a[nbr % 16]);
	if (nbr >= 16)
	{
		ft_void_pointer(nbr / 16, i);
		ft_void_pointer(nbr % 16, i);
	}
	return (*i);
}
