/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:52:12 by fduque-a          #+#    #+#             */
/*   Updated: 2023/08/10 11:05:41 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_move_2(t_game *game)
{
	if (game->exit == 2)
	{
		mlx_put_image_to_window(game->screen.mlx, game->screen.win,
			game->sprite[X1].img, game->curr.y * SIZE, game->curr.x * SIZE);
		game->exit = 0;
	}
	else
		mlx_put_image_to_window(game->screen.mlx, game->screen.win,
			game->sprite[E1].img, game->curr.y * SIZE, game->curr.x * SIZE);
	if (game->exit == 1)
		game->exit = 2;
}

void	render_move_1(t_game *game, char c)
{
	if (game->exit == 1)
		mlx_put_image_to_window(game->screen.mlx, game->screen.win,
			game->sprite[M1].img, game->next.y * SIZE, game->next.x * SIZE);
	else if (c == 'W')
		mlx_put_image_to_window(game->screen.mlx, game->screen.win,
			game->sprite[P1].img, game->next.y * SIZE, game->next.x * SIZE);
	else if (c == 'D')
		mlx_put_image_to_window(game->screen.mlx, game->screen.win,
			game->sprite[P2].img, game->next.y * SIZE, game->next.x * SIZE);
	else if (c == 'S')
		mlx_put_image_to_window(game->screen.mlx, game->screen.win,
			game->sprite[P3].img, game->next.y * SIZE, game->next.x * SIZE);
	else if (c == 'A')
		mlx_put_image_to_window(game->screen.mlx, game->screen.win,
			game->sprite[P4].img, game->next.y * SIZE, game->next.x * SIZE);
}

// check if move is possible and update window
void	func_keypressed(t_game *game, int x, int y, char c)
{
	if (game->map->map_tiles[y][x] == '1')
		return ;
	if (game->map->map_tiles[y][x] == 'E' && game->map->c == 0)
		func_quit_game(game);
	game->moves++;
	ft_printf("Move count: %d\n", game->moves);
	if (game->map->map_tiles[y][x] == 'C')
		game->map->c--;
	else if (game->map->map_tiles[y][x] == 'E')
		game->exit = 1;
	if (game->exit == 2)
		game->map->map_tiles[game->map->p_y][game->map->p_x] = 'E';
	else
		game->map->map_tiles[game->map->p_y][game->map->p_x] = '0';
	game->map->map_tiles[y][x] = 'P';
	game->curr = (t_point){game->map->p_y, game->map->p_x};
	game->next = (t_point){y, x};
	game->map->p_x = x;
	game->map->p_y = y;
	render_move_1(game, c);
	render_move_2(game);
}

int	func_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		ft_printf("You gave up!\n");
		func_quit_game(game);
	}
	else if (keycode == W)
		func_keypressed(game, game->map->p_x, game->map->p_y - 1, 'W');
	else if (keycode == S)
		func_keypressed(game, game->map->p_x, game->map->p_y + 1, 'S');
	else if (keycode == A)
		func_keypressed(game, game->map->p_x - 1, game->map->p_y, 'A');
	else if (keycode == D)
		func_keypressed(game, game->map->p_x + 1, game->map->p_y, 'D');
	return (0);
}
