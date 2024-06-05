/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:09:51 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/05 16:43:40 by sklaps           ###   ########.fr       */
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


int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	char		**map;
	char		*path;

	if (argc != 2)
	{
		display_error(1);
		exit(0);
	}

	path = argv[argc - 1];
	map = read_map(path, &mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.map_width * 100, mlx.map_height * 100, "hello");
	
	mlx_key_hook(mlx.win, key_hook, &mlx);

	draw_map(map, &mlx);
	mlx_loop(mlx.mlx);
}
