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

//call all the functions above and return int as signal to error msg part
	//other wrong cases like map too small 3 x 3 ?
void	check_map_all(t_map *mp)
{
	if (check_elements(mp))
		errmsg_and_exit("wrong element number\n", mp);
	if (check_rectangular(mp))
		errmsg_and_exit("not rectangular map\n", mp);
	if (check_closure(mp))
		errmsg_and_exit("not closed map\n", mp);
	if (check_size(mp))
		errmsg_and_exit("map too big\n", mp);
	if (check_accessibility(mp))
		errmsg_and_exit("not all collectable/exit accessable\n", mp);
}

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
	init_background(mp);
	init_instances(mp);
	mlx_key_hook(mp->mlx, keyboard_control, mp);
	mlx_loop(mp->mlx);
	ft_putstr_fd("so far so good\n", 1);
	free_t_map(mp);
	return (0);
}
