/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:21:58 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/24 16:43:06 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_error(char *msg, int iexit, t_mlx *mlx)
{
	ft_printf("Error\n%s", msg);
	if (iexit == 0)
		exit(0);
	else if (iexit == 1)
		exit_program(mlx);
}
