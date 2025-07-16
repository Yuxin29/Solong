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

static void *mlx_ptr;
static void *win_ptr;
void mlx_new_window(t_map *mp)
{
    int win_w;
    int win_h;
    
    win_w = mp->dimension[1] * IMGSIZE;
    win_h = mp->dimension[0] * IMGSIZE;
    mlx_ptr = mlx_init();  //system call from minilibx
    if (!mlx_ptr)
        // handle error, I am not sure here, shoud I exit and free here as well
        errmsg_and_exit("MLX initialization failed", 1);
    win_ptr = mlx_new_window(mlx_ptr, win_w, win_h, "so_long");
    if (!win_ptr)
        errmsg_and_exit("Window creation failed", 1);
}

static void *img_wall;
static void *img_player;
static void *img_collectible;
static void *img_exit;
static void *space;
//load images here
void img_path(void)
{
    img_space = mlx_xpm_file_to_image(mlx_ptr, SPACE, IMGSIZE, IMGSIZE);
    img_wall = mlx_xpm_file_to_image(mlx_ptr, WALL, IMGSIZE, IMGSIZE);
    img_player = mlx_xpm_file_to_image(mlx_ptr, PLAYER, IMGSIZE, IMGSIZE);
    img_collectible = mlx_xpm_file_to_image(mlx_ptr, COLL, IMGSIZE, IMGSIZE);
    img_exit = mlx_xpm_file_to_image(mlx_ptr, EXIT, IMGSIZE, IMGSIZE);

    if (!img_wall || !img_player || !img_collectible || !img_exit || !img_floor)
        errmsg_and_exit("Failed to load images", 1);
}

//floodfill the map chars with the images here???
void fill_map(t_map *mp)
{
    int i;
    int j;
    int x;
    int y;

    x = j * IMGSIZE;
    y = i * IMGSIZE;
    i = 0;
    while (i < mp->dimension[0])
    {
        j = 0;
        while (j = 0; j < mp->dimension[1]; j++)
        {
            if (mp->2d_arr[i][j] == '0') // empty space
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_space, x, y);
            else if (mp->2d_arr[i][j] == '1')
                 mlx_put_image_to_window(mlx_ptr, win_ptr, img_wall, x, y);
            else if (mp->2d_arr[i][j] == 'C')
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_coll, x, y);
            else if (mp->2d_arr[i][j] == 'E')
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_exit, x, y);
            else if (mp->2d_arr[i][j] == 'P')
                 mlx_put_image_to_window(mlx_ptr, win_ptr, img_player, x, y);
            j++;
        }
        i++;
    }
}
