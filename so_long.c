
#include "so_long.h"

void	initialis(t_game *gam)
{
	int	i;

	gam->map_x = ft_strlen(gam->map[0]);
	gam->map_y = 0;
	gam->c = 0;
	while (gam->map[gam->map_y])
		gam->map_y++;
	gam->imag_1 = mlx_xpm_file_to_image(gam->mlx, "./image/imag_1.xpm", &i, &i);
	gam->imag_2 = mlx_xpm_file_to_image(gam->mlx, "./image/imag_2.xpm", &i, &i);
	gam->imag_3 = mlx_xpm_file_to_image(gam->mlx, "./image/imag_3.xpm", &i, &i);
	gam->imag_4 = mlx_xpm_file_to_image(gam->mlx, "./image/imag_4.xpm", &i, &i);
	gam->imag_5 = mlx_xpm_file_to_image(gam->mlx, "./image/imag_5.xpm", &i, &i);
	if (!gam->imag_1 || !gam->imag_2
		|| !gam->imag_3 || !gam->imag_4 || !gam->imag_5)
		ft_print_error(-7);
}

int	destroy_window(t_game *gam)
{
	mlx_destroy_window(gam->mlx, gam->win);
	exit(1);
	return (0);
}

void	calcule_items(t_game *gam)
{
	int	y;
	int	x;

	y = 0;
	gam->c = 0;
	gam->mov = 1;
	while (gam->map[y])
	{
		x = 0;
		while (gam->map[y][x])
		{
			if (gam->map[y][x] == 'C')
				(gam->c)++;
			x++;
		}
		y++;
	}
}

void	map(t_game *gam)
{
	gam->mlx = mlx_init();
	initialis(gam);
	gam->win = mlx_new_window
		(gam->mlx, 50 * (gam->map_x), 50 * (gam->map_y), "so_long");
	calcule_items(gam);
	update_window(gam);
	mlx_hook(gam->win, 2, 0, move_player, gam);
	mlx_hook(gam->win, 17, 0, &destroy_window, gam);
	mlx_loop(gam->mlx);
}
