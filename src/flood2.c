/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:21 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/22 16:18:18 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_path_to_exit_continued(t_flood *f, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_height)
	{
		f->visited[y] = (int *)malloc(mlx->map_width * sizeof(int));
		if (!f->visited[y])
		{
			while (--y >= 0)
				free(f->visited[y]);
			free(f->visited);
			return (0);
		}
		x = 0;
		while (x < mlx->map_width)
		{
			f->visited[y][x] = 0;
			x++;
		}
		y++;
	}
	return (1);
}

int	flood_fill_continued(t_mlx *mlx, int x, int y, int num_c)
{
	int	new_x;
	int	new_y;
	int	num_c2;
	int	i;

	i = 0;
	while (i < 4)
	{
		new_x = x + mlx->flood->directions[i][0];
		new_y = y + mlx->flood->directions[i][1];
		if (is_valid(mlx, new_x, new_y))
		{
			num_c2 = num_c;
			num_c += flood_fill(mlx, new_x, new_y);
			if (num_c == num_c2 - 1)
				return (-1);
		}
		i++;
	}
	return (num_c);
}

void	init_flood_visited(t_mlx *mlx, t_flood *f)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_height)
	{
		f->visited[y] = (int *)malloc(mlx->map_width * sizeof(int));
		if (!f->visited[y])
		{
			free_flood(f, mlx->map_height);
			exit_program(0);
		}
		x = 0;
		while (x < mlx->map_width)
		{
			f->visited[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	free_flood(t_flood *f, int map_height)
{
	int	y;

	y = 0;
	while (y < map_height)
	{
		free(f->visited[y]);
		y++;
	}
	free(f->visited);
	free(f);
}
