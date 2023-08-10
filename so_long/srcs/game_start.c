/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:12:35 by fduque-a          #+#    #+#             */
/*   Updated: 2023/08/10 01:33:58 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	func_render_map(t_game *game)
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
			mlx_put_image_to_window(game->screen.mlx, game->screen.win,
				curr_sprite.img, game->map->j * SIZE, game->map->i * SIZE);
			game->map->j++;
		}
		game->map->i++;
	}
}

void	func_load_sprites(t_game *game)
{
	game->sprite[W1].img = mlx_xpm_file_to_image(game->screen.mlx, WS,
			&game->sprite[W1].width, &game->sprite[W1].height);
	game->sprite[C1].img = mlx_xpm_file_to_image(game->screen.mlx, CS,
			&game->sprite[C1].width, &game->sprite[C1].height);
	game->sprite[E1].img = mlx_xpm_file_to_image(game->screen.mlx, ES,
			&game->sprite[E1].width, &game->sprite[E1].height);
	game->sprite[X1].img = mlx_xpm_file_to_image(game->screen.mlx, XS,
			&game->sprite[X1].width, &game->sprite[X1].height);
	game->sprite[P1].img = mlx_xpm_file_to_image(game->screen.mlx, PWS,
			&game->sprite[P1].width, &game->sprite[P1].height);
	game->sprite[P2].img = mlx_xpm_file_to_image(game->screen.mlx, PDS,
			&game->sprite[P2].width, &game->sprite[P2].height);
	game->sprite[P3].img = mlx_xpm_file_to_image(game->screen.mlx, PSS,
			&game->sprite[P3].width, &game->sprite[P3].height);
	game->sprite[P4].img = mlx_xpm_file_to_image(game->screen.mlx, PAS,
			&game->sprite[P4].width, &game->sprite[P4].height);
	game->sprite[M1].img = mlx_xpm_file_to_image(game->screen.mlx, MIX,
			&game->sprite[M1].width, &game->sprite[M1].height);
	if (!game->sprite[P4].img || !game->sprite[W1].img || !game->sprite[C1].img
		|| !game->sprite[E1].img || !game->sprite[X1].img
		|| !game->sprite[P1].img || !game->sprite[P2].img
		|| !game->sprite[P3].img || !game->sprite[M1].img)
		func_exit_error("mlx_xpm_file_to_image failed.", game);
}

void	func_init_game(t_game *game)
{
	game->screen.mlx = mlx_init();
	if (!game->screen.mlx)
		func_exit_error("mlx_init failed.", game);
	func_load_sprites(game);
	game->screen.win = mlx_new_window(game->screen.mlx,
			game->map->lenght * SIZE, game->map->rows * SIZE, "so_long");
	if (!game->screen.win)
		func_exit_error("mlx_new_window failed.", game);
	func_render_map(game);
}
