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

static void	free_texture(t_map *mp)
{
	if (mp->tex)
	{
		if (mp->tex->img_empty)
			mlx_delete_image(mp->mlx, mp->tex->img_empty);
		if (mp->tex->img_wall)
			mlx_delete_image(mp->mlx, mp->tex->img_wall);
		if (mp->tex->img_collectable)
			mlx_delete_image(mp->mlx, mp->tex->img_collectable);
		if (mp->tex->img_exit)
			mlx_delete_image(mp->mlx, mp->tex->img_exit);
		if (mp->tex->img_player)
			mlx_delete_image(mp->mlx, mp->tex->img_player);
		free(mp->tex);
	}
}

//clean up and free things
void	free_t_map(t_map *mp)
{
	int	i;

	if (!mp)
		return ;
	ft_putstr_fd("free starts\n", 1);
	free_texture(mp);
	if (mp->arr_2d)
	{
		i = 0;
		while (mp->arr_2d[i])
			free(mp->arr_2d[i++]);
		free(mp->arr_2d);
	}
	if (mp->arr_1d)
		free(mp->arr_1d);
	if (mp->mlx)
		free(mp->mlx);
	free(mp);
	mp = NULL;
}
