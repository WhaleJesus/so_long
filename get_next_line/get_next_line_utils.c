/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:48:31 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/03 12:46:33 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_to_newline(t_list *list)
{
	int	i;
	int	k;

	i = 0;
	while (list)
	{
		k = 0;
		while (list->content[k])
		{
			if (list->content[k] == '\n')
			{
				return (i + 1);
			}
			++k;
			++i;
		}
		list = list->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **list, t_list *new_node, char *buf)
{
	t_list	*temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (new_node->content[0])
		*list = new_node;
	else
	{
		free(buf);
		free(new_node);
	}
}

void	copy_str(t_list *list, char *ret)
{
	int	i;
	int	k;

	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				ret[k++] = '\n';
				ret[k] = '\0';
				return ;
			}
			ret[k++] = list->content[i++];
		}
		list = list->next;
	}
	ret[k] = '\0';
}

void	polish_list(t_list **list)
{
	t_list	*new_node;
	t_list	*last_node;
	char	*buf;
	int		i;
	int		k;

	if (!list || !(*list))
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] != '\n' && last_node->content[i])
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	new_node->content = buf;
	new_node->next = NULL;
	ft_lstclear(list, new_node, buf);
}
