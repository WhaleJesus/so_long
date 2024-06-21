/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:35:50 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/21 13:01:35 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	is_valid(t_mlx *mlx, int x, int y)
{
	if (x >= 0 && x < mlx->map_width && y >= 0 && y < mlx->map_height
		&& !ft_strchr(mlx->flood->wall, mlx->map[y][x])
		&& !mlx->flood->visited[y][x])
	{
		return (1);
	}
	return (0);
}

int	flood_fill(t_mlx *mlx, int x, int y)
{
	int	num_c;

	num_c = 0;
	if (mlx->map[y][x] == mlx->flood->target)
		num_c++;
	mlx->flood->visited[y][x] = 1;
	if (x == 0 || x == mlx->map_width - 1 || y == 0 || y == mlx->map_height - 1)
	{
		ft_printf("ERROR\nMap not enclosed\n");
		return (-1);
	}
	num_c = flood_fill_continued(mlx, x, y, num_c);
	return (num_c);
}

int	is_path_to_exit(t_mlx *mlx, char c, char *wall)
{
	int		result;
	t_flood	*f;

	f = malloc(sizeof(t_flood));
	if (!f)
		return (0);
	f->visited = (int **)malloc(mlx->map_height * sizeof(int *));
	if (!f->visited)
	{
		free(f);
		return (0);
	}
	init_flood_visited(mlx, f);
	initialize_directions(f->directions);
	mlx->flood = f;
	mlx->flood->y2 = mlx->y;
	mlx->flood->x2 = mlx->x;
	mlx->flood->wall = wall;
	mlx->flood->target = c;
	result = flood_fill(mlx, mlx->flood->x2, mlx->flood->y2);
	free_flood(f, mlx->map_height);
	return (result);
}
