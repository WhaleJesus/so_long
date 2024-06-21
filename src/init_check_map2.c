/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:29:31 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/21 14:10:08 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_illegal_char(char c, t_mlx *mlx)
{
	if (!(c == 'P' || c == 'E' || c == 'C' || c == '1' || \
		c == '0' || c == '\n'))
		display_error("ERROR\nMap contains illegal character", 1, mlx);
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
	ft_printf("ERROR\nMap extension must be '.ber'");
	exit(0);
}
