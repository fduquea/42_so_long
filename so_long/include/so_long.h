/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:55:58 by fduque-a          #+#    #+#             */
/*   Updated: 2023/08/10 09:35:56 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft_curr/include/libft.h"

# define SIZE	32
# define WS		"assets/textures/wall.xpm"
# define ES		"assets/textures/empty.xpm"
# define CS		"assets/textures/coin.xpm"
# define XS		"assets/textures/exit.xpm"
# define PWS	"assets/textures/player1.xpm"
# define PDS	"assets/textures/player2.xpm"
# define PSS	"assets/textures/player3.xpm"
# define PAS	"assets/textures/player4.xpm"
# define MIX	"assets/textures/mix.xpm"

typedef enum e_key
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307,
}				t_key;

typedef enum e_index
{
	W1,
	E1,
	C1,
	X1,
	P1,
	P2,
	P3,
	P4,
	M1,
}					t_id;

typedef struct s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
}					t_graphics;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}					t_sprite;

typedef struct s_map
{
	int		e;
	int		c;
	int		p;
	int		lenght;
	int		rows;
	char	**map_tiles;
	int		p_x;
	int		p_y;
	int		i;
	int		j;
}					t_map;

typedef struct s_game
{
	t_map		*map;
	t_point		curr;
	t_point		next;
	t_graphics	screen;
	t_sprite	sprite[9];
	int			moves;
	int			exit;
}					t_game;

// check file
void	func_check_file(char *file);
// read map
void	func_read_map(t_game *game, char *file);
// check map
void	func_check_map(t_game *game);
// uitls
int		flood_fill(t_map *map, int x, int y, char **path);
// error and clean stuff
void	func_clear_game(t_game *so_long);
void	func_quit_game(t_game *so_long);
void	func_exit_error(char *message, t_game *game);
// init game
void	func_init_game(t_game *game);

int		func_keypress(int keycode, t_game *game);

int		func_quit_request(t_game *game);

int		func_get_rows(char *file);

#endif
