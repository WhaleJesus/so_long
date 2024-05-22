/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:55:41 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/22 13:29:10 by sklaps           ###   ########.fr       */
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
