/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/07 17:36:29 by fconde-p         ###   ########.fr       */
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
		head = ft_lstnew(buffer);
		ft_lstadd_back(lst, head);
		free(buffer);
		if (bytes_read == 0)
			break ;
		// verify if buffer contains \n
		// if it does, stops function and deal with line at gnl()
	}
}

char	*mount_line(t_list *lst)
{
	size_t	line_size;
	char	*mounted_line;
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
	mounted_line = malloc((line_size + 1) * sizeof(char));
	cpy_ptr = mounted_line;
	while (lst != NULL)
	{
		temp_content = lst->content;
		while (*temp_content)
			*cpy_ptr++ = *temp_content++;
		lst = lst->next;
	}
	mounted_line[line_size] = '\0';
	return (mounted_line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	t_list	*lst;
	t_list	*head;
	// char	*remain;

	// check remain
	// if it has content, iterate till end or \n
	//  if has \n, return until \n and save new remain
	//  if has end of content, keep it to next read
	lst = NULL;
	write_content_to_nodes(buffer, fd, head, &lst);
	// mount_line(lst);
	free(buffer);
	// pass mounted line to pointer
	// keep until \n or end
	// save from \n forward at 'remain'
	return (mount_line(lst));
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
	free(str);
	return (0);
}