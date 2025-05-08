
#include "so_long.h"

void	up_win(t_game *gam, int x, int y)
{
	if (gam->map[y][x] == '1')
		mlx_put_image_to_window
			(gam->mlx, gam->win, gam->imag_1, 50 * x, 50 * y);
	else if (gam->map[y][x] == '0')
		mlx_put_image_to_window
			(gam->mlx, gam->win, gam->imag_2, 50 * x, 50 * y);
	else if (gam->map[y][x] == 'P')
		mlx_put_image_to_window
			(gam->mlx, gam->win, gam->imag_3, 50 * x, 50 * y);
	else if (gam->map[y][x] == 'E')
		mlx_put_image_to_window
			(gam->mlx, gam->win, gam->imag_4, 50 * x, 50 * y);
	else if (gam->map[y][x] == 'C')
		mlx_put_image_to_window
			(gam->mlx, gam->win, gam->imag_5, 50 * x, 50 * y);
}

void	destroy_image(t_game *gam)
{
	mlx_destroy_image(gam->mlx, gam->win);
	exit(1);
}

void	check_door(t_game *gam, int key, int x, int y)
{
	if ((key == 125) && gam->map[y + 1][x] == 'E' && !gam->c)
		destroy_image(gam);
	if ((key == 126) && gam->map[y - 1][x] == 'E' && !gam->c)
		destroy_image(gam);
	if ((key == 124) && gam->map[y][x + 1] == 'E' && !gam->c)
		destroy_image(gam);
	if ((key == 123) && gam->map[y][x - 1] == 'E' && !gam->c)
		destroy_image(gam);
}

void	position_p(t_game *gam)
{
	int	i;
	int	j;

	i = 0;
	while (gam->map[i])
	{
		j = 0;
		while (gam->map[i][j])
		{
			if (gam->map[i][j] == 'P')
			{
				gam->x = j;
				gam->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	update_window(t_game *gam)
{
	int	x;
	int	y;

	y = 0;
	while (y < gam->map_y)
	{
		x = 0;
		while (x < gam->map_x)
		{
			up_win(gam, x, y);
			x++;
		}
		y++;
	}
}
