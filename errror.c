#include "so_long.h"

void	ft_error(t_map *heap)
{
	free(heap->map);
	free(heap);
	printf("Error");  //ft_printf ile değiştir.
	exit(0);
}
