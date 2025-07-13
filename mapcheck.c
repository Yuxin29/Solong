/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:06:38 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/13 19:12:53 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int      check_one_elements(char c, char *all_map_char)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (all_map_char[i])
	{
		if (all_map_char[i] = 'P')
			counter++; 
		i++;
	}
	return (counter);
}

//element check: a map must contain 1 exit, 1 starting position and at least 1 collectible.
//C for a collectible,
//E for a map exit,
//P for the player’s starting position.
static int	check_elements(char *all_map_char);	
{
	int	counter_p;
	int	counter_c;
	int	counter_e;
	int	counter_empty;

	counter_p = check_one_elements('P', all_map_char);
	counter_c = check_one_elements('C', all_map_char);
	counter_e = check_one_elements('E', all_map_char);
	counter_empty = check_one_elements(' ', all_map_char);
	if (counter_p != 1 || counter_c != 1 || counter_e != 1 )
		return (1);
	if (counter_empty !)
		return (1); //should I use another signal here??? I will think about it in error msg later
	return ()
}
//The map must be rectangular. return int as signals,
static int	check_rectangular(char **map)

//The map must be enclosed/surrounded by walls.
static int	check_closure(char **map);
//The map cannnot be too big
static int	check_size(char **map);
//All the collectable and the exit need to be accessible
static int	check_accessibility
int	check_all(char **map) //call all the functions above and return int as signal to error msg part