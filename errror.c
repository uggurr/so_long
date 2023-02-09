#include "so_long.h"

int    close_game(t_map *heap)
{
    int    i;

    i = 0;
    mlx_destroy_image(heap->img->mlx, heap->img->coin);
    mlx_destroy_image(heap->img->mlx, heap->img->exit);
    mlx_destroy_image(heap->img->mlx, heap->img->graund);
    mlx_destroy_image(heap->img->mlx, heap->img->player);
    mlx_destroy_image(heap->img->mlx, heap->img->wall);
    while (heap->map[i])
    {
        free(heap->map[i]);
        free(heap->path->visited[i]);
        free(heap->path->matrix[i]);
        i++;
    }
    mlx_destroy_window(heap->img->mlx, heap->img->mlx_win);
    free(heap->path->visited);
    free(heap->path->matrix);
    free(heap->path);
    free(heap->map_line);
    free(heap->img);
    free(heap->map);
    free(heap->object);
    free(heap);
    //system("leaks so_long");
    exit(0);
}

void    ft_error(t_map *heap)
{
    int    i;

    i = 0;
    while (heap->map[i])
    {
        free(heap->map[i]);
        free(heap->path->visited[i]);
        free(heap->path->matrix[i]);
        i++;
    }
    free(heap->path->visited);
    free(heap->path->matrix);
    free(heap->path);
    free(heap->map_line);
    free(heap->img);
    free(heap->map);
    free(heap->object);
    free(heap);
    //system("leaks so_long");
    printf("Error"); //ft_printf ile değiştir.
    exit(0);
}
