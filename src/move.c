/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:03:13 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/14 18:03:25 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_over(t_mlx *mlx)
{
	ft_printf("conmgrat u won\n");
	exit_program(mlx);
}

void	turn_move(t_mlx *mlx)
{
		if (mlx->map[mlx->y][mlx->x] == 'c')
		{
			mlx->score += 1;
			my_put_img(mlx, mlx->img_background, mlx->x, mlx->y);
		}
		else if (mlx->map[mlx->y][mlx->x] == 'e')
			game_over(mlx);
		mlx->map[mlx->y][mlx->x] = 'p';
		my_put_img(mlx, mlx->img_player, mlx->x, mlx->y);
		mlx->turn += 1;
		ft_printf("Turn: %i\n", mlx->turn);
}

void	turn_move_vertical(t_mlx *mlx, int direction)
{
	if (mlx->map[mlx->y + direction][mlx->x] != '1')
	{
		mlx->map[mlx->y][mlx->x] = '0';
		my_put_img(mlx, mlx->img_background, mlx->x, mlx->y);
		mlx->y += direction;
		turn_move(mlx);
	}
}

void	turn_move_horizontal(t_mlx *mlx, int direction)
{
	if (mlx->map[mlx->y][mlx->x + direction] != '1')
	{
		mlx->map[mlx->y][mlx->x] = '0';
		my_put_img(mlx, mlx->img_background, mlx->x, mlx->y);
		mlx->x += direction;
		turn_move(mlx);
	}
}
