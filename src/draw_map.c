/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:11 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/06 17:06:43 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int draw_map(char **map, t_mlx *mlx)
{
	return (1);
}

int	get_map_sizes(t_mlx *mlx, char *path)
{
	int		fd;
	int		i;
	char	*line;
	
	mlx->map_width = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error Opening Map file"));
	i = 0;
	ft_printf("woah\n");
	while (line && !ft_strncmp(line, "(null)", ft_strlen("(null)")))
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
		if (ft_strlen(line) != mlx->map_width && mlx->map_width != 0)
		{
			display_error(2);
			exit(0);
		}
		mlx->map_width = ft_strlen(line);
		i++;
	}
	mlx->map_height = i;
	ft_printf("uhhhh");
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
	ft_printf("nigga");
	i = 0;
	map = malloc(sizeof(char *) * mlx->map_height);
	line = get_next_line(69);
	ft_printf("nigga2\n");
	while (line && !ft_strncmp(line, "(null)", ft_strlen(line)))
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
		if (line == NULL)
			return (map);
		map[i] = line;
		i++;
	}
	return (map);
}
