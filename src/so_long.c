/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:09:51 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/25 22:27:44 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	ft_printf("Hello from key_hook! %i\n", keycode);
	if (keycode == KEY_W)
		ft_printf("W");
	else if (keycode == KEY_SPACE)
		ft_printf("space");
	else if (keycode == KEY_ESC)
	{
		ft_printf("esc");
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	ft_printf("\n");
	return (0);
}


int	main(void)
{
	t_mlx		mlx;

	mlx.mlx = mlx_init();
	mlx.width = 1080;
	mlx.height = 700;
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "hello");
	
	mlx_key_hook(mlx.win, key_hook, &mlx);
	//mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx);
}
