#include "so_long.h"

void	ft_path_put(t_map *heap,int result)
{
	static int	k;

	if (result)
	{
		k++;
		printf ("[%d] ", k);
		printf("kontrol aşamaları ... Başarılı\n");
	}
	else
	{
		printf("[X] Hatalı harita ");
		printf("coinler toplanamıyor ya da çıkışa erişilemiyor\n");
		ft_error(heap);
	}
}

int	ft_safe(int y, int j, t_path *path)
{
	if (y >= 0 && y < path->mat_y && j >= 0 && j < path->mat_x)
		return (1);
	return (0);
}

int	ft_path(int y, int x, t_path *path)
{
	if (ft_safe(y, x, path) && path->matrix[y][x] != '1'
		&& path->visited[y][x] != '1')
	{
		path->visited[y][x] = '1';
		if (path->matrix[y][x] == 'F')
			return (1);
		if (ft_path(y - 1, x, path))
			return (1);
		if (ft_path(y, x - 1, path))
			return (1);
		if (ft_path(y + 1, x, path))
			return (1);
		if (ft_path(y, x + 1, path))
			return (1);
	}
	return (0);
}

void	ft_visited_clear(t_path *path)
{
	int	i;
	int	j;

	i = -1;
	while (++i < path->mat_y)
	{
		j = -1;
		while (++j < path->mat_x)
		{
			path->visited[i][j] = '0';
		}
	}
}

void	ft_path_find(t_map *heap)
{
	int	result;
	int	i;
	int	j;

	ft_visited_clear(heap->path);
	result = 0;
	i = -1;
	while (++i < heap->path->mat_y)
	{
		j = -1;
		while (++j < heap->path->mat_x)
		{
			if (heap->path->matrix[i][j] == 'P' && heap->path->visited[i][j] != '1')
			{
				
				if (ft_path(i, j, heap->path))
				{
					result = 1;
					break ;
				}
			}
		}
	}
	ft_path_put(heap, result);
}
