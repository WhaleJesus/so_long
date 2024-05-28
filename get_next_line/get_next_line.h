/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:13:13 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/28 15:13:23 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}	t_lst;

int		len_to_newline(t_lst *list);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstclear(t_lst **list, t_list *new_node, char *buf);
void	polish_list(t_lst **list);
char	*get_next_line(int fd);
char	*get_line(t_lst *list);
void	create_list(t_lst **list, int fd);
void	append(t_list **lst, char *buf);
int		found_newline(t_lst *list);
void	copy_str(t_lst *list, char *ret);

#endif
