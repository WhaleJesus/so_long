/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:13:13 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/03 12:47:34 by sklaps           ###   ########.fr       */
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

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int		len_to_newline(t_list *list);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **list, t_list *new_node, char *buf);
void	polish_list(t_list **list);
char	*get_next_line(int fd);
char	*get_line(t_list *list);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buf);
int		found_newline(t_list *list);
void	copy_str(t_list *list, char *ret);

#endif
