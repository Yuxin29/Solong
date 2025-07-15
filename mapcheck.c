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
static int      check_one_elements(char c, t_map *mp)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (mp->1d_arr[i])
	{
		if (mp->1d_arr[i] == 'P')
			counter++; 
		i++;
	}
	return (counter);
}

//element check: a map must contain 1 exit, 1 starting position and at least 1 collectible.
//C for a collectible,
//E for a map exit,
//P for the player’s starting position.
int	check_elements(t_map mp);	
{
	int	counter_p;
	int	counter_c;
	int	counter_e;
	int	counter_empty;

	counter_p = check_one_elements('P', mp);
	counter_c = check_one_elements('C', mp);
	counter_e = check_one_elements('E', mp);
	counter_empty = check_one_elements(' ', mp);
	if (counter_p != 1 || counter_c != 1 || counter_e != 1 )
		return (1);
	if (counter_empty !)
		return (1); //should I use another signal here??? I will think about it in error msg later
	return (0);
}
//The map must be rectangular. return int as signals,
int	check_rectangular(t_map mp)
{
	int	line_width;
	int	line_nbr;

	line_nbr = 0;
	while (line_nbr < mp->dimension[0])
	{
		line_width = 0;
		while (line_width < mp->dimension[1])
			line_width++;
		if line_width != mp->dimension[1]
			retrun(1);
		line_nbr++;
	}
	return (0);
}

//The map must be enclosed/surrounded by walls.
static int	check_closure(t_map *mp)
{
	int	w;
	int	h;

	w = 0;
	while (mp->2d_arr[0][w])
	{
		if (mp->2d_arr[0][w] != '1')
			return (1);
		w++;
	}
	h = mp->dimension[0] - 1;
	w = 0;
	while (mp->2d_arr[h][w])
	{
		if (mp->2d_arr[h][w] != '1')
			return (1);
		w++;
	}
	h = 0;
	while (h < mp->dimension[0])
	{
		if (mp->2d_arr[h][0] != '1' || mp->2d_arr[h][mp->dimension[1] - 1] != '1')
			return (1);
		h++;
	}
	return (0);
}

//The map cannnot be too big
static int	check_size(t_map mp);
{
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
