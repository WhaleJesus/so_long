/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:09:51 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/13 19:07:46 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_program(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

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
		exit_program(mlx);
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
	ft_printf("%s\n", path);
	map = read_map(path, &mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.map_width * GRID_SIZE, mlx.map_height * GRID_SIZE, "hello");
	
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_program, &mlx);
	init_imgs(&mlx);
	draw_map(map, &mlx);
	mlx_loop(mlx.mlx);
}
