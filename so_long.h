/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:31:06 by yuwu              #+#    #+#             */
/*   Updated: 2025/06/28 11:27:14 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h> //write, close
#include <stdlib.h> //malloc, free, exit
#include <fcntl.h> //open
#include <stdio.h> //perror
#include <string.h> //strerror
*/

//read??? do I need it, does it need header

#ifndef SO_LONG
# define SO_LONG

---------------------------------------------------
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
# include "./get_next_line/get_next_line.h"

# define SPACE "path to space.jpg"
# define WALL "path to wall.jpg"
# define FISH "path to fish.jpg"
# define DOOR "path to door.jpg"

//0 for an empty space,
//1 for a wall,		
//C for a collectible,
//E for a map exit,
//P for the player’s starting position.

typedef struct s_map
{
	int	dimension[2];
	int	player_location[2];
	int	exit_location[2];
	char	*1d_arr;
	char	**2d_arr;
}		t_map;

------------------------------------
//parsing.c 
//malloc arrays here
static void  malloc_and_dimention(t_map mp, char *file_name)
//malloc for t_map, and initiate every variables here
t_map   *init_map(char *file_name);

//inputcheck.c
//You must verify if there is a valid path in the map.
//varify exutability
int	check_file(char *filename);
{
	//if not exucutable
		return(1)
	//if ok;
		return (0);
}

//mapcheck.c
//element check: a map must contain 1 exit, 1 starting position and at least 1 collectible, and no empty space.
int	check_elements(t_map mp);	//11  1 as error and  0 as ok
//The map must be rectangular. return int as signals,
int	check_rectangular(t_map mp)	//12,  0 as ok
//The map must be enclosed/surrounded by walls.
int	check_closure(t_map mp); //13,  0 as ok
//The map cannnot be too big	
int	check_size(t_map mp);	//14,  0 as ok
//All the collectable and the exit need to be accessible
static int	check_accessibility(t_map mp);	//15,  0 as ok

//execution.c
//floodfill here???
//library here

//error.c
// this one send error msg according the the return int of check_all and exit with 1
void	errmsg_and_exit(char *msg, int	n);
//clean up and free things
void	free_t_map(t_map	map);
//this err exit happens after malloc, so it includes free, err mags and exit code
void	free_errmsg_and_exit(t_map	map, int map_error, int	n);

//main.c
//call all the functions above and return int as signal to error msg part
int	check_map_all(t_map mp);
//I am not sure should I exit or shoud I exit with some error code here???
int	main(int ac, char **av)
------------------------------------------------------

# endif
