/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:51:31 by uguyildi          #+#    #+#             */
/*   Updated: 2023/02/20 17:51:36 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_animation(int pos_player, t_map *heap)
{
	if (pos_player == 1)
		heap->img->coin = mlx_xpm_file_to_image(heap->img->mlx, C,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 2)
		heap->img->coin = mlx_xpm_file_to_image(heap->img->mlx, C1,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 3)
		heap->img->coin = mlx_xpm_file_to_image(heap->img->mlx, C2,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 4)
		heap->img->coin = mlx_xpm_file_to_image(heap->img->mlx, C3,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 5)
		heap->img->coin = mlx_xpm_file_to_image(heap->img->mlx, C4,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 6)
		heap->img->coin = mlx_xpm_file_to_image(heap->img->mlx, C5,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 7)
		heap->img->coin = mlx_xpm_file_to_image(heap->img->mlx, C6,
				&heap->img->x, &heap->img->y);
}

void	enemy_animation(int pos_player, t_map *heap)
{
	if (pos_player == 1)
		heap->img->enemy = mlx_xpm_file_to_image(heap->img->mlx, D,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 2)
		heap->img->enemy = mlx_xpm_file_to_image(heap->img->mlx, D1,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 3)
		heap->img->enemy = mlx_xpm_file_to_image(heap->img->mlx, D2,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 4)
		heap->img->enemy = mlx_xpm_file_to_image(heap->img->mlx, D3,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 5)
		heap->img->enemy = mlx_xpm_file_to_image(heap->img->mlx, D4,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 6)
		heap->img->enemy = mlx_xpm_file_to_image(heap->img->mlx, D5,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 7)
		heap->img->enemy = mlx_xpm_file_to_image(heap->img->mlx, D6,
				&heap->img->x, &heap->img->y);
}

void	exit_animation(int pos_player, t_map *heap)
{
	if (pos_player == 1)
		heap->img->exit = mlx_xpm_file_to_image(heap->img->mlx, E,
				&heap->img->x, &heap->img->y);
	else if (pos_player == 2)
		heap->img->exit = mlx_xpm_file_to_image(heap->img->mlx, E1,
				&heap->img->x, &heap->img->y);
}

int	loop_img(t_map *heap)
{
	static int	pos_player;
	static int	loop;

	if (loop < 1500)
	{
		loop++;
		return (0);
	}
	coin_animation(pos_player, heap);
	enemy_animation(pos_player, heap);
	exit_animation(pos_player, heap);
	ft_img_idx(heap);
	if (pos_player == 7)
		pos_player = 0;
	pos_player++;
	loop = 0;
	return (0);
}
