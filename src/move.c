/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:26:24 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/21 14:05:17 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_over(t_mlx *mlx)
{
	ft_printf("conmgrat u won\n");
	exit_program(mlx);
}

void	add_turn(t_mlx *mlx)
{
	mlx->turn += 1;
	ft_printf("Turn: %i\n", mlx->turn);
	display_turn_counter(mlx);
}

void	turn_move(t_mlx *mlx)
{
	if (mlx->map[mlx->y][mlx->x] == 'C')
	{
		mlx->score += 1;
		my_put_img(mlx, mlx->img_background, mlx->x, mlx->y);
	}
	else if (mlx->map[mlx->y][mlx->x] == 'E')
		game_over(mlx);
	mlx->map[mlx->y][mlx->x] = 'P';
	my_put_img(mlx, mlx->img_player, mlx->x, mlx->y);
	add_turn(mlx);
}

void	turn_move_vertical(t_mlx *mlx, int direction)
{
	if (mlx->map[mlx->y + direction][mlx->x] != '1')
	{
		if (!(mlx->score != mlx->num_collectibles
				&& mlx->map[mlx->y + direction][mlx->x] == 'E'))
		{
			mlx->map[mlx->y][mlx->x] = '0';
			my_put_img(mlx, mlx->img_background, mlx->x, mlx->y);
			mlx->y += direction;
			turn_move(mlx);
		}
		else
			ft_printf("Not all collectibles collected");
	}
}

void	turn_move_horizontal(t_mlx *mlx, int direction)
{
	if (mlx->map[mlx->y][mlx->x + direction] != '1')
	{
		if (!(mlx->score != mlx->num_collectibles
				&& mlx->map[mlx->y][mlx->x + direction] == 'E'))
		{
			mlx->map[mlx->y][mlx->x] = '0';
			my_put_img(mlx, mlx->img_background, mlx->x, mlx->y);
			mlx->x += direction;
			turn_move(mlx);
		}
		else
			ft_printf("Not all collectibles collected");
	}
}
