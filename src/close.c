/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:29:21 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/19 14:24:49 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_array(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map_height)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}

void	free_imgs(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img_wall);
	mlx_destroy_image(mlx->mlx, mlx->img_background);
	mlx_destroy_image(mlx->mlx, mlx->img_player);
	mlx_destroy_image(mlx->mlx, mlx->img_collectible);
	mlx_destroy_image(mlx->mlx, mlx->img_exit);
	mlx_destroy_image(mlx->mlx, mlx->img_clear.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}
