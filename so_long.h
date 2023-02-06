#ifndef SO_LONG_H
# define SO_LONG_H
# define P "./textures/mario.xpm"
# define G "./textures/graound.xpm"
# define W "./textures/wall.xpm"
# define C "./textures/coin.xpm"
# define E "./textures/exit.xpm"

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
	int		x;
	int		y;
	int		endian;
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

#endif
