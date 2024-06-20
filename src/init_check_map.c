/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:14:44 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/20 15:29:55 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_edges2(t_mlx *mlx, int i, int j)
{
	if ((j == 0 || j == (ft_strlen(mlx->map[i]) - 2)))
	{
		if (mlx->map[i][j] != '1')
		{
			ft_printf("Error: map is not enclosed");
			exit_program(mlx);
		}
	}
	if ((i == 0) || (i == mlx->map_height - 1))
	{
		if (mlx->map[i][j] != '1')
		{
			ft_printf("(%i,%i) Error: map is not enclosed\n", i, j);
			exit_program(mlx);
		}
	}
}

void	check_map_edges(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map_height)
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] != '\n')
			{
				check_map_edges2(mlx, i, j);
			}
			j++;
		}
		i++;
	}
}

int	check_map_char2(t_mlx *mlx, char *c, char **map, int i)
{
	int	j;
	int	num_c;

	num_c = 0;
	j = 0;
	while (map[i][j])
	{
		check_map_illegal_char(map[i][j], mlx);
		if (map[i][j] == c[0])
			num_c++;
		j++;
	}
	return (num_c);
}

int	check_map_char(t_mlx *mlx, char *c, int min, int max)
{
	int		num_c;
	int		i;
	int		j;
	char	**map;

	map = mlx->map;
	num_c = 0;
	i = 0;
	while (i < mlx->map_height)
	{
		num_c += check_map_char2(mlx, c, map, i);
		i++;
	}
	if (!((num_c >= min) && (num_c <= max)))
	{
		ft_printf("Error: please keep %s between %i and %i\n", c, min, max);
		exit_program(mlx);
	}
	return (num_c);
}

void	check_map_tokens(t_mlx *mlx)
{
	check_map_char(mlx, "P", 1, 1);
	check_map_char(mlx, "E", 1, 1);
	mlx->num_collectibles = check_map_char(mlx, "C", 1, INT_MAX);
}
