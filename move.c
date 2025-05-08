
#include "so_long.h"

void	p_move(t_game *gam, int x, int y)
{
	ft_putnbr(gam->mov++);
	write(1, "\n", 1);
	if (gam->map[y][x - 1] == 'C')
		gam->c--;
	gam->map[y][x] = '0';
	gam->map[y][x - 1] = 'P';
	update_window(gam);
}

void	d_move(t_game *gam, int x, int y)
{
	ft_putnbr(gam->mov++);
	write(1, "\n", 1);
	if (gam->map[y][x + 1] == 'C')
		gam->c--;
	gam->map[y][x] = '0';
	gam->map[y][x + 1] = 'P';
	update_window(gam);
}

void	t_move(t_game *gam, int x, int y)
{
	ft_putnbr(gam->mov++);
	write(1, "\n", 1);
	if (gam->map[y + 1][x] == 'C')
		gam->c--;
	gam->map[y][x] = '0';
	gam->map[y + 1][x] = 'P';
	update_window(gam);
}

void	q_move(t_game *gam, int x, int y)
{
	ft_putnbr(gam->mov++);
	write(1, "\n", 1);
	if (gam->map[y - 1][x] == 'C')
		gam->c--;
	gam->map[y][x] = '0';
	gam->map[y - 1][x] = 'P';
	update_window(gam);
}

int	move_player(int key, t_game *gam)
{
	int	x;
	int	y;

	position_p(gam);
	x = gam->x;
	y = gam->y;
	if (key == 53)
		exit (0);
	if (key == 125 || key == 126 || key == 124 || key == 123)
		check_door(gam, key, x, y);
	if (key == 126 && gam->map[y - 1][x] != '1' && gam->map[y - 1][x] != 'E')
		q_move(gam, x, y);
	if (key == 125 && gam->map[y + 1][x] != '1' && gam->map[y + 1][x] != 'E')
		t_move(gam, x, y);
	if (key == 124 && gam->map[y][x + 1] != '1' && gam->map[y][x + 1] != 'E')
		d_move(gam, x, y);
	if (key == 123 && gam->map[y][x - 1] != '1' && gam->map[y][x - 1] != 'E')
		p_move(gam, x, y);
	return (0);
}
