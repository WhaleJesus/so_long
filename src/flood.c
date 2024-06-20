/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:06:49 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/20 14:30:45 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void initialize_directions(int directions[4][2]) {
    directions[0][0] = -1;
    directions[0][1] = 0;
    directions[1][0] = 1;
    directions[1][1] = 0;
    directions[2][0] = 0;
    directions[2][1] = -1;
    directions[3][0] = 0;
    directions[3][1] = 1;
}

int is_valid(t_mlx *mlx, int **visited, int x, int y)
{
    if (x >= 0 && x < mlx->map_width && y >= 0 && y < mlx->map_height && !ft_strchr(mlx->flood->wall, mlx->map[y][x]) && !visited[y][x]) {
        return (1);
    }
    return (0);
}

int flood_fill(t_mlx *mlx, int x, int y, char c, int directions[4][2]) {
    int i;
    int new_x;
    int new_y;
    int num_c;

    num_c = 0;
    if (mlx->map[y][x] == c) {
        num_c++;
    }
    mlx->flood->visited[y][x] = 1;
	if (x == 0 || x == mlx->map_width - 1 || y == 0 || y == mlx->map_height - 1) {
        ft_printf("ERROR\nMap not enclosed\n");
        return (-1);
    }
    i = 0;
    while (i < 4) {
        new_x = x + directions[i][0];
        new_y = y + directions[i][1];
        if (is_valid(mlx, mlx->flood->visited, new_x, new_y)) {
            num_c += flood_fill(mlx, new_x, new_y, c, directions);
        }
        i++;
    }
    return (num_c);
}

int is_path_to_exit(t_mlx *mlx, char c, char *wall) {
    int directions[4][2];
    int result;
    int y;
    t_flood *f;

    f = malloc(sizeof(t_flood));
    if (!f) {
        return (0);
    }
    f->visited = (int **)malloc(mlx->map_height * sizeof(int *));
    if (!f->visited) {
        free(f);
        return (0);
    }
    if (is_path_to_exit_continued(f, mlx) != 1) {
        free_flood(f, mlx->map_height);
        return (0);
    }

    initialize_directions(directions);
    mlx->flood = f;
    mlx->flood->y2 = mlx->y;
    mlx->flood->x2 = mlx->x;
    mlx->flood->wall = wall;
    result = flood_fill(mlx, mlx->flood->x2, mlx->flood->y2, c, directions);
    free_flood(f, mlx->map_height);
    return (result);
}
