/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:39:48 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/21 19:00:55 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_draw(t_img *img, int left, int top, int right, int bottom, int color)
{
	int	x;
	int	y;

	x = left;
	while (x <= right + left)
	{
		y = top;
		while (y <= bottom + top)
			my_mlx_pixel_put(img, x, y++, color);
		x++;
	}
}

int	letter_r(t_img *img, int left, int spacing, int width, int height, int color)
{
	int	top;
	int	special_width;
	int	y;
	int	x;

	top = 50;
	special_width = height / 4;
	my_draw(img, left, top, width, height, color);
	my_draw(img, left, top, special_width, width, color);
	my_draw(img, left + special_width - width, top, width, (height / 2) - width, color);
	my_draw(img, left, top + (height / 2) - width, special_width, width, color);
	y = 0;
	x = top + (height / 2) - width;
	while (x <= height + top)
	{
		my_draw(img, left, x, width, 1 , color);
		y++;
		x++;
		if (y % 5 == 0)
			left += 2;
	}
	return (left);
}

int	letter_e(t_img *img, int left, int spacing, int width, int height, int color)
{
	int	top;
	int	special_width;

	top = 50;
	special_width = (height / 4) - width;
	my_draw(img, left, top, width, height, color);
	left += width;
	my_draw(img, left, top, special_width, width, color);
	my_draw(img, left, top + (height / 2) - (width), (special_width / 2) + width, width, color);
	my_draw(img, left, top + height - width, special_width , width, color);
	return(left + special_width + spacing);
}

int	letter_g(t_img *img, int left, int spacing, int width, int height, int color)
{
	int	top;
	int special_width;

	top = 50;
	special_width = height / 4;
	my_draw(img, left, top, special_width, width, color);
	my_draw(img, left, top + width, width, height - width, color);
	my_draw(img, left, (top + height) - width, special_width, width, color);
	my_draw(img, left + special_width - width, top + (height / 2) - width, width, height / 2, color);
	my_draw(img, left + (special_width / 2), top + (height / 2) - width, special_width / 2, width, color);
	return (left + special_width + spacing);
}

int	letter_i(t_img *img, int left, int spacing, int width, int height, int color)
{
	int	top;

	top = 50;
	my_draw(img, left, top, width, height, color);
	return (left + width + spacing);
}

int	letter_n(t_img *img, int left, int spacing, int width, int height, int color)
{
	int	x;
	int	y;
	int	top;

	top = 50;
	my_draw(img, left, top, width, height, color);
	y = 0;
	x = 0;
	while (y < height)
	{
		my_draw(img, left, top + y, width, 1, color);
		y++;
		x++;
		if (x % 4 == 0)
			left++;
	}
	my_draw(img, left, top, width, height, color);
	return (left + width + spacing);
}

void	drawNig(t_mlx *mlx)
{
	t_img	img;
	int		width;
	int		height;
	int		left;
	int		spacing;

	width = 20;
	height = 800;
	left = 200;
	spacing = 100;
	img.img = mlx_new_image(mlx->mlx, 1920, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	left = letter_n(&img, left, spacing, width, height, create_trgb(1, 227, 30, 201));
	left = letter_i(&img, left, spacing, width, height, 0x00FF0000);
	left = letter_g(&img, left, spacing, width, height, 0x00FF0000);
	left = letter_g(&img, left, spacing, width, height, 0x00FF0000);
	left = letter_e(&img, left, spacing, width, height, 0x00FF0000);
	left = letter_r(&img, left, spacing, width, height, 0x00FF0000);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_loop(mlx->mlx);
}
