/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:06:38 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/16 14:45:03 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//helper to check how many times one element appears in this map
int	check_one_elements(char c, t_map *mp)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (mp->arr_1d[i])
	{
		if (mp->arr_1d[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

//a map must contain 1 exit, 1 starting position and at least 1 collectible.
//C for a collectible,
//E for a map exit,
//P for the player’s starting position.
int	check_elements(t_map *mp)
{
	int	counter_p;
	int	counter_c;
	int	counter_e;
	int	counter_empty;

	counter_p = check_one_elements('P', mp);
	counter_c = check_one_elements('C', mp);
	counter_e = check_one_elements('E', mp);
	counter_empty = check_one_elements(' ', mp);
	if (counter_p != 1 || counter_c < 1 || counter_e != 1)
		return (1);
	if (counter_empty)
		return (1);
	return (0);
}

//The map must be rectangular. return int as signals,
int	check_rectangular(t_map *mp)
{
	int	line_width;
	int	i;

	i = 0;
	while (mp->arr_2d[i])
	{
		line_width = ft_strlen(mp->arr_2d[i]);
		if (mp->arr_2d[i][line_width] == '\n')
			line_width--;
		if (line_width != mp->dimension[1])
			return (1);
		i++;
	}
	return (0);
}

//The map must be enclosed/surrounded by walls.
int	check_closure(t_map *mp)
{
	int	w;
	int	h;

	w = 0;
	h = mp->dimension[0] - 1;
	while (mp->arr_2d[h][w])
	{
		if (mp->arr_2d[0][w] != '1')
			return (1);
		if (mp->arr_2d[h][w] != '1')
			return (1);
		w++;
	}
	h = 0;
	while (h < mp->dimension[0])
	{
		if (mp->arr_2d[h][0] != '1')
			return (1);
		if (mp->arr_2d[h][mp->dimension[1] - 1] != '1')
			return (1);
		h++;
	}
	return (0);
}

//The map cannnot be too big
int	check_size(t_map *mp)
{
	if (mp->dimension[0] > WIN_MAX_H / IMGSIZE)
		return (1);
	if (mp->dimension[1] > WIN_MAX_W / IMGSIZE)
		return (1);
	return (0);
}
