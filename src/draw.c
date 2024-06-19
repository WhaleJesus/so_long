/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:55:41 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/19 13:58:41 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	*my_create_img(t_mlx *mlx, char *path)
{
	int		height;
	int		width;
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx, path, &width, &height);
	return (img);
}

void	my_put_img(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, \
			x * GRID_SIZE, y * GRID_SIZE);
}

void	img_clear_pixel_put(t_mlx *mlx, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->map_width * GRID_SIZE)
	{
		y = 0;
		while (y < 15)
		{
			my_mlx_pixel_put(img, x, y, create_trgb(1, 255, 0, 0));
			y++;
		}
		x++;
	}
}
