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
	int	dimention[2];
	int	god_location[2];
	int	exit_location[2];
	char	**map;
}		t_map;

//parsing.c 
static char	**get_map(file xxx.ber)		//using gnl to get the t_map.map
static int	*get_dimention(char **map)		//getting dimentions of the map
static int	*get_location(char **map, char c)  //getting exit/god_location[2] from **map
t_map	get_tmap(file xxx.ber) //in this one, call all fts as above

//inputcheck.c
//You must verify if there is a valid path in the map.
//varify exutability

//mapcheck.c
//element check: a map must contain 1 exit, 1 starting position and at least 1 collectible.
static int	check_elements(char **map);	
//The map must be rectangular. return int as signals,
static int	check_rectangular(char **map)
//element check: a map must contain no empty space.
static int	check_empty(char **map);
//The map must be enclosed/surrounded by walls.
static int	check_closure(char **map);
//The map cannnot be too big
static int	check_size(char **map);
//All the collectable and the exit need to be accessible
static int	check_accessibility
int	check_all(char **map) //call all the functions above and return int as signal to error msg part

//execution.c

//helper.c

//main.c

# endif
