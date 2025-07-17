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

//0 for an empty space,
//1 for a wall,		
//C for a collectible,
//E for a map exit,
//P for the player’s starting position.
*/

#ifndef SO_LONG
# define SO_LONG

//header and libs
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/get_next_line/get_next_line.h"
# include "MLX42/MLX42.h"

//graphics macros
# define IMGSIZE 64
# define WIN_MAX_W 2560
# define WIN_MAX_H 1440

//image macros
# define SPACE "textures/empty.png"
# define WALL "textures/wall.png"
# define COLL "textures/collectable.png"
# define EXIT "textures/exit.png"
# define PLAYER "textures/player.png"

//keyboard macros
# define KEY_UP		MLX_KEY_W
# define KEY_DOWN	MLX_KEY_S
# define KEY_LEFT	MLX_KEY_A
# define KEY_RIGHT	MLX_KEY_D
# define KEY_ESC	MLX_KEY_ESCAPE

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
	int			exit_location[2];
	int			counter[2];
	int			steps;
	char		*arr_1d;
	char		**arr_2d;
	t_texture	*tex;
	mlx_t		*mlx;
	mlx_image_t	*player_inst;
}				t_map;

/* ----------------t_map handling------------parsing.c----------------------- */
void	get_map_arrays(t_map *mp, char *file_name);
void	get_location(t_map *mp);
void	malloc_and_dimension(t_map mp, char *file_name);
t_map	*init_map(char *file_name);

/* ------------------input check------------mapcheck.c----------------------- */
int		check_one_elements(char c, t_map *mp);
int		check_elements(t_map *mp);	//11  1 as error and  0 as ok
int		check_rectangular(t_map *mp); //12,  0 as ok
int		check_closure(t_map *mp); //13,  0 as ok	
int		check_size(t_map *mp);	//14,  0 as ok

/* -------------more input check------------accessibility_check.c------------ */
t_map	*map_copy(t_map *mp);
void	flood_fill(t_map *mp, int x, int y);
int		check_accessibility(t_map *mp);	//15,  0 as ok
void	check_map_all(t_map *mp);

/* ------------------initialise mlx windows-------init_mlx.c----------------- */
void	mlx_new_window(t_map *mp);
void	texture_path(t_map *mp);
void	init_instances(t_map *mp);

/* ------player control and game processing-------player_move.c-------------- */
void	keyboard_control(mlx_key_data_t keydata, void *param);
void	map_updating(t_map *mp);
void	map_collectable_refill(t_map *mp, int x, int y);
void	finish_game_by_player(t_map *mp, int x, int y);
void	print_steps(t_map *mp);

/* --------error management and exit cleannig up-------error.c--------------- */
void	errmsg_and_exit(char *msg, t_map *mp);
void	free_t_map(t_map	*map);
//void	quit_by_player(void);

/* --------error management and exit cleannig up-------main.c---------------- */
int		check_file(char *filename);
int		main(int ac, char **av);
//int	main(void);

#endif
