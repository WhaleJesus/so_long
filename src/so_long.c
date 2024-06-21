/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:09:51 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/21 13:21:03 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_program(t_mlx *mlx)
{
	free_array(mlx);
	free_imgs(mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if ((keycode == KEY_W) || (keycode == KEY_UP))
		turn_move_vertical(mlx, -1);
	else if ((keycode == KEY_D) || (keycode == KEY_RIGHT))
		turn_move_horizontal(mlx, 1);
	else if ((keycode == KEY_S) || (keycode == KEY_DOWN))
		turn_move_vertical(mlx, 1);
	else if ((keycode == KEY_A) || (keycode == KEY_LEFT))
		turn_move_horizontal(mlx, -1);
	else if (keycode == KEY_ESC)
	{
		ft_printf("esc");
		exit_program(mlx);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx		mlx;

	if (argc != 2)
	{
		display_error(1);
		exit(0);
	}
	init_mlx(&mlx, argv[argc - 1]);
	mlx_loop(mlx.mlx);
}
