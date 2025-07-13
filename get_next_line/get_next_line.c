/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:19:06 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/16 12:41:16 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
notes of new things used in get_next_line
- ssize_t: signed versiong of size_t(unsigned)
- read(fd, buffer, max): a bit like printf, returns(+, 0(EOF), -(error));
*/

#include "get_next_line.h"

static char	*ft_read_buffer(int fd, char *left_c)
{
	ssize_t		bytes_read;
	char		*buffer;
	char		*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(left_c), NULL);
	bytes_read = 1;
	temp = NULL;
	while (!left_c || (!ft_strchr(left_c, '\n') && bytes_read > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(left_c), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(left_c, buffer);
		if (!temp)
			return (free(buffer), free(left_c), NULL);
		free(left_c);
		left_c = temp;
	}
	return (free(buffer), left_c);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*temp;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_read_buffer(fd, remainder);
	if (!remainder || !remainder[0])
		return (free(remainder), remainder = NULL, NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = ft_substr(remainder, 0, i);
	if (!line)
		return (free(remainder), remainder = NULL, NULL);
	temp = ft_substr(remainder, i, ft_strlen(remainder) - i);
	free (remainder);
	remainder = temp;
	if (!remainder || !*remainder)
		return (free (remainder), remainder = NULL, line);
	return (line);
}
