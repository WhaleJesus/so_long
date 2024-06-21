/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:21:58 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/21 14:08:52 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_error(char *msg, int iexit, t_mlx *mlx)
{
	ft_printf("ERROR\n%s", msg);
	if (iexit == 0)
		exit(0);
	else if (iexit == 1)
		exit_program(mlx);
}
