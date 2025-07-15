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

//call all the functions above and return int as signal to error msg part
int	check_map_all(t_map mp);
{
	if (check_elements(mp))
		return (11);
	if (check_rectangular(mp))
		return (12);		/this has to be check first
	if (check_closure(mp))
		return (13);
	if (check_size(mp))
		return (14);
	if (check_accessibility(mp))
		return (15);
	//....
	//if (check_other(mp)???)
	//	return (16);
}

int	main(int ac, char **av)
{
	t_map	mp;
	int		map_error;

	if (ac != 2)
		err_and_exit("wrong argument number", 1);
	if (check_file)
		err_and_exit("not valid file/path/ecutable", 1);
	mp = init_map(argc[1])
	if (!mp)
		err_and_exit("initiate map failed", 1);
	map_error = check_map_all(mp->map_char, mp->all_map_char)
	if (map_error)
		free_errmsg_and_exit(map, map_error, 1);
	//getting texture and excucate here, flood fill the map array with my picture, I DONT KNOW HOW TO DO IT YET
	return(0):
}
