/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:50 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/30 16:27:33 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read, malloc, free
char	*get_next_line(int fd)
{
	char	*str;
	ssize_t	bytes_read;

	str = malloc(20 * sizeof(char));
	bytes_read = read(fd, str, 19);
	str[bytes_read] = '\0';
	return (str);
}