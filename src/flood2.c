/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:56:21 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/20 12:56:55 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_path_to_exit_continued(t_flood *f, t_mlx *mlx)
{
    int y;
	int	x;

    y = 0;
    while (y < mlx->map_height) {
        f->visited[y] = (int *)malloc(mlx->map_width * sizeof(int));
        if (!f->visited[y]) {
            while (--y >= 0)
                free(f->visited[y]);
            free(f->visited);
            return (0);
        }
        x = 0;
        while (x < mlx->map_width) {
            f->visited[y][x] = 0;
            x++;
        }
        y++;
    }
    return (1);
}
