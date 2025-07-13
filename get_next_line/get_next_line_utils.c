/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:20:20 by yuwu              #+#    #+#             */
/*   Updated: 2025/05/15 14:35:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (count);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	l1;
	size_t	l2;
	char	*join;
	size_t	i;

	if (!str1 && !str2)
		return (NULL);
	l1 = ft_strlen(str1);
	l2 = ft_strlen(str2);
	join = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		join[i] = str1[i];
		i++;
	}
	while (i < l1 + l2)
	{
		join[i] = str2[i - l1];
		i++;
	}
	join[l1 + l2] = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	n;
	size_t	max;

	if (!s)
		return (NULL);
	max = ft_strlen((char *)s);
	if (start >= max)
		len = 0;
	if (start + len > max)
		len = max - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	n = 0;
	while (s[start + n] && n < len)
	{
		sub[n] = s[start + n];
		n++;
	}
	sub[n] = '\0';
	return (sub);
}
