/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:19:52 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/04 17:23:13 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

typedef struct s_list
{
	char			*content;
	size_t				content_len;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*trim_line(char *str);
size_t	get_line_size(char *s);
int		get_nl_char(char *str);
t_list	*ft_lstnew(char *content);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif