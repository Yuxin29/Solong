/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:27:54 by yuwu              #+#    #+#             */
/*   Updated: 2025/07/16 14:28:14 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_new_window(t_map *mp)
{
	int	win_w;
	int	win_h;

	win_w = mp->dimension[1] * IMGSIZE;
	win_h = mp->dimension[0] * IMGSIZE;
	mp->mlx = mlx_init(win_w, win_h, "so long", false);
	if (!mp->mlx)
		errmsg_and_exit("MLX initialization failed\n", mp);
}

void	texture_path(t_map *mp)
{
	mlx_texture_t	*png;

	png = mlx_load_png(SPACE);
	if (png)
		mp->tex->img_empty = mlx_texture_to_image(mp->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png(WALL);
	if (png)
		mp->tex->img_wall = mlx_texture_to_image(mp->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png(EXIT);
	if (png)
		mp->tex->img_exit = mlx_texture_to_image(mp->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png(PLAYER);
	if (png)
		mp->tex->img_player = mlx_texture_to_image(mp->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png(COLL);
	if (png)
		mp->tex->img_collectable = mlx_texture_to_image(mp->mlx, png);
	mlx_delete_texture(png);
	if (!mp->tex->img_empty || !mp->tex->img_wall || !mp->tex->img_exit
		|| !mp->tex->img_player || !mp->tex->img_collectable)
		errmsg_and_exit("Image loading failed\n", mp);
}

void	init_background(t_map *mp)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < mp->dimension[0])
	{
		y = i * IMGSIZE;
		j = 0;
		while (j < mp->dimension[1])
		{
			x = j * IMGSIZE;
			mlx_image_to_window(mp->mlx, mp->tex->img_empty, x, y);
			j++;
		}
		i++;
	}
}

static void	init_character(t_map *mp, int i, int j)
{
	int	x;
	int	y;

	y = i * IMGSIZE;
	x = j * IMGSIZE;
	if (mp->arr_2d[i][j] == '1')
		mlx_image_to_window(mp->mlx, mp->tex->img_wall, x, y);
	else if (mp->arr_2d[i][j] == 'C')
		mlx_image_to_window(mp->mlx, mp->tex->img_collectable, x, y);
	else if (mp->arr_2d[i][j] == 'E')
		mlx_image_to_window(mp->mlx, mp->tex->img_exit, x, y);
	else if (mp->arr_2d[i][j] == 'P')
	{
		mlx_image_to_window(mp->mlx, mp->tex->img_player, x, y);
		mp->player_inst = mp->tex->img_player;
	}
}

void	init_instances(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (i < mp->dimension[0])
	{
		j = 0;
		while (j < mp->dimension[1])
		{
			init_character(mp, i, j);
			j++;
		}
		i++;
	}
}
