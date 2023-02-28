/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:58:16 by uguyildi          #+#    #+#             */
/*   Updated: 2022/10/31 14:58:20 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr, int *i)
{
	if (nbr == -2147483648)
	{
		*i += ft_putchar('-');
		nbr = nbr / 10;
		ft_putnbr(-nbr, i);
		*i += ft_putchar('8');
	}
	else if (nbr < 0)
	{
		*i += ft_putchar('-');
		ft_putnbr(-nbr, i);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr(nbr / 10, i);
		*i += ft_putchar('0' + (nbr % 10));
	}
	return (*i);
}
