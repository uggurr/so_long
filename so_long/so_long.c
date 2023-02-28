/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uguyildi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:53:59 by uguyildi          #+#    #+#             */
/*   Updated: 2023/02/20 17:54:03 by uguyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bercheck(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		ft_printf(".ber File Not Found!");
		exit(0);
	}
}

char	*get_map(char *str)
{
	char	*map;
	char	*get_line;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file not found");
		close(fd);
		exit(0);
	}
	map = NULL;
	get_line = NULL;
	i = -1;
	while (get_line != NULL || ++i == 0)
	{
		get_line = get_next_line(fd);
		if (get_line != NULL)
			map = ft_gnl_strjoin(map, get_line);
		free(get_line);
	}
	return (map);
	map_opened_check();
}

void	creat_map(t_map *heap)
{
	heap->map = ft_split(heap->map_line, '\n');
	heap->path->matrix = ft_split(heap->map_line, '\n');
	heap->path->visited = ft_split(heap->map_line, '\n');
}

void	ft_direction(char *str, t_map *heap)
{
	ft_bercheck(str);
	creat_map(heap);
	wall_check(heap);
	object_check(heap);
	accessible_check(heap);
	get_image(heap);
}

int	main(int ag, char **av)
{
	t_map		*heap;
	t_object	*object;
	t_path		*path;
	t_img		*img;

	if (ag == 2)
	{
		heap = malloc(sizeof(t_map));
		object = malloc(sizeof(t_object));
		path = malloc(sizeof(t_path));
		img = malloc(sizeof(t_img));
		heap->object = object;
		heap->path = path;
		heap->img = img;
		heap->map_line = get_map(av[1]);
		if (heap->map_line == NULL)
			ft_error_null_map(heap);
		ft_direction(av[1], heap);
	}
	else
		return (0);
}
