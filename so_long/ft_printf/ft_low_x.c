/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:57:36 by uguyildi          #+#    #+#             */
/*   Updated: 2022/10/31 14:57:40 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_low_x(unsigned int nbr, int *i)
{
	char	*a;

	a = "0123456789abcdef";
	if (nbr < 16)
		*i += ft_putchar(a[nbr % 16]);
	if (nbr >= 16)
	{
		ft_low_x(nbr / 16, i);
		ft_low_x(nbr % 16, i);
	}
	return (*i);
}
