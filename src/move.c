/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:03:13 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/18 16:21:47 by sklaps           ###   ########.fr       */
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
	int		color;
	int		y;
	char	*string_turn;

	y = (mlx->map_height * GRID_SIZE) + 20;
	color = create_trgb(1, 0, 255, 0);
	mlx->turn += 1;
	string_turn = ft_itoa(mlx->turn);
	if (NULL == string_turn)
		string_turn = "null";
	my_put_img(mlx, mlx->img_clear->img, 0, mlx->map_height);
	mlx_string_put(mlx->mlx, mlx->win, 10, y, color, string_turn);
	ft_printf("Turn: %i\n", mlx->turn);
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
		add_turn(mlx);
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
