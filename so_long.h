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
	char	**map_char;
	char	*all_map_char;
}		t_map;

//parsing.c 
static char	**get_map(file xxx.ber)		//using gnl to get the t_map.map
static int	*get_dimention(int	dimention[2], char **map_char)		//getting dimentions of the map
static int	*get_location(char **map_char, char c)  //getting exit/god_location[2] from **map
t_map	get_tmap(file xxx.ber) //in this one, call all fts as above

//inputcheck.c
//You must verify if there is a valid path in the map.
//varify exutability

//mapcheck.c
//element check: a map must contain 1 exit, 1 starting position and at least 1 collectible, and no empty space.
int	check_elements(char *all_map_char);	


//The map must be rectangular. return int as signals,
int	check_rectangular(char **map_char)
//The map must be enclosed/surrounded by walls.
int	check_closure(char **map_char);
//The map cannnot be too big
int	check_size(char **map_char);
//All the collectable and the exit need to be accessible
static int	check_accessibility
int	check_all(char **map_char) //call all the functions above and return int as signal to error msg part

//error.c
void	send_err_msg(int	n)// this one send error msg according the the return int of check_all

//execution.c

//helper.c

//main.c

# endif
