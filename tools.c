

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y, int *c_e)
{
	if (game->map[y][x] == '1' || game->visited[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		c_e[0] += 1;
	if (game->map[y][x] == 'E')
		c_e[1] += 1;
	game->visited[y][x] = '1';
	flood_fill(game, x + 1, y, c_e);
	flood_fill(game, x - 1, y, c_e);
	flood_fill(game, x, y + 1, c_e);
	flood_fill(game, x, y - 1, c_e);
}

void	flood_fill2(t_game *game, int x, int y, int *is_valid_path)
{
	if (game->map[y][x] == '1' || game->visited[y][x] == '1'
		|| game->map[y][x] == 'E')
		return ;
	if (game->map[y][x] == 'P')
	{
		*is_valid_path = 1;
		return ;
	}
	game->visited[y][x] = '1';
	flood_fill2(game, x + 1, y, is_valid_path);
	flood_fill2(game, x - 1, y, is_valid_path);
	flood_fill2(game, x, y + 1, is_valid_path);
	flood_fill2(game, x, y - 1, is_valid_path);
}

void	init_visited(t_game *game, int *is_valid_path)
{
	int	y;
	int	x;

	y = 0;
	*is_valid_path = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			game->visited[y][x] = '0';
			++x;
		}
		++y;
	}
}

void	check_items_helper(t_game *game, int x, int y, int *cnt)
{
	int	is_valid_path;

	is_valid_path = 0;
	init_visited(game, &is_valid_path);
	flood_fill2(game, x, y, &is_valid_path);
	if (is_valid_path)
		++(*cnt);
}

void	check_items(t_game *game)
{
	int	y;
	int	x;
	int	cnt;

	y = 0;
	cnt = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				check_items_helper(game, x, y, &cnt);
			++x;
		}
		++y;
	}
	if (cnt != game->c)
		ft_print_error(-8);
}
