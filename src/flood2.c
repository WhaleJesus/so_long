/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:49:43 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/19 13:54:06 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_path_to_exit_continued_continued(t_flood *f, t_mlx *mlx)
{
	f->y = 0;
	while (f->y < mlx->map_height)
	{
		f->x = 0;
		while (f->x < mlx->map_width)
		{
			f->visited[f->y][f->x] = 0;
			f->x++;
		}
		f->y++;
	}
}

int	is_path_to_exit_continued(t_flood *f, t_mlx *mlx)
{
	f->y = 0;
	while (f->y < mlx->map_height)
	{
		f->visited[f->y] = (int *)malloc(mlx->map_width * sizeof(int));
		if (!f->visited[f->y])
		{
			while (f->y > 0)
			{
				free(f->visited[--f->y]);
			}
			free(f->visited);
			return (0);
		}
		f->y++;
	}
	is_path_to_exit_continued_continued(f, mlx);
	return (1);
}
