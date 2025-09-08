/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/07 22:42:47 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	write_content_to_nodes(char *buffer, int fd, t_list *head, t_list **lst)
{
	ssize_t	bytes_read;
	
	bytes_read = 0;
	while (bytes_read >= 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		head = ft_lstnew(buffer, lst);
		free(buffer);
		if (bytes_read == 0)
			break ;
		// verify if buffer contains \n
		// if it does, stops function and deal with line at gnl()
	}
}

char	*mount_str(t_list *lst)
{
	size_t	line_size;
	char	*mounted_str;
	char	*temp_content;
	t_list	*head;
	char	*cpy_ptr;

	head = lst;
	line_size = 0;
	while (lst != NULL)
	{
		line_size += lst->content_len;
		lst = lst->next;
	}
	lst = head;
	mounted_str = malloc((line_size + 1) * sizeof(char));
	cpy_ptr = mounted_str;
	while (lst != NULL)
	{
		temp_content = lst->content;
		while (*temp_content)
			*cpy_ptr++ = *temp_content++;
		lst = lst->next;
	}
	mounted_str[line_size] = '\0';
	return (mounted_str);
}

char	*line_splitter(char *full_content, char *remain)
{
	char	*current_line;
	int		nl_index;
	int		i;
	size_t	full_content_size;

	full_content_size = 0;
	full_content_size = ft_strlen(full_content);
	i = 0;
	nl_index = 0;
	nl_index = get_nl_char(full_content);
	if (nl_index >= 0)
	{
		current_line = malloc((nl_index + 2) * sizeof(char));
		while (i <= nl_index)
		{
			current_line[i] = full_content[i];
			i++;
		}
		remain = malloc((full_content_size - nl_index++) * sizeof(char));
		i = 0;
		while (nl_index < (int)full_content_size)
			remain[i++] = full_content[nl_index++];
	}
	else
		return (NULL);
	return  (current_line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	t_list	*lst;
	t_list	*head;
	char	*full_content;
	char	*remain;

	lst = NULL;
	buffer = NULL;
	head = NULL;
	remain = NULL;
	write_content_to_nodes(buffer, fd, head, &lst);
	full_content = mount_str(lst);
	free(buffer);
	return (line_splitter(full_content, remain));
}
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char	*str;
	int		i;

	if (argc != 2)
		return (0);
	int	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < 2)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	return (0);
}