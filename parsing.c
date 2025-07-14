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

//using gnl to get the t_map.map_char
static void	get_2d_map(t_map mp, char *file_name)
{

}

//using gnl to get the t_map.map_char
static void	get_1d_map(t_map mp)
{
    
}

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

//in this one, malloc and call all fts as above
t_map	malloc_tmap(void)
{
    t_map   mp;

    mp = malloc(sizeof(t_map) * 1)
    if (!mp)
        return(NULL);
    mp->dimension = {0, 0};
    mp->start_location = {0, 0};
    mp->player_location = {0, 0};
    mp->exit_location = {0, 0};
    map->2d_char=NULL;
    map->1d_char=NULL;
}
