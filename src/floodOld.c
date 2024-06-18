/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:34:45 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/18 12:07:43 by sklaps           ###   ########.fr       */
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

int		is_valid(t_mlx *mlx, int **visited, int x, int y)
{
    if (x >= 0 && x < mlx->map_width && y >= 0 && y < mlx->map_height
        && mlx->map[y][x] != '1' && !visited[y][x])
        return (1);
    return (0);
}

void	printvisited(t_mlx *mlx, int **visited)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			ft_printf("%i", visited[y][x]);
			x++;
		}
		ft_printf(" | ");
		ft_printf("%s", mlx->map[y]);
		y++;
	}
	ft_printf("\n");
}

int		flood_fill(t_mlx *mlx, int **visited, int x, int y, int directions[4][2])
{
    int	i;
    int	new_x;
    int	new_y;

    if (mlx->map[y][x] == 'e')
        return (1);

    visited[y][x] = 1;
	printvisited(mlx, visited);
    i = 0;
    while (i < 4)
    {
        new_x = x + directions[i][0];
        new_y = y + directions[i][1];

        if (is_valid(mlx, visited, new_x, new_y) == 1)
        {
            if (flood_fill(mlx, visited, new_x, new_y, directions))
                return (1);
        }
        i++;
    }
    return (0);
}

int	is_path_to_exit(t_mlx *mlx)
{
    int	**visited;
    int	directions[4][2];
    int	x;
    int	y;
	int	result;

    visited = (int **)malloc(mlx->map_height * sizeof(int *));
    if (!visited)
   		return (0);
	y = 0;
    while (y < mlx->map_height)
    {
        visited[y] = (int *)malloc(mlx->map_width * sizeof(int));
        if (!visited[y])
        {
            while (y > 0)
            {
                free(visited[--y]);
            }
            free(visited);
            return (0);
        }
        y++;
    }

    y = 0;
    while (y < mlx->map_height)
    {
        x = 0;
        while (x < mlx->map_width)
        {
            visited[y][x] = 0;
            x++;
        }
        y++;
    }

    initialize_directions(directions);

    result = flood_fill(mlx, visited, mlx->x, mlx->y, directions);

    y = 0;
    while (y < mlx->map_height)
    {
        free(visited[y]);
        y++;
    }
    free(visited);

    return result;
}
