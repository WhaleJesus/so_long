/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:11 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/13 13:48:25 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*my_create_img(t_mlx *mlx, char *path)
{
	int		height;
	int		width;
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx, path, &width, &height);
	return (img);
}


int init_imgs(t_mlx *mlx)
{
	mlx->img_wall = my_create_img(mlx, PATH_WALL);
	mlx->img_player = my_create_img(mlx, PATH_PLAYER);
	mlx->img_collectible = my_create_img(mlx, PATH_COLLECTIBLE);
	mlx->img_exit = my_create_img(mlx, PATH_EXIT);
	mlx->img_background = my_create_img(mlx, PATH_BACKGROUND);
	return (1);
}

void	my_put_img(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, x * GRID_SIZE, y * GRID_SIZE);
}

int	draw_map(char **map, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				my_put_img(mlx, mlx->img_wall, x, y);
			else
			{
				my_put_img(mlx, mlx->img_background, x, y);
				if (map[y][x] == 'p')
					my_put_img(mlx, mlx->img_player, x, y);
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
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error Opening Map file");
		return (-1);
	}
	i = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		width = ft_strlen(line) - 1;
		if ((width != mlx->map_width) && (mlx->map_width != 0))
		{
			display_error(2);
			exit(0);
		}
		mlx->map_width = width;
		i++;
	}
	mlx->map_height = i;
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
	fd = open(path, O_RDONLY);
	i = 0;
	map = malloc(sizeof(char *) * mlx->map_height);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (map);
		map[i] = line;
		i++;
	}
	return (map);
}
