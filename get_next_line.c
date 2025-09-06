/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/05 22:34:07 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	// char	*trimmed_line;
	ssize_t	bytes_read;
	char	*buffer;
	t_list	**lst;
	// char	*remain;

	bytes_read = 0;
	//start loop
	lst = NULL;
	while (bytes_read >= 0)
	{
		// memmory allocation for buffer (buffer size plus one)
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		// read file to buffer;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		*lst = ft_lstnew(buffer);
		
		free(buffer);
		// if reads EOF, break
		if (bytes_read == 0)
			break ;
	}
	// trimmed_line = trim_line(str);
	free(buffer);
	return (NULL);
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