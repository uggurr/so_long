#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	int	a;
}				t_game;

typedef struct s_map
{
	char	*map_line;
	char	**map;
	int		width;
	int		height;
}				t_map;

void	wall_check(t_map *heap);
void	ft_error(t_map *heap);

#endif
