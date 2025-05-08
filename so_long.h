

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_game
{
	int		x;
	int		y;
	int		height;
	int		width;
	char	**map;
	char	**visited;
	void	*mlx;
	int		map_y;
	int		map_x;
	void	*win;
	void	*imag_1;
	void	*imag_2;
	void	*imag_3;
	void	*imag_4;
	void	*imag_5;
	void	*imag_6;
	int		player_x;
	int		player_y;
	int		*exit_x;
	int		*exit_y;
	int		found_player;
	int		found_door;
	int		found_item;
	int		found_other;
	int		c;
	int		i;
	int		j;
	int		mov;

}	t_game;

void	check_door(t_game *game, int key, int x, int y);
void	position_p(t_game *gam);
int		move_player(int key, t_game *gam);
char	**ft_split(const char *s, char c);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	initialis(t_game *gam);
void	ft_print_error(int i);
void	map(t_game *gam);
void	update_window(t_game *gam);
void	check_map(t_game *game, char *p);
void	fun_eleme(t_game *game, int i, int j);
void	init(t_game *game);
void	flood_fill(t_game *game, int x, int y, int *c_e);
void	flood_fill2(t_game *game, int x, int y, int *is_valid_path);
void	calcule_items(t_game *gam);
void	ft_putnbr(int n);
void	check_items(t_game *game);

#endif
