/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:26:24 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/16 14:26:44 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//be called every time when the keyboard control turned out to be a valid one
void	map_normal_move(t_map *mp, int x, int y)
{
	mp->player_inst->instances[0].x = x * IMGSIZE;
	mp->player_inst->instances[0].y = y * IMGSIZE;
}

//when the keyboard control turn out to be towards a collectable?
void	map_collecting_move(t_map *mp, int x, int y)
{
	int	i;

	i = 0;
	if (mp->arr_2d[y][x] == 'C')
	{
		mp->counter[0]++;
		mp->arr_2d[y][x] = '0';
		i = 0;
		while (i < mp->counter[0])
		{
			if (mp->tex->img_collectable->instances[i].x == x * IMGSIZE)
			{
				if (mp->tex->img_collectable->instances[i].y == y * IMGSIZE)
				{
					mp->tex->img_collectable->instances[i].enabled = false;
					break ;
				}
			}
			i++;
		}
	}
}

//end game after collecting every thing and enter exit
void	map_exit_move(t_map *mp, int x, int y)
{
	if (mp->arr_2d[y][x] == 'E' && mp->counter[0] == mp->counter[1])
	{
		ft_putstr_fd("Victory\n", 1);
		mlx_close_window(mp->mlx);
		free_t_map(mp);
	}
}

void	move(t_map *mp, int x_new, int y_new)
{
	if (mp->arr_2d[y_new][x_new] == '1')
		return ;
	mp->player_location[0] = y_new;
	mp->player_location[1] = x_new;
	map_normal_move(mp, x_new, y_new);
	map_collecting_move(mp, x_new, y_new);
	map_exit_move(mp, x_new, y_new);
	print_steps(mp);
}

//this checks the move and if it is valid, and what kind of move it is,
void	keyboard_control(mlx_key_data_t	keydata, void *param)
{
	t_map	*mp;
	int		x_new;
	int		y_new;

	mp = (t_map *)param;
	x_new = mp->player_location[1];
	y_new = mp->player_location[1];
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(mp->mlx);
		free_t_map(mp);
		return ;
	}
	else if (keydata.key == MLX_KEY_UP)
		y_new -= 1;
	else if (keydata.key == MLX_KEY_DOWN)
		y_new += 1;
	else if (keydata.key == MLX_KEY_LEFT)
		x_new -= 1;
	else if (keydata.key == MLX_KEY_RIGHT)
		x_new += 1;
	else
		return ;
	move(mp, x_new, y_new);
}

// a structruct by mlx42
/*
typedef struct s_mlx_key_data {
    keys_t  key;      // The key that was pressed (e.g. MLX_KEY_W, MLX_KEY_UP)
    action_t action;  // The action (press, release, repeat)
    mods_t  modifiers; // Modifier keys (Shift, Ctrl, etc.)
} mlx_key_data_t;

void *param
*/
