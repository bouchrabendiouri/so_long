
#include "so_long.h"

void	ft_print_error(int i)
{
	if (i == -1)
		write (1, "Error\nnew_line\n", 15);
	else if (i == -2)
		write (1, "Error\nn'est pas entoure par 1\n", 31);
	else if (i == -3)
		write (1, "Error\ncheker les element de la carte\n", 38);
	else if (i == -4)
		write (1, "Error\nla carte n'est pas rectangulaire\n", 40);
	else if (i == -5)
		write (1, "Error\nles argumment n'egale pas a 2 ou *.ber\n", 46);
	else if (i == -6)
		write (1, "Error\nfile !\n", 7);
	else if (i == -7)
		write (1, "Error\nimage\n", 13);
	else if (i == -8)
		write (1, "Error\nun des element est bloquer\n", 6);
	else if (i == -8)
		write (1, "Error\nprobleme d'allocation\n", 6);
	exit (1);
}

void	init(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->found_player = 0;
	game->found_door = 0;
	game->found_item = 0;
	game->found_other = 0;
	game->width = ft_strlen(game->map[0]);
	game->visited = (char **)malloc(sizeof(char *) * game->height);
	if (!game->visited)
		ft_print_error(-9);
	while (i < game->height)
	{
		j = 0;
		game->visited[i] = (char *)malloc(game->width);
		while (j < game->width)
		{
			game->visited[i][j] = '0';
			++j;
		}
		++i;
	}
}

void	fun_eleme(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		game->found_player++;
	else if (game->map[i][j] == 'E')
		game->found_door++;
	else if (game->map[i][j] == 'C')
		game->found_item = 1;
	else if (game->map[i][j] != '0' && game->map[i][j] != '1')
		game->found_other++;
}

int	ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (-1);
	i--;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.' && str[i - 4] && str[i - 4] != '/')
		return (0);
	return (-1);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		fd;
	char	*p;
	int		i;

	i = 0;
	if (ac != 2 || ber(av[1]) == -1)
		ft_print_error(-5);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_print_error(-6);
	p = get_next_line(fd);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_print_error(-9);
	game->map = ft_split(p, '\n');
	game->height = 0;
	while (game->map[i++])
		++game->height;
	init(game);
	check_map(game, p);
	game->map = ft_split(p, '\n');
	map(game);
	return (0);
}
