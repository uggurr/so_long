/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:59:04 by uguyildi          #+#    #+#             */
/*   Updated: 2022/10/31 14:59:06 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int nbr, int *i)
{
	if (nbr <= 9 && nbr >= 0)
		*i += ft_putchar(nbr + '0');
	if (nbr > 9)
	{
		ft_unsigned(nbr / 10, i);
		ft_unsigned(nbr % 10, i);
	}
	return (*i);
}
