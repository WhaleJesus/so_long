/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:11 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/18 15:22:14 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
				my_put_img(mlx, mlx->img_background, x, y);
				if (map[y][x] == 'p')
				{
					mlx->x = x;
					mlx->y = y;
					my_put_img(mlx, mlx->img_player, x, y);
				}
				else if (map[y][x] == 'c')
					my_put_img(mlx, mlx->img_collectible, x, y);
				else if (map[y][x] == 'e')
					my_put_img(mlx, mlx->img_exit, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	get_map_sizes(t_mlx *mlx, char *path)
{
	int		fd;
	int		i;
	int		width;
	char	*line;
	
	mlx->map_width = 0;
	mlx->map_height = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error Opening Map file");
		exit(0);
	}
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (NULL == line)
			break ;
		width = ft_strlen(line) - 1;
		if ((width != mlx->map_width) && (mlx->map_width != 0))
		{
			display_error(2);
			free(line);
			exit(0);
		}
		mlx->map_width = width;
		free(line);
		mlx->map_height++;
	}
	free(line);
	close(fd);
	return (0);
}

char	**read_map(char *path, t_mlx *mlx)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	get_map_sizes(mlx, path);
	if (mlx->map_height * GRID_SIZE > SCREEN_HEIGHT || mlx->map_width - 1 * GRID_SIZE > SCREEN_WIDTH)
	{
		ft_printf("Error: please make map no bigger than: W:%i H:%i\n", SCREEN_WIDTH / GRID_SIZE, SCREEN_HEIGHT / GRID_SIZE);
		exit_program(mlx);
	}
	fd = open(path, O_RDONLY);
	i = 0;
	map = malloc(sizeof(char *) * mlx->map_height);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (NULL == line)
			break ;
		map[i] = line;
		i++;
	}
	free(line);
	close(fd);
	return (map);
}
