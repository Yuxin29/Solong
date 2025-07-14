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

//this is a static helper to check how many times one element appears in this map
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
static int	check_elements(t_map mp);	
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
static int	check_rectangular(t_map mp)
{
	int	line_width;
	int	line_nbr;

	//it went though all the lines and check if every line_width is the same
	//return signals: 1 as error and  0 as ok
}

//The map must be enclosed/surrounded by walls.
static int	check_closure(t_map mp);
{

	//return signals: 1 as error and  0 as ok
}
//The map cannnot be too big
static int	check_size(t_map mp);
{
	//related to the pixels of the jpg elements and the resolutions of the specific screen
	//return signals: 1 as error and  0 as ok
}

//All the collectable and the exit need to be accessible
static int	check_accessibility(t_map mp);
{
	//I do I check this???
	//I can get the nbr of collectables
	//Do I go to each of them and check if it is soroounded?
	//Do I need another static checker for soroundability???
}

//call all the functions above and return int as signal to error msg part
int	check_map_all(t_map mp);
{
	if (check_elements(mp))
		return (11);
	if (check_rectangular(mp))
		return (12);
	if (check_closure(mp))
		return (13);
	if (check_size(mp))
		return (14);
	if (check_accessibility(mp))
		return (15);
	//if (check_other(mp)???)
	//	return (16);
	//....
}