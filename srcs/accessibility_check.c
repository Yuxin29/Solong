/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:25:35 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/16 14:26:07 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_all_ints(t_map *mp_cp, t_map *mp)
{
	mp_cp->dimension[0] = mp->dimension[0];
	mp_cp->dimension[1] = mp->dimension[1];
	mp_cp->player_location[0] = mp->player_location[0];
	mp_cp->player_location[1] = mp->player_location[1];
	mp_cp->counter[0] = mp->counter[0];
	mp_cp->counter[1] = mp->counter[1];
}

t_map	*map_copy(t_map *mp)
{
	t_map	*mp_cp;
	int		i;
	int		len;

	i = 0;
	mp_cp = malloc(sizeof(t_map) * 1);
	if (!mp_cp)
		errmsg_and_exit("malloc for copy failed", mp);
	ft_bzero(mp_cp, sizeof(t_map));
	copy_all_ints(mp_cp, mp);
	len = ft_strlen(mp->arr_1d);
	mp_cp->arr_2d = malloc(sizeof(char *) * (mp->dimension[0] + 1));
	mp_cp->arr_1d = malloc(len + 1);
	if (!mp_cp->arr_2d || !mp_cp->arr_1d)
		free_t_map(mp);
	if (!mp_cp->arr_2d || !mp_cp->arr_1d)
		errmsg_and_exit("malloc for copy arr failed", mp_cp);
	while (i < mp->dimension[0])
	{
		mp_cp->arr_2d[i] = ft_strdup(mp->arr_2d[i]);
		i++;
	}
	mp_cp->arr_2d[i] = NULL;
	ft_memcpy(mp_cp->arr_1d, mp->arr_1d, len + 1);
	return (mp_cp);
}

//recursive call to fill all the map with F as filled
void	flood_fill(t_map *mp, int x, int y)
{
	if (mp->arr_2d[y][x] == '1' || mp->arr_2d[y][x] == 'F')
		return ;
	mp->arr_2d[y][x] = 'F';
	flood_fill(mp, x + 1, y);
	flood_fill(mp, x - 1, y);
	flood_fill(mp, x, y + 1);
	flood_fill(mp, x, y - 1);
}

//All the collectable and the exit need to be accessible
int	check_accessibility(t_map *mp)
{
	t_map	*mp_cp;
	int		y;
	int		x;

	mp_cp = map_copy(mp);
	flood_fill(mp_cp, mp->player_location[1], mp->player_location[0]);
	y = 0;
	while (y < mp_cp->dimension[0])
	{
		x = 0;
		while (mp_cp->arr_2d[y][x])
		{
			if (mp_cp->arr_2d[y][x] == 'C' || mp_cp->arr_2d[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	free_t_map(mp_cp);
	return (0);
}
