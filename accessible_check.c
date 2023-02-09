#include "so_long.h"

void	map_exit_check(int i, int j, t_map *heap)
{
	heap->path->matrix[i][j] = 'F';
	ft_path_find(heap);
}

void	init_matrix(int exit_i, int exit_j, t_map *heap)
{
	int			i;
	int			j;

	i = -1;
	while (heap->path->matrix[++i])
	{
		j = -1;
		while (heap->path->matrix[i][++j])
		{
			if (heap->path->matrix[i][j] == 'E')
			{
				exit_i = i;
				exit_j = j;
				heap->path->matrix[i][j] = '1';
			}
			if (heap->path->matrix[i][j] == 'C')
			{
				heap->path->matrix[i][j] = 'F';
				ft_path_find(heap);
				heap->path->matrix[i][j] = 'C';
			}
		}
	}
	map_exit_check(exit_i, exit_j, heap);
}

void	accessible_check(t_map *heap)
{
	static int	exit_i;
	static int	exit_j;

	heap->path->mat_y = heap->height;
	heap->path->mat_x = heap->width;
	init_matrix(exit_i, exit_j, heap);
}
