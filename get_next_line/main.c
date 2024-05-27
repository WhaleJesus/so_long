/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:22:58 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/18 14:30:12 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../ft_printf/ft_printf.h"
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		ft_printf("%s", str);
	}
}
