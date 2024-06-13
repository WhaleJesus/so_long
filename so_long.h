/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:10:56 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/13 13:25:16 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 700
# define GRID_SIZE 100

# define PATH_WALL "img/wall.xmp"
# define PATH_PLAYER "img/player.xmp"
# define PATH_COLLECTIBLE "img/collectible.xmp"
# define PATH_EXIT "img/exit.xmp"
# define PATH_BACKGROUND "img/background.xmp"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SPACE 32
# define KEY_ESC 65307

# define A 1664525
# define C 1013904223
# define M 4294967296  

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_imgfile
{
	void		*img;
	int			img_width;
	int			img_height;
	char		*relative_path;
}	t_imgfile;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	void	*img_background;
	int		map_width;
	int		map_height;
	int		turn;
	int		score;
}	t_mlx;

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			my_draw(t_img *img, int left, int top, int right, int bottom, int color);
int				key_hook(int keycode, t_mlx *mlx);
int				create_trgb(int t, int r, int g, int b);

unsigned int	lcg_rand_range(unsigned int *current, unsigned int min, unsigned int max);

int				init_imgs(t_mlx *mlx);

int				draw_map(char **map, t_mlx *mlx);
char			**read_map(char *path, t_mlx *mlx);

void			display_error(int error);

#endif
