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

//first initiate mp->2d_array using gnl
//then get 1d_array from 2 _d array
//I already malloc for both arrays before this steo
static void	get_map_arrays(t_map *mp, char *file_name)
{
    int     fd;
    char    *line;
    int     j;
    int     k;
    int     m;

    fd = open(file_name, 0_RDONLY);
    if (fd < 0)  //error exit here need to be reconsidered later
    {  
        perror("error openning file")
        exit(1)
    }
    j = 0;
    k = 0;
    while (line = get_next_line(fd))
    {
        m = 0;
        mp->2d_arr[j] = line;
        while(*line)
        {
            mp->1d_arr[k] = linep[m];
            k++;
            m++;
        }
        free(line);
        j++;
    }
    mp->2d_arr[j] = NULL;
    mp->1d_arr[k] = '\0';
    close(fd);
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
            if (mp->2d_arr[i][j] = 'P')
                mp->player_location = {i, j};
            if (mp->2d_arr[i][j] = 'E')
                mp->exit_location = {i, j};
            j++;    
        }
        i++;
    }
}

static void  malloc_and_dimention(t_map mp, char *file_name)
{
    int     line_count;
    int     char_count;
    char    *line;
    
    line_count = 0;
    char_count = 0;
    fd = open(file_name, RDONLY);
    if (fd < 0)
        //error and exit
    while (line = get_next_line(fd))
    {
        char_count += ft_strlen(line);
        mp->dimension[1] = ft_strlen(line); //this repeateddlly get the width of every line and end with the last one
        free(line);
        line_count++;
    }
    mp->2d_arr = malloc(sizeof(char *) * (line_count + 1));
    mp->1d_arr = malloc(sizeof(char) * (char_count + 1));
    mp->dimension[0] = line_count;
    close(fd);
    if (!mp->2d_arr)
        //error and free
    if (!mp->2d_arr)
        //error and free
}

//malloc for t_map, and initiate every variables here
t_map   *init_map(char *file_name)
{
    t_map   mp;

    mp = malloc(sizeof(t_map) * 1)
    if (!mp)
        return(NULL);
    mp->dimension[0] = 0;
    mp->dimension[1] = 0;
    mp->start_location[0] = 0;
    mp->start_location[1] = 0;
    mp->player_location[0] = 0;
    mp->player_location[1] = 0;
    mp->player_location[0] = 0;
    mp->player_location[1] = 0;
    mp->1d_arr = NULL;
    mp->2d_arr = NULL;
    malloc_and_dimention(mp, file_name);
    get_map_arrays(mp, file_name);
    get_location(mp);
    return (mp);
}
