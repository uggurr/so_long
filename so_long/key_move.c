/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:53:07 by uguyildi          #+#    #+#             */
/*   Updated: 2023/02/20 17:53:09 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_score(int point, t_map *heap)
{
	char	*score;

	score = ft_itoa(point);
	mlx_string_put(heap->img->mlx, heap->img->mlx_win,
		20, 20, 0x00FFFFFF, score);
	free(score);
}

void	value_swap(t_map *heap, int x, int y)
{
	heap->map[heap->img->p_x][heap->img->p_y] = '0';
	heap->map[x][y] = 'P';
	heap->img->p_x = x;
	heap->img->p_y = y;
}

void	move(t_map *heap, int x, int y)
{
	if (!heap->object->c_count && heap->map[x][y] == 'E')
	{
		value_swap(heap, x, y);
		ft_printf("Walk:%d\nWin!", heap->img->point += 1);
		close_game(heap);
	}
	if (heap->map[x][y] != '1' && heap->map[x][y] != 'E')
	{
		if (heap->map[x][y] == 'C')
			heap->object->c_count -= 1;
		value_swap(heap, x, y);
		ft_printf("Walk:%d\n", heap->img->point += 1);
	}
}

int	key_move(int keycode, t_map *heap)
{
	mlx_clear_window(heap->img->mlx, heap->img->mlx_win);
	if (keycode == 13)
		move(heap, heap->img->p_x - 1, heap->img->p_y);
	else if (keycode == 0)
		move(heap, heap->img->p_x, heap->img->p_y - 1);
	else if (keycode == 1)
		move(heap, heap->img->p_x + 1, heap->img->p_y);
	else if (keycode == 2)
		move(heap, heap->img->p_x, heap->img->p_y + 1);
	else if (keycode == 53)
		close_game(heap);
	ft_img_idx(heap);
	return (keycode);
}
