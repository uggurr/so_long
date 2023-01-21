#include "so_long.h"

void	map_exit_check(int i, int j, t_path *path)
{
	path->matrix[i][j] = 'F';
	ft_path_find(path);
}

void	init_matrix(t_path *path)
{
	static int	exit_i;
	static int	exit_j;
	int			i;
	int			j;

	i = -1;
	while (path->matrix[++i])
	{
		j = -1;
		while (path->matrix[i][++j])
		{
			if (path->matrix[i][j] == 'E')
			{
				exit_i = i;
				exit_j = j;
				path->matrix[i][j] = '1';
			}
			if (path->matrix[i][j] == 'C')
			{
				path->matrix[i][j] = 'F';
				ft_path_find(path);
				path->matrix[i][j] = 'C';
			}
		}
	}
	map_exit_check(exit_i, exit_j, path);
}

void	accessible_check(t_map *heap, t_path *path)
{
	path->mat_y = heap->height;
	path->mat_x = heap->width;
	init_matrix(path);
}
