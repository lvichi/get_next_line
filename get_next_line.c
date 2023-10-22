/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:14:18 by lvichi            #+#    #+#             */
/*   Updated: 2023/10/22 21:40:37 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(int fd, ssize_t *read_return)
{
	char	*buffer;

	buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*read_return = read(fd, buffer, BUFFER_SIZE);
	if (*read_return <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

static char	*fill_line(char	*buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = 0;
	while (i-- > 0)
		line[i] = buffer[i];
	return (line);
}

static char	*new_buffer(char *buffer, size_t size)
{
	char	*new_buffer;
	size_t	i;

	if (size >= ft_strlen(buffer))
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(ft_strlen(buffer) - size + 1);
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (buffer[size])
		new_buffer[i++] = buffer[size++];
	new_buffer[i] = 0;
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp_buffer;
	ssize_t		read_return;

	read_return = 0;
	if (!buffer)
	{
		buffer = fill_buffer(fd, &read_return);
		if (!buffer)
			return (NULL);
	}
	while (!ft_strchr(buffer, '\n'))
	{
		temp_buffer = fill_buffer(fd, &read_return);
		if (!temp_buffer)
			break ;
		buffer = ft_strcat(buffer, temp_buffer);
	}
	line = fill_line(buffer);
	buffer = new_buffer(buffer, ft_strlen(line));
	if (read_return == -1)
	{
		free (line);
		return (NULL);
	}
	return (line);
}
