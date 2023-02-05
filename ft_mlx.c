#include "so_long.h"

void    ft_img_addr(t_map *heap)
{
    heap->img->graund = mlx_xpm_file_to_image(heap->img->mlx,G,&heap->img->x,&heap->img->y);
    heap->img->player = mlx_xpm_file_to_image(heap->img->mlx,P,&heap->img->x,&heap->img->y);
}

void    ft_image_put(char s, t_img *img, int l, int k)
{
    //(void)s;
    if (s == 'P')
        mlx_put_image_to_window(img->mlx,img->mlx_win,img->player,l,k);
    else if (s == '0')
        mlx_put_image_to_window(img->mlx,img->mlx_win,img->graund,l,k);
}

void    ft_img_idx(t_map *heap)
{
    int i = 0;
    int k = 0;
    int l = 0;
    int j = 0;
    while (i < heap->height)
    {
        j= 0;
        l = 0;
        while (j < heap->width)
        {
            ft_image_put(heap->map[i][j],heap->img,l,k);
            l += 64;
            j++;
        }
        i++;
        k +=64;
    }
}

void    get_image(t_map *heap)
{
    //int l = 0;
    //int k = 0;
    heap->img->mlx = mlx_init();
    heap->img->mlx_win = mlx_new_window(heap->img->mlx,heap->width * 64,heap->height * 64,"so_long");
    ft_img_addr(heap);
    //ft_image_put(heap->map[5][4],heap->img,l,k);

    ft_img_idx(heap);
    mlx_loop(heap->img->mlx);
}