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
			&& heap->map_line[i] != '\n')
		{
			printf("undefined character\n");  //ft_printf ile değiştir.
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
	while (heap->map[i])
	{
		j = 0;
		while (heap->map[i][j] != '\0')
		{
			if (heap->map[i][j] == 'P')
				heap->object->p_count += 1;
			j++;
		}
		i++;
	}
	if (heap->object->p_count == 0)
	{
		printf("There is no player\n"); //ft_printf ile değiştir.
		ft_error(heap);
	}
	if (heap->object->p_count > 1)
	{
		printf("multiple players\n"); //ft_printf ile değiştir.
		ft_error(heap);
	}
}

void	coin_check(t_map *heap)
{
	int	i;
	int	j;

	i = 0;
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
		printf("There is no coin\n"); //ft_printf ile değiştir.
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
		printf("There is no Exit\n"); //ft_printf ile değiştir.
		ft_error(heap);
	}
	if (heap->object->e_count > 1)
	{
		printf("Multiple Exits\n"); //ft_printf ile değiştir.
		ft_error(heap);
	}
}

void	object_check(t_map *heap)
{
	all_object_check(heap);
	player_check(heap);
	coin_check(heap);
	exit_check(heap);
}
