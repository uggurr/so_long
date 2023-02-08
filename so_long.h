#ifndef SO_LONG_H
# define SO_LONG_H
# define P "./textures/characterDown.xpm"
# define P1 "./textures/characterAbove.xpm"
# define P2 "./textures/characterLeft.xpm"
# define P3 "./textures/characterRight.xpm"
# define G "./textures/BG.xpm"
# define W "./textures/wall1.xpm"
# define C "./textures/coingif1.xpm"
# define C1 "./textures/coingif2.xpm"
# define C2 "./textures/coingif3.xpm"
# define C3 "./textures/coingif4.xpm"
# define C4 "./textures/coingif5.xpm"
# define C5 "./textures/coingif6.xpm"
# define C6 "./textures/coingif7.xpm"
# define E "./textures/EXIT1.xpm"
# define E1 "./textures/EXIT2.xpm"
# define D "./textures/ENEMY1.xpm"
# define D1 "./textures/ENEMY2.xpm"
# define D2 "./textures/ENEMY3.xpm"
# define D3 "./textures/ENEMY4.xpm"
# define D4 "./textures/ENEMY5.xpm"
# define D5 "./textures/ENEMY6.xpm"
# define D6 "./textures/ENEMY7.xpm"



# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx/mlx.h"

typedef struct s_object
{
	int	p_count;
	int	c_count;
	int	e_count;
}				t_object;

typedef struct s_path
{
	char	**visited;
	char	**matrix;
	int		mat_y;
	int		mat_x;
}				t_path;

typedef struct s_img
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	void	*graund;
	void	*player;
	void	*coin;
	void	*wall;
	void	*exit;
	void	*enemy;
	int 	p_x;
	int		p_y;
	int		p_coin;
	int		point;
	int		x;
	int		y;
}				t_img;

typedef struct s_map
{
	t_object	*object;
	t_path		*path;
	t_img		*img;
	char		*map_line;
	char		**map;
	int			width;
	int			height;
}				t_map;

void	wall_check(t_map *heap);
void	ft_error(t_map *heap);
void	object_check(t_map *heap);
void	accessible_check(t_map *heap, t_path *path);
int		ft_path(int y, int x, t_path *path);
void	ft_path_find(t_path *path);
void	ft_path_put(int result);
void	map_exit_check(int i, int j, t_path *path);
void	ft_visited_clear(t_path *path);
void	get_image(t_map *heap);
int		key_move(int keycode, t_map *heap);
void    ft_img_idx(t_map *heap);
int		close_game(t_map *heap);
void    put_score(int point, t_map *heap);
int		loop_img(t_map *heap);

#endif
