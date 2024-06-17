/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:50:33 by fdaems            #+#    #+#             */
/*   Updated: 2024/06/17 11:37:01 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	is_new_line(t_lst *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	lst = gnl_lstlast(lst);
	while (lst -> content[i] && i < BUFFER_SIZE)
	{
		if (lst -> content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	make_list(t_lst **lst, int fd)
{
	int		n;
	char	*buf;

	while (!is_new_line(*lst))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		n = read(fd, buf, BUFFER_SIZE);
		if (!n)
		{
			free(buf);
			return ;
		}
		buf[n] = '\0';
		gnl_lstadd_back(lst, buf);
	}
}

unsigned int	count_chars(t_lst **lst)
{
	unsigned int	n;
	unsigned int	i;
	t_lst			*now;

	if (*lst == NULL)
		return (0);
	now = *lst;
	n = 0;
	while (now)
	{
		i = 0;
		while (now -> content[i])
		{
			if (now -> content[i] == '\n')
			{
				n++;
				return (n);
			}
			i++;
			n++;
		}
		now = now -> next;
	}
	return (n);
}

char	*make_string(t_lst **lst)
{
	char			*d;
	unsigned int	len;

	if (!*lst)
		return (NULL);
	len = count_chars(lst);
	d = (char *)malloc(len + 1);
	if (!d)
		return (NULL);
	copy_str(lst, d);
	return (d);
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;
	char			*line;

	if (!lst)
		lst = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	make_list(&lst, fd);
	if (lst == NULL)
		return (NULL);
	line = make_string(&lst);
	start_new(&lst);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	char	*line;
	int		i;
	int		fd1;

	// Open the files
	fd1 = open("test", O_RDONLY);

	i = 1;
	while ((line = get_next_line(fd1)))
	{
		printf("line [%02d] from file 1: %s\n", i, line);
		free(line);
		i++;
	}

	// Close the files
	close(fd1);

	return (0);

}
*/
