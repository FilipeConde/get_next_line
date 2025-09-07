/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/07 18:51:07 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*node;
	char	*temp_cont;

	node = malloc(1 * sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = malloc((ft_strlen(content) + 1) * sizeof(char));
	temp_cont = node->content;
	while (*content)
	{
		*temp_cont++ = *content++;
	}
	*temp_cont = '\0';
	node->content_len = ft_strlen(node->content);
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	get_nl_char(char *str)
{
	int	nl_index;

	nl_index = 0;
	while (str[nl_index] != '\0' && str[nl_index] != '\n')
	{
		nl_index++;
	}
	if (str[nl_index] == '\0')
		nl_index = -1;
	else if (str[nl_index] == '\n')
		return (nl_index);
	return (-1);
	
}
