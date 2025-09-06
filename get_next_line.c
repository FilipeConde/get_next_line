/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/06 19:30:53 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	write_content_to_nodes(char *buffer, int fd, t_list *head, t_list **lst)
{
	ssize_t	bytes_read;
	char	*mounted_line;

	bytes_read = 0;
	while (bytes_read >= 0)
	{
		// memmory allocation for buffer (buffer size plus one)
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		// read file to buffer;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		head = ft_lstnew(buffer);
		ft_lstadd_back(lst, head);
		// if reads EOF, break
		if (bytes_read == 0)
			break ;
	}
}

char	*mount_line(t_list *lst)
{
	size_t	line_size;

	line_size = 0;
	while (lst != NULL)
	{
		line_size += lst->content_len;
		lst = lst->next;
	}
	// printf("TAMANHO DA LINHA: %zu\n", line_size);
	return ("teste");
}

char	*get_next_line(int fd)
{
	char	*buffer;
	t_list	*lst;
	t_list	*head;
	// char	*remain;

	//start loop
	lst = NULL;
	write_content_to_nodes(buffer, fd, head, &lst);
	mount_line(lst);
	free(buffer);
	return (lst->content);
}
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char	*str;

	if (argc != 2)
		return (0);
	int	fd = open(argv[1], O_RDONLY);

	str = get_next_line(fd);
	printf("%s\n", str);
	//free(str);
	return (0);
}