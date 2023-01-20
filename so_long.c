#include "so_long.h"

char	*get_map(char *str)
{
	char	*map;
	char	*get_line;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	map = NULL;
	get_line = NULL;
	i = 0;
	while (get_line != NULL || i == 0)
	{
		get_line = get_next_line(fd);
		if (get_line != NULL)
			map = ft_gnl_strjoin(map, get_line);
		i++;
	}
	return (map);
}

int	main(int ag, char **av)
{
	t_map	*heap;

	if (ag == 2)
	{
		heap = malloc(sizeof(t_map));
		heap->map_line = get_map(av[1]);
		printf("%s\n", heap->map_line); //silinecek
		heap->map = ft_split(heap->map_line, '\n');
		//int i = 0;
		//while(heap->map[i] != NULL)
		//	printf("%s\n",heap->map[i++]);
		wall_check(heap);
	}
	else
		return (0);
}
