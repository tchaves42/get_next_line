/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaves <tchaves@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:12:46 by tchaves           #+#    #+#             */
/*   Updated: 2023/11/01 15:21:28 by tchaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	int		bytesread;
	char	*readbuf;

	readbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readbuf)
		return (readbuf);
	bytesread = read(fd, readbuf, BUFFER_SIZE);
	if (bytesread == 0)
	{
		free(readbuf);
		return (ft_strdup(""));
	}
	readbuf[bytesread] = 0;
	if (bytesread < 0)
	{
		free(readbuf);
		return (0);
	}
	else
		return (readbuf);
}

char	*check_line(char *stored_buf, char *line, int newline_index)
{
	char	*temp;

	if (!stored_buf)
		return (0);
	newline_index = ft_strchr(stored_buf, '\n');
	ft_strlcpy(line, stored_buf, newline_index + 2);
	temp = stored_buf;
	stored_buf = ft_strdup(stored_buf + newline_index + 1);
	if (temp)
		free (temp);
	return (stored_buf);
}

char	*check_end(char *stored_buf, char *temp)
{
	if (temp == 0)
	{
		if (stored_buf)
			free(stored_buf);
		return (0);
	}
	if (ft_strlen(stored_buf) > 0)
	{
		free (temp);
		return (stored_buf);
	}
	free (temp);
	free (stored_buf);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stored_buf;
	char		*line;
	int			newline_index;

	if (fd < 0)
		return (0);
	while (1)
	{
		newline_index = ft_strchr(stored_buf, '\n');
		if ( newline_index >= 0)
		{
			line = malloc((newline_index + 2) * sizeof(*line));
			stored_buf = check_line(stored_buf, line, newline_index);
			return (line);
		}
		line = ft_read(fd);
		if (ft_strlen(line) == 0)
		{
			line = check_end(stored_buf, line);
			stored_buf = 0;
			return (line);
		}
		stored_buf = ft_strjoin(stored_buf, line);
	}
}