/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/31 20:07:19 by fconde-p         ###   ########.fr       */
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

	str = malloc(43 * sizeof(char));
	bytes_read = read(fd, str, 42);
	str[bytes_read] = '\0';
	trimmed_line = trim_line(str);
	printf("TESTE ===> %s\n", trimmed_line);
	free(str);
	return (trimmed_line);
}