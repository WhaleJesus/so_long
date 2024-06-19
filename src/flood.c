/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:13:20 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/19 16:40:25 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void	initialize_directions(int directions[4][2])
{
	directions[0][0] = -1;
	directions[0][1] = 0;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = 0;
	directions[3][1] = 1;
}

int	is_valid(t_mlx *mlx, int **visited, int x, int y)
{
	if (x >= 0 && x < mlx->map_width && y >= 0 && y < mlx->map_height
		&& mlx->map[y][x] != '1' && !visited[y][x])
		return (1);
	return (0);
}

int	flood_fill(t_mlx *mlx, int x, int y, int directions[4][2])
{
	int	i;
	int	new_x;
	int	new_y;

	if (mlx->map[y][x] == 'E')
		return (1);
	mlx->flood->visited[y][x] = 1;
	i = 0;
	while (i < 4)
	{
		new_x = x + directions[i][0];
		new_y = y + directions[i][1];
		if (is_valid(mlx, mlx->flood->visited, new_x, new_y) == 1)
		{
			if (flood_fill(mlx, new_x, new_y, directions))
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_path_to_exit(t_mlx *mlx)
{
	int		directions[4][2];
	int		continued;
	int		result;
	t_flood	f;

	f.visited = (int **)malloc(mlx->map_height * sizeof(int *));
	if (!f.visited)
		return (0);
	continued = is_path_to_exit_continued(&f, mlx);
	if (continued != 1)
		return (0);
	initialize_directions(directions);
	mlx->flood = &f;
	result = flood_fill(mlx, mlx->x, mlx->y, directions);
	f.y = 0;
	while (f.y < mlx->map_height)
	{
		free(f.visited[f.y]);
		f.y++;
	}
	free(f.visited);
	return (result);
}
