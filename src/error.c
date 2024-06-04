/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:21:58 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/04 17:25:03 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_error(int error)
{
	char	*msg;

	if (error == 1)
		msg = "Wrong amount of args";

	ft_printf("Error: %s.\n", msg);
}
