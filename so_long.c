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
	t_map		*heap;
	t_object	*object;
	t_path		*path;
	t_img		*img;
	//t_temp		*temp;
	if (ag == 2)
	{
		heap = malloc(sizeof(t_map));
		object = malloc(sizeof(t_object));
		path = malloc(sizeof(t_path));
		img = malloc(sizeof(t_img));
		//temp =malloc(sizeof(t_temp));
		heap->object = object;
		heap->path = path;
		heap->img = img;
		heap->map_line = get_map(av[1]);
		printf("%s\n", heap->map_line); //silinecek
		heap->map = ft_split(heap->map_line, '\n');
		path->matrix = ft_split(heap->map_line, '\n');
		path->visited = ft_split(heap->map_line, '\n');
		//int i = 0;
		//while(heap->map[i] != NULL)
		//	printf("%s\n",heap->map[i++]);
		wall_check(heap);
		object_check(heap);
		accessible_check(heap, path);
		printf("merhaba %d\n",heap->height); //silinecek
		printf("selam %d\n",heap->width); //silinecek
		printf("p_x : %d\n",heap->img->p_x); //silinecek
		printf("p_y : %d\n",heap->img->p_y); //silinecek
		get_image(heap);
	}
	else
		return (0);
}
