/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:11 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/25 15:43:33 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_map2(char **map, t_mlx *mlx, int x, int y)
{
	my_put_img(mlx, mlx->img_background, x, y);
	if (map[y][x] == 'P')
	{
		mlx->x = x;
		mlx->y = y;
		my_put_img(mlx, mlx->img_player, x, y);
	}
	else if (map[y][x] == 'C')
		my_put_img(mlx, mlx->img_collectible, x, y);
	else if (map[y][x] == 'E')
		my_put_img(mlx, mlx->img_exit, x, y);
}

int	draw_map(char **map, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				my_put_img(mlx, mlx->img_wall, x, y);
			else if (map[y][x] != '\n')
			{
				draw_map2(map, mlx, x, y);
			}
			x++;
		}
		y++;
	}
	display_turn_counter(mlx);
	return (0);
}

int	get_map_sizes2(t_mlx *mlx, char *line, int width)
{
	int	error;

	error = 0;
	width = ft_strlen(line) - 1;
	if ((width != mlx->map_width) && (mlx->map_width != 0))
		error = 1;
	mlx->map_width = width;
	mlx->map_height++;
	free(line);
	return (error);
}

void	get_map_sizes(t_mlx *mlx, char *path)
{
	int		fd;
	char	*line;
	int		error;

	error = 0;
	line = "";
	fd = open(path, O_RDONLY);
	if (fd == -1)
		display_error("Error Opening Map file", 0, mlx);
	get_map_sizes3(line, &error, fd, mlx);
	close(fd);
	if (mlx->map_height < 3 || mlx->map_width < 3 || error > 0)
		display_error("Just straight up what is this map", 0, mlx);
}

char	**read_map(char *path, t_mlx *mlx)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	line = "";
	i = 0;
	get_map_sizes(mlx, path);
	check_map_too_big(mlx);
	fd = open(path, O_RDONLY);
	map = read_map2(mlx, fd, i, line);
	close(fd);
	return (map);
}
