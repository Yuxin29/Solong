/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	if (mp)
		free_t_map(mp);
	exit (1);
}

void	handle_cross_click(void *param)
{
	t_map	*mp;

	mp = (t_map *)param;
	free_t_map(mp);
	ft_putstr_fd("You closed the window early\n", 1);
	exit(0);
}

void	free_texture(t_map *mp)
{
	if (!mp || !mp->tex)
		return ;
	if (mp->tex->img_empty && mp->mlx)
		mlx_delete_image(mp->mlx, mp->tex->img_empty);
	if (mp->tex->img_wall && mp->mlx)
		mlx_delete_image(mp->mlx, mp->tex->img_wall);
	if (mp->tex->img_collectable && mp->mlx)
		mlx_delete_image(mp->mlx, mp->tex->img_collectable);
	if (mp->tex->img_exit && mp->mlx)
		mlx_delete_image(mp->mlx, mp->tex->img_exit);
	if (mp->tex->img_player && mp->mlx)
		mlx_delete_image(mp->mlx, mp->tex->img_player);
	free(mp->tex);
	mp->tex = NULL;
}

//clean up and free things
void	free_t_map(t_map *mp)
{
	int	i;

	if (!mp)
		return ;
	free_texture(mp);
	if (mp->arr_2d)
	{
		i = 0;
		while (mp->arr_2d[i])
		{
			free(mp->arr_2d[i]);
			i++;
		}
		free(mp->arr_2d);
	}
	if (mp->arr_1d)
		free(mp->arr_1d);
	if (mp->mlx != NULL)
		mlx_terminate(mp->mlx);
	free(mp);
	mp = NULL;
}
