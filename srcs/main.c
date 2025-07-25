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

//check the extension of the file or filename
int	check_extension(char *file_name)
{
	const char	*ext;

	ext = ft_strrchr(file_name, '.');
	if (!ext || ft_strncmp(ext, ".ber", 5) != 0)
		return (1);
	return (0);
}

//call all the map checkers functions above
void	check_map_all(t_map *mp)
{
	int	a;

	if (check_elements(mp))
		errmsg_and_exit("wrong element number / empty space\n", mp);
	if (check_rectangular(mp))
		errmsg_and_exit("not rectangular map\n", mp);
	if (check_closure(mp))
		errmsg_and_exit("not closed map\n", mp);
	if (check_size(mp))
		errmsg_and_exit("map too big\n", mp);
	if (check_invalid_chars(mp))
		errmsg_and_exit("invalid chars from the map\n", mp);
	a = check_accessibility(mp);
	if (a == 1)
		errmsg_and_exit("not all collectable/exit accessable\n", mp);
	if (a == 2)
		errmsg_and_exit("copy for check_accessibility failed\n", mp);
}

int	main(int ac, char **av)
{
	t_map	*mp;

	mp = NULL;
	if (ac != 2)
		errmsg_and_exit("wrong argument number\n", mp);
	if (check_extension(av[1]))
		errmsg_and_exit("wrong extension of the map file\n", mp);
	mp = init_map(av[1]);
	check_map_all(mp);
	mlx_new_window(mp);
	texture_path(mp);
	init_background(mp);
	init_instances(mp);
	mlx_key_hook(mp->mlx, keyboard_control, mp);
	mlx_close_hook(mp->mlx, handle_cross_click, mp);
	mlx_loop(mp->mlx);
	free_t_map(mp);
	return (0);
}
