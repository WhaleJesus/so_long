/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:54:11 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/19 15:08:29 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_too_big(t_mlx *mlx)
{
	if (mlx->map_height * GRID_SIZE > SCREEN_HEIGHT || mlx->map_width - 1
		* GRID_SIZE > SCREEN_WIDTH)
	{
		ft_printf("Error: please make map no bigger than: W:%i H:%i\n",
			SCREEN_WIDTH / GRID_SIZE, SCREEN_HEIGHT / GRID_SIZE);
		exit(0);
	}
}
