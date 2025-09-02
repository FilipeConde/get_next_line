/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/09/02 19:38:51 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// read, malloc, free
char	*get_next_line(int fd)
{
	char	*str;
	char	*trimmed_line;
	ssize_t	bytes_read;
	int		buffer;

	printf("TESTE BUFFER => %d\n", BUFFER_SIZE);
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, str, BUFFER_SIZE);
	str[bytes_read] = '\0';
	trimmed_line = trim_line(str);
	printf("TESTE ===> %s\n", trimmed_line);
	free(str);
	return (trimmed_line);
}