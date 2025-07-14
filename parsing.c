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
//maybe this one first, it will get 1_d array of the chars with '/t' in the middle
//using gnl to get the t_map.map_char
static void	get_map_array(t_map mp, char *file_name)
{
    //first initiate mp->1d_array
    //then get 2d_array from 1_d array
}

//getting dimentions of the map
static void	get_dimention(t_map mp)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map_char[i][j])
        j++;
    mp->dimension[0] = i;
    i++;
    while (map_char[i])
        i++;
    mp->dimension[1] = j;
}

//getting exit/god_location[2] from **map
static void	get_location(t_map mp)
{
    int i;
    int j;

    i = 0;
    while (mp->2d_arr[i])
    {
        j = 0;
        while (mp->2d_arr[i][j])
        {
            //here 
            if (mp->2d_arr[i][j] = 'P')
                mp->player_location = {i, j};
            if (mp->2d_arr[i][j] = 'E')
                mp->exit_location = {i, j};
            j++;    
        }
        i++;
    }
}

//malloc for t_mao, and initiate every variables here
t_map   *init_map(char *file_name)
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
    get_map_array(mp, file_name);
    get_dimention(t_map mp);
    get_location(t_map mp);
}
