/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:21:25 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/20 20:40:56 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
notes of new things used in get_next_line_binus
- static char *remainders[OPEN_MAX]: it is like **remainders, or *strs[1024]
- [OPEN_MAX]: max times of opennings, in <limits.h>
*/

#include "get_next_line_bonus.h"

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
	static char	*remainder[READ_MAX];
	char		*line;
	char		*temp;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= READ_MAX)
		return (NULL);
	remainder[fd] = ft_read_buffer(fd, remainder[fd]);
	if (!remainder[fd] || !remainder[fd][0])
		return (free(remainder[fd]), remainder[fd] = NULL, NULL);
	i = 0;
	while (remainder[fd][i] && remainder[fd][i] != '\n')
		i++;
	if (remainder[fd][i] == '\n')
		i++;
	line = ft_substr(remainder[fd], 0, i);
	if (!line)
		return (free (remainder[fd]), remainder[fd] = NULL, NULL);
	temp = ft_substr(remainder[fd], i, ft_strlen(remainder[fd]) - i);
	free (remainder[fd]);
	remainder[fd] = temp;
	if (!remainder[fd] || !*remainder[fd])
		return (free (remainder[fd]), remainder[fd] = NULL, line);
	return (line);
}
