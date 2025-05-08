
#include "so_long.h"

int	check_new_line(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] == '\n' || str[len - 1] == '\n')
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	is_map_surrounded(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((i == 0 || j == game->width - 1 || j == 0
					|| i == game->height - 1) && game->map[i][j] != '1')
			{
				return (-2);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			fun_eleme(game, i, j);
			j++;
		}
		i++;
	}
	if (game->found_player != 1 || game->found_door != 1
		|| !game->found_item || game->found_other != 0)
		return (-3);
	return (0);
}

int	is_rectangular_map(t_game *game)
{
	int	i;
	int	j;

	i = ft_strlen(game->map[0]);
	j = 1;
	while (game->map[j])
	{
		if (i != ft_strlen(game->map[j]))
			return (-4);
		j++;
	}
	return (0);
}

void	check_map(t_game *game, char *p)
{
	int	c_e[2];
	int	i;

	c_e[0] = 0;
	c_e[1] = 0;
	i = 0;
	if (check_new_line(p) < 0)
		ft_print_error(-1);
	if (is_rectangular_map(game) < 0)
		ft_print_error(-4);
	if (is_map_surrounded(game) < 0)
		ft_print_error(-2);
	if (check_map_elements(game) < 0)
		ft_print_error(-3);
	position_p(game);
	calcule_items(game);
	flood_fill(game, game->x, game->y, c_e);
	if (c_e[0] != game->c || c_e[1] != 1)
		ft_print_error(-8);
	check_items(game);
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}
