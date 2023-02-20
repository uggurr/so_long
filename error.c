/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:52:07 by uguyildi          #+#    #+#             */
/*   Updated: 2023/02/20 17:52:11 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_map *heap)
{
	free(heap->path->visited);
	free(heap->path->matrix);
	free(heap->path);
	free(heap->map_line);
	free(heap->img);
	free(heap->map);
	free(heap->object);
	free(heap);
}

int	close_game(t_map *heap)
{
	int	i;

	i = 0;
	mlx_destroy_image(heap->img->mlx, heap->img->coin);
	mlx_destroy_image(heap->img->mlx, heap->img->exit);
	mlx_destroy_image(heap->img->mlx, heap->img->graund);
	mlx_destroy_image(heap->img->mlx, heap->img->player);
	mlx_destroy_image(heap->img->mlx, heap->img->wall);
	while (heap->map[i])
	{
		free(heap->map[i]);
		free(heap->path->visited[i]);
		free(heap->path->matrix[i]);
		i++;
	}
	mlx_destroy_window(heap->img->mlx, heap->img->mlx_win);
	free_all(heap);
	exit(0);
}

void	ft_error(t_map *heap)
{
	int	i;

	i = 0;
	while (heap->map[i])
	{
		free(heap->map[i]);
		free(heap->path->visited[i]);
		free(heap->path->matrix[i]);
		i++;
	}
	free_all(heap);
	ft_printf("Error");
	exit(0);
}
