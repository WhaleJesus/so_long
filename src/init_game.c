/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:29:21 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/25 15:42:47 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_flood(t_mlx *mlx)
{
	int	result;

	result = is_path_to_exit(mlx, 'C', "E1");
	if (result != mlx->num_collectibles)
	{
		if (result != -1)
			ft_printf("Error:\nNot all collectibles reachable");
		exit_program(mlx);
	}
	result = is_path_to_exit(mlx, 'E', "1");
	if (result != 1)
	{
		if (!(result == -1))
			ft_printf("Error:\nPath to exit is not valid");
		exit_program(mlx);
	}
}

void	display_turn_counter(t_mlx *mlx)
{
	int		y;
	int		color;
	char	*str_turn;

	y = mlx->map_height;
	my_put_img(mlx, mlx->img_clear.img, 0, y);
	y = (y * GRID_SIZE) + 10;
	color = create_trgb(1, 0, 255, 0);
	str_turn = ft_itoa(mlx->turn);
	if (NULL == str_turn)
		str_turn = "null";
	mlx_string_put(mlx->mlx, mlx->win, 10, y, color, str_turn);
	free(str_turn);
}

void	init_mlx(t_mlx *mlx, char *path)
{
	mlx->map_width = 0;
	mlx->map_height = 0;
	mlx->score = 0;
	mlx->turn = 0;
	check_map_extension(path);
	mlx->map = read_map(path, mlx);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_width * GRID_SIZE,
			(mlx->map_height * GRID_SIZE) + 15, "hello");
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, exit_program, mlx);
	init_imgs(mlx);
	draw_map(mlx->map, mlx);
	check_map_tokens(mlx);
	check_flood(mlx);
}

int	init_imgs(t_mlx *mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx->mlx, mlx->map_width * GRID_SIZE, 15);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img_clear_pixel_put(mlx, &img);
	mlx->img_wall = my_create_img(mlx, PATH_WALL);
	mlx->img_player = my_create_img(mlx, PATH_PLAYER);
	mlx->img_collectible = my_create_img(mlx, PATH_COLLECTIBLE);
	mlx->img_exit = my_create_img(mlx, PATH_EXIT);
	mlx->img_background = my_create_img(mlx, PATH_BACKGROUND);
	mlx->img_clear = img;
	return (1);
}
