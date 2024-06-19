/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:29:31 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/19 16:51:25 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_illegal_char(char c, t_mlx *mlx)
{
	if (!(c == 'P' || c == 'E' || c == 'C' || c == '1' || \
		c == '0' || c == '\n'))
	{
		ft_printf("ERROR\nMap contains illegal character\n");
		exit_program(mlx);
	}
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
