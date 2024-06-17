/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:05:51 by fdaems            #+#    #+#             */
/*   Updated: 2024/06/17 11:38:34 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}					t_lst;

void				copy_str(t_lst **lst, char *d);
void				gnl_lstadd_back(t_lst **lst, char *buf);
t_lst				*gnl_lstlast(t_lst *lst);
char				*get_next_line(int fd);
char				*make_string(t_lst **lst);
unsigned int		count_chars(t_lst **lst);
t_lst				*make_new_line(t_lst **lst, int fd);
int					is_new_line(t_lst *lst);
void				gnl_lstclear(t_lst **lst, t_lst *new, char *buf);
void				start_new(t_lst **lst);

#endif
