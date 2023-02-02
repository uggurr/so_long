#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    get_image(t_map *heap)
{
    heap->img->mlx = mlx_init();
    heap->img->mlx_win = mlx_new_window(heap->img->mlx,heap->width * 64,heap->height * 64,"so_long");
    heap->img->img = mlx_new_image(heap->img->mlx,1920,1080);
    heap->img->addr = mlx_get_data_addr(heap->img->img,&heap->img->bits_per_pixel,&heap->img->line_length,&heap->img->endian);
    my_mlx_pixel_put(heap->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(heap->img->mlx, heap->img->mlx_win, heap->img->img, 0, 0);
    mlx_loop(heap->img->mlx);
}