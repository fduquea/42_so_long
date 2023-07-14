/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:12:35 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/14 15:40:18 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	func_render_sprites(t_game *game)
// {
	
// }

// void	func_render_map (t_game *game)
// {
	
// }

// void	func_load_sprites(t_game *game)
// {
	
// }

void	func_init_game(t_game *game)
{
	game->screen.mlx = mlx_init();
	if (!game->screen.mlx)
		func_exit_error("mlx_init failed.", game);
	game->screen.win = mlx_new_window(game->screen.mlx, game->map->lenght * SIZE, game->map->rows * SIZE, "so_long");
	if (!game->screen.win)
		func_exit_error("mlx_new_window failed.", game);
}
