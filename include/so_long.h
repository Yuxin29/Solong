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
#include <unistd.h> //write, close, read??
#include <stdlib.h> //malloc, free, exit
#include <fcntl.h> //open
#include <stdio.h> //perror
#include <string.h> //strerror

//0: empty space,
//1: wall,		
//C: collectible,
//E: exit,
//P: player’s starting position.

** ************************************************************************** **
init_map.c    --->  +--------------------------+	--->  utils.c   
    |               | malloc & dimension       |			|
    |           	| get 1D/2D arrays         |---> err msg, free & exit 1
	|               | locate player            |			|
    |               +--------------------------+			|
	|														|
mapcheck.c    --->  +--------------------------+			|
    |               | check elements           |			|
    |               | check rectangle          |			|
    |               | check closure            |---> err msg, free & exit 1
    |               | check size               |			|
    |               +--------------------------+			|
	|														|	
accessibility_--->	+--------------------------+			|
 check.c            | copy map and flood fill  |---> err msg, free & exit 1
    |               | check accessibility      |			|
    |               +--------------------------+			|
	|														|
init_mlx.c   --->   +--------------------------+			|
    |               | create window            |			|
    |               | load textures            |			|
    |               | draw background          |---> err msg, free & exit 1
    |               | draw characters          |			|
    |               +--------------------------+			|
	|														|
player_move.c --->  +--------------------------+			|
    |               | keyboard input           |			|
    |               | move player              |			|
    |               | update map & print steps |---> err msg, free & exit 1  
    |               | check win condition      |			|
    |               +--------------------------+			|
	|														|
main.c        --->  +--------------------------+			|
                    | check arguments          |			|
                    | init & verify map        |			|
                	| set mlx hooks            |--> if success, free & exit 0
                    | start mlx_loop           |
					| win: free and close win  |
                    +--------------------------+
** ************************************************************************** **
*/

#ifndef SO_LONG_H
# define SO_LONG_H

//header and libs
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42/MLX42.h"

//graphics macros
# define IMGSIZE 64
# define WIN_MAX_W 3840
# define WIN_MAX_H 2160

//image macros
# define SPACE "textures/empty.png"
# define WALL "textures/wall.png"
# define COLL "textures/collectable.png"
# define EXIT "textures/exit.png"
# define PLAYER "textures/player.png"

typedef struct s_texture
{
	mlx_image_t	*img_empty;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_collectable;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_player;
}	t_texture;

typedef struct s_map
{
	int			dimension[2];
	int			player_location[2];
	//int			exit_location[2];
	int			counter[2];
	int			steps;
	char		*arr_1d;
	char		**arr_2d;
	t_texture	*tex;
	mlx_t		*mlx;
	mlx_image_t	*player_inst;
}				t_map;

//input parsing and t_map initiation
//init_map.c
void	get_2d_arrays(t_map *mp, char *file_name);
void	get_1d_arrays(t_map *mp);
void	get_location(t_map *mp);
void	malloc_and_dimension(t_map mp, char *file_name);
t_map	*init_map(char *file_name);

//map precheck
// mapcheck.c
int		get_element_number(char c, t_map *mp);
int		check_elements(t_map *mp);	//11  1 as error and  0 as ok
int		check_rectangular(t_map *mp); //12,  0 as ok
int		check_closure(t_map *mp); //13,  0 as ok	
int		check_size(t_map *mp);	//14,  0 as ok

//map postcheck
//accessibility_check.c
void	copy_all_ints(t_map *mp_cp, t_map *mp);
t_map	*map_copy(t_map *mp);
void	flood_fill(t_map *mp, int x, int y);
int		check_accessibility(t_map *mp);	//15,  0 as ok

//map mlx window, texture and instance initiation
//init_mlx.c
void	mlx_new_window(t_map *mp);
void	texture_path(t_map *mp);
void	init_background(t_map *mp);
void	init_instances(t_map *mp);

//player control and game processing
//player_move.c
void	map_updating(t_map *mp);
void	map_collectable_refill(t_map *mp, int x, int y);
void	finish_game_by_player(t_map *mp, int x, int y);
void	move(t_map *mp, int x_new, int y_new);
void	keyboard_control(mlx_key_data_t keydata, void *param);

//error management and exit cleannig up
// utils.c
void	print_steps(t_map *mp);
void	errmsg_and_exit(char *msg, t_map *mp);
void	handle_cross_click(void *param);
void	free_texture(t_map *mp);
void	free_t_map(t_map	*map);

//check extension, check map and initiate window, loop through and terminate
//main.c
int		check_extension(char *filename);
void	check_map_all(t_map *mp);
int		main(int ac, char **av);

#endif
