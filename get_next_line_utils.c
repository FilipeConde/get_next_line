/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/05 19:06:19 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*node;

	node = malloc(1 * sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = malloc(ft_strlen(content) + 1);
	while (*content)
	{
		*(node->content)++ = *content++;
	}
	node->content_len = ft_strlen(content);
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

size_t	get_line_size(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
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
		nl_index = 0;
	else if (str[nl_index] == '\n')
		return (nl_index);
	return (0);
	
}

char *trim_line(char *str)
{
	char	*trimmed_line;
	char	*ptr_trimmed;
	size_t	line_size;

	line_size = get_line_size(str);
	trimmed_line = malloc((line_size * sizeof(char)) + 1);
	ptr_trimmed = trimmed_line;
	while (*str)
	{
		*ptr_trimmed = *str;
		if (*str == '\n')
			return (trimmed_line);
		str++;
		ptr_trimmed++;
	}
	return (trimmed_line);
}
