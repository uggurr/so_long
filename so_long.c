#include "so_long.h"

char	*get_map(char *str)
{
	char	*map;
	char	*get_line;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("file not found"); //ft_printf ile değiştir.
		close(fd);
		exit(0);
	}
	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i - 3] != '.')
	{
		printf(".ber File Not Found!"); //ft_printf ile değiştir
		exit(0);
	}
	map = NULL;
	get_line = NULL;
	i = 0;
	while (get_line != NULL || i == 0)
	{
		get_line = get_next_line(fd);
		if (get_line != NULL)
			map = ft_gnl_strjoin(map, get_line);
		free(get_line);
		i++;
	}
	return (map);
	map_opened_check();
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
		heap->map = ft_split(heap->map_line, '\n');
		heap->path->matrix = ft_split(heap->map_line, '\n');
		heap->path->visited = ft_split(heap->map_line, '\n');
		wall_check(heap);
		object_check(heap);
		accessible_check(heap);
		get_image(heap);
	}
	else
		return (0);
}
