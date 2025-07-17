/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:53:57 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/16 14:41:01 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//first initiate mp->2d_array using gnl
//then get 1d_array from 2 _d array
//I already malloc for both arrays before this steo
void	get_map_arrays(t_map *mp, char *file_name)
{
	int		fd;
	char	*line;
	int		j;
	int		k;	
	int		m;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		errmsg_and_exit("openning file failed\n", mp);
	j = 0;
	k = 0;
	line = get_next_line(fd);
	while (line)
	{
		int len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		line[len] = '\0';
		mp->arr_2d[j] = ft_strdup(line);
		m = 0;
		while (line[m] && line[m] != '\n')
		{
			mp->arr_1d[k] = line[m];
			k++;
			m++;
		}
		free(line);
		j++;
		line = get_next_line(fd);
	}
	mp->counter[1] = k;
	mp->arr_2d[j] = NULL;
	mp->arr_1d[k] = '\0';
	close(fd);
}

//getting exit/god_location[2] from **map
void	get_location(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (mp->arr_2d[i])
	{
		j = 0;
		while (mp->arr_2d[i][j])
		{
			if (mp->arr_2d[i][j] == 'P')
			{
				mp->player_location[0] = i;
				mp->player_location[1] = j;
			}
			if (mp->arr_2d[i][j] == 'E')
			{
				mp->exit_location[0] = i;
				mp->exit_location[1] = j;
			}
			j++;
		}
		i++;
	}
}

void	malloc_and_dimention(t_map *mp, char *file_name)
{
	int		line_count;
	int		char_count;
	int		fd;
	char	*line;

	line_count = 0;
	char_count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		errmsg_and_exit("openning file failed\n", mp);
	line = get_next_line(fd);
	while (line)
	{
		if (mp->dimension[1] == 0 && line[ft_strlen(line) - 1] == '\n')
			mp->dimension[1] = ft_strlen(line) - 1;
		else if (mp->dimension[1] == 0)
			mp->dimension[1] = ft_strlen(line);
		char_count += ft_strlen(line);
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	mp->dimension[0] = line_count;
	close(fd);
	mp->arr_2d = malloc(sizeof(char *) * (line_count + 1));
	mp->arr_1d = malloc(sizeof(char) * (char_count + 1));
	if (!mp->arr_2d || !mp->arr_1d)
	{
		free_t_map(mp);
		errmsg_and_exit("malloc array failed\n", mp);
	}
}

//malloc for t_map, and initiate every variables here
t_map	*init_map(char *file_name)
{
	t_map	*mp;

	mp = malloc(sizeof(t_map) * 1);
	if (!mp)
		return (NULL);
	mp->dimension[0] = 0;
	mp->dimension[1] = 0;
	mp->player_location[0] = 0;
	mp->player_location[1] = 0;
	mp->exit_location[0] = 0;
	mp->exit_location[1] = 0;
	mp->counter[0] = 0;
	mp->counter[1] = 0;
	mp->steps = 0;
	mp->arr_1d = NULL;
	mp->arr_2d = NULL;
	mp->mlx = NULL;
	malloc_and_dimention(mp, file_name);
	mp->tex = malloc(sizeof(t_texture));
	
	if (!mp->tex)
		errmsg_and_exit("malloc for map texture failed\n", mp);
	get_map_arrays(mp, file_name);
	get_location(mp);
	return (mp);
}
