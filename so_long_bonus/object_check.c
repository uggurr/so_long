/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:53:25 by uguyildi          #+#    #+#             */
/*   Updated: 2023/02/20 17:53:27 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_object_check(t_map *heap)
{
	int	i;

	i = 0;
	while (heap->map_line[i])
	{
		if (heap->map_line[i] != 'P'
			&& heap->map_line[i] != 'C'
			&& heap->map_line[i] != 'E'
			&& heap->map_line[i] != '1'
			&& heap->map_line[i] != '0'
			&& heap->map_line[i] != 'D'
			&& heap->map_line[i] != '\n')
		{
			ft_printf("undefined character\n");
			ft_error(heap);
		}
		i++;
	}
}

void	player_check(t_map *heap)
{
	int	i;
	int	j;

	i = 0;
	heap->object->p_count = 0;
	while (heap->map[i])
	{
		j = 0;
		while (heap->map[i][j] != '\0')
		{
			if (heap->map[i][j] == 'P')
			{
				heap->img->p_x = i;
				heap->img->p_y = j;
				heap->object->p_count += 1;
			}
			j++;
		}
		i++;
	}
}

void	coin_check(t_map *heap)
{
	int	i;
	int	j;

	i = 0;
	heap->object->c_count = 0;
	while (heap->map[i])
	{
		j = 0;
		while (heap->map[i][j] != '\0')
		{
			if (heap->map[i][j] == 'C')
				heap->object->c_count += 1;
			j++;
		}
		i++;
	}
	if (heap->object->c_count < 1)
	{
		ft_printf("There is no coin\n");
		ft_error(heap);
	}
}

void	exit_check(t_map *heap)
{
	int	i;
	int	j;

	i = 0;
	while (heap->map[i])
	{
		j = 0;
		while (heap->map[i][j] != '\0')
		{
			if (heap->map[i][j] == 'E')
				heap->object->e_count += 1;
			j++;
		}
		i++;
	}
	if (heap->object->e_count == 0)
	{
		ft_printf("There is no Exit\n");
		ft_error(heap);
	}
	if (heap->object->e_count > 1)
	{
		ft_printf("Multiple Exits\n");
		ft_error(heap);
	}
}

void	object_check(t_map *heap)
{
	all_object_check(heap);
	player_check(heap);
	if (heap->object->p_count == 0)
	{
		ft_printf("There is no player\n");
		ft_error(heap);
	}
	if (heap->object->p_count > 1)
	{
		ft_printf("multiple players\n");
		ft_error(heap);
	}
	coin_check(heap);
	exit_check(heap);
}
