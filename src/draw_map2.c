/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:54:11 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/25 14:50:05 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_too_big(t_mlx *mlx)
{
	if (mlx->map_height * GRID_SIZE > SCREEN_HEIGHT || (mlx->map_width - 1)
		* GRID_SIZE > SCREEN_WIDTH)
	{
		ft_printf("ERROR\nPlease make map no bigger than: W:%i H:%i\n",
			SCREEN_WIDTH / GRID_SIZE, SCREEN_HEIGHT / GRID_SIZE);
		exit(0);
	}
}

char	**read_map2(t_mlx *mlx, int fd, int i, char *line)
{
	char	*line2;
	char	**map;

	map = malloc(sizeof(char *) * mlx->map_height);
	if (!map)
		display_error("map malloc failed", 0, mlx);
	while (line)
	{
		line = get_next_line(fd);
		if (NULL == line)
			break ;
		if (!ft_strchr(line, '\n'))
		{
			line2 = ft_strjoin(line, "\n");
			free(line);
			line = line2;
		}
		map[i] = line;
		i++;
	}
	free(line);
	return (map);
}

void	get_map_sizes3(char *line, int *error, int fd, t_mlx *mlx)
{
	char	*line2;
	int		width;

	width = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (NULL == line)
			break ;
		if (!ft_strchr(line, '\n'))
		{
			line2 = ft_strjoin(line, "\n");
			free(line);
			line = line2;
		}
		*(error) += get_map_sizes2(mlx, line, width);
	}
	free(line);
}
