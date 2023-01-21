#include "so_long.h"

void	first_line_check(t_map *heap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (heap->map[i][j] != '\0')
	{
		if (heap->map[i][j] != '1')
			ft_error(heap);
		j++;
	}
	heap->width = j;
}

void	column_check(t_map *heap)
{
	int	i;
	int	j;

	i = 0;
	while (heap->map[i])
	{
		if (heap->map[i][0] != '1')
			ft_error(heap);
		j = 0;
		while (heap->map[i][j] != '\0')
		{
			if (heap->map[i][heap->width - 1] != '1')
				ft_error(heap);
			j++;
		}
		if (heap->width != j)
			ft_error(heap);
		i++;
	}
	heap->height = i;
}

void	last_line_check(t_map *heap)
{
	int	j;

	j = 0;
	while (heap->map[heap->height -1][j] != '\0')
	{
		if (heap->map[heap->height - 1][j] != '1')
			ft_error(heap);
		j++;
	}
}

void	line_check(t_map *heap)
{
	int	i;

	i = 0;
	while (heap->map_line[i])
	{
		if (heap->map_line[i] == '\n' && heap->map_line[i + 1] == '\n')
			ft_error(heap);
		i++;
	}
}

void	wall_check(t_map *heap)
{
	first_line_check(heap);
	column_check(heap);
	last_line_check(heap);
	line_check(heap);
}
