/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:12:35 by fduque-a          #+#    #+#             */
/*   Updated: 2023/08/07 13:13:05 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	func_render_map (t_game *game)
{
	t_sprite	curr_sprite;

    game->map->i = 0;
	while (game->map->i < game->map->rows)
	{
		game->map->j = 0;
		while (game->map->j < game->map->lenght)
		{
			if (game->map->map_tiles[game->map->i][game->map->j] == '1')
				curr_sprite = game->sprite[W1];
			else if (game->map->map_tiles[game->map->i][game->map->j] == '0')
				curr_sprite = game->sprite[E1];
			else if (game->map->map_tiles[game->map->i][game->map->j] == 'C')
				curr_sprite = game->sprite[C1];
			else if (game->map->map_tiles[game->map->i][game->map->j] == 'E')
				curr_sprite = game->sprite[X1];
			else if (game->map->map_tiles[game->map->i][game->map->j] == 'P')
				curr_sprite = game->sprite[P1];
			mlx_put_image_to_window(game->screen.mlx, game->screen.win, curr_sprite.img, game->map->j * SIZE, game->map->i * SIZE);
			game->map->j++;
		}
		game->map->i++;
	}
}

void	func_load_sprites(t_game *game)
{
	game->sprite[W1].img = mlx_xpm_file_to_image(game->screen.mlx, "assets/img/wall.xpm", &game->sprite[W1].width, &game->sprite[W1].height);
	if (!game->sprite[W1].img)
		func_exit_error("mlx_xpm_file_to_image failed. wall", game);
	game->sprite[C1].img = mlx_xpm_file_to_image(game->screen.mlx, "assets/img/coin.xpm", &game->sprite[C1].width, &game->sprite[C1].height);
	if (!game->sprite[C1].img)
		func_exit_error("mlx_xpm_file_to_image failed. coin", game);
	game->sprite[E1].img = mlx_xpm_file_to_image(game->screen.mlx, "assets/img/empty.xpm", &game->sprite[E1].width, &game->sprite[E1].height);
	if (!game->sprite[E1].img)
		func_exit_error("mlx_xpm_file_to_image failed. empty", game);
	game->sprite[X1].img = mlx_xpm_file_to_image(game->screen.mlx, "assets/img/exit.xpm", &game->sprite[X1].width, &game->sprite[X1].height);
	if (!game->sprite[X1].img)
		func_exit_error("mlx_xpm_file_to_image failed. exit", game);
	game->sprite[P1].img = mlx_xpm_file_to_image(game->screen.mlx, "assets/img/player.xpm", &game->sprite[P1].width, &game->sprite[P1].height);
	if (!game->sprite[P1].img)
		func_exit_error("mlx_xpm_file_to_image failed. player", game);
}

void	func_init_game(t_game *game)
{
	game->screen.mlx = mlx_init();
	if (!game->screen.mlx)
		func_exit_error("mlx_init failed.", game);
	func_load_sprites(game);
	game->screen.win = mlx_new_window(game->screen.mlx, game->map->lenght * SIZE, game->map->rows * SIZE, "so_long");
	if (!game->screen.win)
		func_exit_error("mlx_new_window failed.", game);
	func_render_map(game);
}
