/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:10:10 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/19 16:26:37 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill(t_mlx *mlx, int x, int y, int directions[4][2])
{
	int	i;
	int	new_x;
	int	new_y;
	int	collectibles_found;

	collectibles_found = 0;
	if (mlx->map[y][x] == 'e')
		collectibles_found++;
	mlx->flood->visited[y][x] = 1;
	i = 0;
	while (i < 4)
	{
		new_x = x + directions[i][0];
		new_y = y + directions[i][1];
		if (is_valid(mlx, mlx->flood->visited, new_x, new_y) == 1)
		{
			collectibles_found += flood_fill(mlx, new_x, new_y, directions);
		}
		i++;
	}
	return (collectibles_found);
}
