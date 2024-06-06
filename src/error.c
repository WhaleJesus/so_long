/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:21:58 by sklaps            #+#    #+#             */
/*   Updated: 2024/06/06 16:23:33 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_error(int error)
{
	char	*msg;

	if (error == 1)
		msg = "Wrong amount of args";
	if (error == 2)
		msg = "map size does not represent square or rechthoek";

	ft_printf("Error: %s.\n", msg);
}
