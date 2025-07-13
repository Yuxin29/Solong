/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:53:57 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/13 19:54:12 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//using gnl to get the t_map.map
static char	**get_map(file xxx.ber)	

//getting dimentions of the map
//shoudl I malloc here or not
static int	*get_dimention(int	dimention[2], char **map_char)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map_char[i][j])
        j++;
    i++;
    while (map_char[i])
        i++;
    return {i, j};
}

//getting exit/god_location[2] from **map
static int	*get_location(char **map_char, char c)
{
    int i;
    int j;

    i = 0;
    while (map_char[i])
    {
        j = 0;
        while (map_char[i][j])
            j++
        i++;
    }
    return {i, j};
}

t_map	get_tmap(file xxx.ber) //in this one, call all fts as above
