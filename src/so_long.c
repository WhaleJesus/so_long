/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:09:51 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/22 14:09:42 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_mlx *vars)
{
	ft_printf("Hello from key_hook! %i\n", keycode);
	if (keycode == KEY_W)
		ft_printf("W");
	else if (keycode == KEY_SPACE)
		ft_printf("space");
	else if (keycode == KEY_ESC)
		ft_printf("esc");
	ft_printf("\n");
	return (0);
}

int	render_next_frame(t_mlx *mlx)
{
	int r;
	int g;
	int b;

	mlx->niga++;
	if (mlx->niga > 255)
		mlx->niga = 0;
	r = mlx->niga++;
	mlx->niga += 24;
	if (mlx->niga > 255)
		mlx->niga = 0;
	g = mlx->niga++;
	mlx->niga += 24;
	if (mlx->niga > 255)
		mlx->niga = 0;
	b = mlx->niga++;
	my_draw(&mlx->img, 100, 100, 100, 100, create_trgb(1, r, g, b));
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;
	t_img	img;
	t_img	duck;
	int		i;

	i = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 900, "hello");
	img.img = mlx_new_image(mlx.mlx, 500, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	mlx.img = img;
	mlx.niga = i;
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop_hook(mlx.mlx, render_next_frame, &mlx);
	mlx_loop(mlx.mlx);	
}
