/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:52:12 by fduque-a          #+#    #+#             */
/*   Updated: 2023/08/07 16:30:42 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_tile();

void	render_move(t_game *game)
{
	mlx_put_image_to_window(game->screen.mlx,game->screen.win, game->sprite[W1].img, game->next.x * SIZE, game->next.y * SIZE);	
	if (game->map->map_tiles[game->curr.y][game->curr.x] == '0')
		mlx_put_image_to_window(game->screen.mlx,game->screen.win, game->sprite[E1].img, game->curr.x * SIZE, game->curr.y * SIZE);
	else if (game->map->map_tiles[game->curr.y][game->curr.x] == 'C')
		mlx_put_image_to_window(game->screen.mlx,game->screen.win, game->sprite[C1].img, game->curr.x * SIZE, game->curr.y * SIZE);
	else if (game->map->map_tiles[game->curr.y][game->curr.x] == 'E')
		mlx_put_image_to_window(game->screen.mlx,game->screen.win, game->sprite[E1].img, game->curr.x * SIZE, game->curr.y * SIZE);
}

// check if move is possible and update window
void	func_keypressed(t_game *game, int x, int y)
{
	if (game->map->map_tiles[y][x] == '1')
		return ;
	ft_printf("Move count: %d\n", game->moves);
	game->moves++;
	if (game->map->map_tiles[y][x] == 'C')
	{
		game->map->map_tiles[y][x] = '0';
		game->map->c--;
	}
	if (game->map->map_tiles[y][x] == 'E' && game->map->c == 0)
		func_quit_game(game);
	if (game->map->map_tiles[y][x] == 'E')
		ft_printf("Add cool missing colectables message here\n");
	game->map->map_tiles[game->map->p_y][game->map->p_x] = '0';
	game->map->p_x = x;
	game->map->p_y = y;
	game->map->map_tiles[y][x] = 'P';
	game->curr = (t_point){game->map->p_y, game->map->p_x};
	game->next = (t_point){y, x};
	render_move(game);
}

int	func_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		func_quit_game(game);
	else if (keycode == W)
		func_keypressed(game, game->map->p_x, game->map->p_y - 1);
	else if (keycode == S)
		func_keypressed(game, game->map->p_x, game->map->p_y + 1);
	else if (keycode == A)
		func_keypressed(game, game->map->p_x - 1, game->map->p_y);
	else if (keycode == D)
		func_keypressed(game, game->map->p_x + 1, game->map->p_y);

	// if (!game)
	// 	return (0);
		
	// if (keycode == ESC)
	// 	func_quit_request(game);
	// else if (keycode == W)
	// 	ft_printf("W pressed\n");
	// else if (keycode == S)
	// 	ft_printf("S pressed\n");
	// else if (keycode == A)
	// 	ft_printf("A pressed\n");
	// else if (keycode == D)
	// 	ft_printf("D pressed\n");
	
	// printf("Key pressed: %d\n", keycode);
	
	return (0);
}
