/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:10:56 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/22 14:09:45 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SPACE 32
# define KEY_ESC 65307



typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	struct s_img	img;
	int		niga;
}	t_mlx;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	my_draw(t_img *img, int left, int top, int right, int bottom, int color);
int	key_hook(int keycode, t_mlx *mlx);
int	create_trgb(int t, int r, int g, int b);

#endif
