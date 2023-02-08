#include "so_long.h"

int		close_game(t_map *heap)
{
	int i;

	i = 0;
	mlx_destroy_image(heap->img->mlx,heap->img->coin);
	mlx_destroy_image(heap->img->mlx,heap->img->exit);
	mlx_destroy_image(heap->img->mlx,heap->img->graund);
	mlx_destroy_image(heap->img->mlx,heap->img->player);
	mlx_destroy_image(heap->img->mlx,heap->img->wall);
	while (heap->map[i])
	{
		free(heap->map[i]);
		i++;
	}
	free(heap->map);
	mlx_destroy_window(heap->img->mlx,heap->img->mlx_win);
	exit(0);
}

void	ft_error(t_map *heap)
{
	free(heap->map);
	free(heap);
	printf("Error");  //ft_printf ile değiştir.
	exit(0);
}
