/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:11 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/05 16:54:49 by sklaps           ###   ########.fr       */
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
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error Opening Map file"));
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) != mlx->map_width && mlx->map_width != 0)
			// Give error that map is not rectangle
		mlx->map_width = ft_strlen(line);
		i++;
	}
	mlx->map_height = i;
	return (fd);
}

char	**read_map(char *path, t_mlx *mlx)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;
	
	fd = get_map_sizes(mlx, path);
	i = 0;
	map = malloc(sizeof(char *) * mlx->map_height);
	while (line)
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
