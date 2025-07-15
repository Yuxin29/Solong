

#include "so_long.h"

/* ******player control and game processing-------player_move.c******************* */
void	keyboard_control(int	key, t_map mp);
{
	int	x;
	int	y;

	x = mp->player_locationp[1];
	y = mp->player_locationp[0];  //initial location of the play

	if (key == KEY_ESC)
		quit_by_player();
	if (key == KEY_UP  && mp->2d_arr[y - 1][x] != '1' )
		mp->player_locationp[0] -= 1;
	else if (key == KEY_DOWN && mp->2d_arr[y + 1][x] != '1'))
		mp->player_locationp[0] += 1;
	if (key == KEY_LEFT && mp->2d_arr[y][x - 1] != '1')
		mp->player_locationp[1] -= 1;
	else if (key == KEY_RIGHT && mp->2d_arr[y][x + 1] != '1')
		mp->player_locationp[1] += 1;
	map_collectable_refill(mp, x_new, y_new);
	finish_game_by_player(mp, x_new, y_new);
}

//the map should be changing with the player movement
void	map_collectable_refill(t_map mp, int x_new, int y_new)
{
	int	y = mp->player_location[0];
	int	x = mp->player_location[1];

	if (mp->2d_arr[y_new][x_new] == 'C')
	{
		mp->counterp[0]++;
		mp->2d_arr[y_new][x_new] = '0';
		//call print_collects(void)
	}
}

void	print_collects(void)
{
	//
}

//end game
void	finish_game_by_player(t_map mp, int x_new, int y_new)
{
	int	y = mp->player_location[0];
	int	x = mp->player_location[1];

	if (mp->2d_arr[y][x] == 'E' && mp->counterp[0] == mp->counterp[1])
		finish_game(mp);
}
