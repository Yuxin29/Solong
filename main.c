/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:47:11 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/14 16:47:25 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *file_name)
{
	if (access(file_name, F_OK) != 0)
		return (1);
	if (access(file_name, R_OK) != 0)
		return (0);
	return (0);
}

/*
int	main(void)
{
	mlx_t *mlx = mlx_init(300, 300, "Test Window", false);
	if (!mlx)
		return (1);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
*/

int	main(int ac, char **av)
{
	t_map	*mp;

	mp = NULL;
	if (ac != 2)
		errmsg_and_exit("wrong argument number\n", mp);
	if (check_file(av[1]))
		errmsg_and_exit("not existing/readable1\n", mp);
	mp = init_map(av[1]);
	if (!mp)
		errmsg_and_exit("initiate map failed\n", mp);
	check_map_all(mp);
	mlx_new_window(mp);
	texture_path(mp);
	init_instances(mp);
	mlx_key_hook(mp->mlx, keyboard_control, mp);
	ft_putstr_fd("Entering mlx loop\n", 1);
	mlx_loop(mp->mlx);
	mlx_terminate(mp->mlx);
	free_t_map(mp);
	return (0);
}
