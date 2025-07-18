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

//this should be called every time when a solid move is made
void	print_steps(t_map *mp)
{
	mp->steps++;
	ft_putnbr_fd(mp->steps, 1);
	ft_putchar_fd('\n', 1);
}

// this one send error msg and exit with 1 and free mp
void	errmsg_and_exit(char *msg, t_map *mp)
{
	ft_putstr_fd(msg, 2);
	if (mp)
		free_t_map(mp);
	exit (1);
}

//clean up and free things
//should I set this str arr_1d to NULL as well???
void	free_t_map(t_map	*mp)
{
	free(mp->arr_1d);
	ft_free_split(mp->arr_2d);
	free (mp->tex);
	free (mp->mlx);
	free (mp->player_inst);
	free (mp);
	mp = NULL;
}
