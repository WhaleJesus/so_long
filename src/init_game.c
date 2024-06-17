/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:29:21 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/17 17:06:43 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_edges(t_mlx *mlx)
{
	int	i;
	int j;

	i = 0;
	while(i < mlx->map_height)
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] != '\n')
			{
				if ((j == 0 || j == (ft_strlen(mlx->map[i]) - 2)))
					if (mlx->map[i][j] != '1')
					{
						ft_printf("Error: map is not enclosed");
						exit_program(mlx);
					}
				if ((i == 0) || (i == mlx->map_height - 1))
					if (mlx->map[i][j] != '1')
					{
						ft_printf("(%i,%i) Error: map is not enclosed\n", i, j);
						exit_program(mlx);
					}
			}
			j++;
		}
		i++;
	}
}

void	check_map_char(t_mlx *mlx, char *c, int min, int max)
{
	int	num_c;
	int	i;
	int	j;
	char	**map;

	map = mlx->map;
	num_c = 0;
	i = 0;
	while (i < mlx->map_height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c[0])
				num_c++;
			j++;
		}
		i++;
	}
	if (!((num_c >= min) && (num_c <= max)))
	{
		ft_printf("Error: please keep %s between %i and %i\n", c, min, max);
		exit_program(mlx);
	}
}

void	check_map_tokens(t_mlx *mlx)
{
	check_map_char(mlx, "p", 1, 1);
	check_map_char(mlx, "e", 1, 1);
	check_map_char(mlx, "c", 1, INT_MAX);
}

void	check_map_extension(char *path)
{
	path += ft_strlen(path) - 1;
	if (*path == 'r')
	{
		path--;
		if (*path == 'e')
		{
			path--;
			if (*path == 'b')
			{
				path--;
				if (*path == '.')
					return ;
			}
		}
	}
	ft_printf("Error: map extension must be .ber\n");
	exit(0);
}

void	init_mlx(t_mlx *mlx, char *path)
{
	check_map_extension(path);
	mlx->map = read_map(path, mlx);
	mlx->score = 0;
	mlx->turn = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_width * GRID_SIZE, mlx->map_height * GRID_SIZE, "hello");
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, exit_program, mlx);
	init_imgs(mlx);
	draw_map(mlx->map, mlx);
	check_map_edges(mlx);
	check_map_tokens(mlx);
}

int	init_imgs(t_mlx *mlx)
{
	mlx->img_wall = my_create_img(mlx, PATH_WALL);
	mlx->img_player = my_create_img(mlx, PATH_PLAYER);
	mlx->img_collectible = my_create_img(mlx, PATH_COLLECTIBLE);
	mlx->img_exit = my_create_img(mlx, PATH_EXIT);
	mlx->img_background = my_create_img(mlx, PATH_BACKGROUND);
	return (1);
}
