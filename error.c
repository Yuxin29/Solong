/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:31:09 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/14 16:31:12 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// this one send error msg according the the return int of check_all and exit with 1
void	errmsg_and_exit(char *msg, int	n);
{
    //putchar(msg);
    return (1);
}

//clean up and free things
void	free_t_map(t_map	mp);
{
    free(mp->dimention[0]);
    free(mp->dimention[1]);
    free(mp->player_location[0]);
    free(mp->player_location[1]);
    free(mp->exit_location[0]);
    free(mp->exit_location[1]);
    free(mp->1d_arr); //should I set this str to NULL as well???
    ft_free_split(mp->2d_arr);
    free (mp);
    mp = NULL;
}

//this err exit happens after malloc, so it includes free, err mags and exit code
void	free_errmsg_and_exit(t_map	map, int map_error, int	n);
{
	free_t_map(mp);
	if (map_error ==  11)
		//putstr("xxxxxxxx")
	else if (map_error ==  12)
		//putstr("xxxxxxxx")
	///
	else if (map_error ==  xxx)
		//putstr("xxxxxxxx")
	
}

