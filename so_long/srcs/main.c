/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:38:52 by fduque-a          #+#    #+#             */
/*   Updated: 2023/08/10 01:16:09 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	func_quit_request(t_game *game)
{
	ft_printf("You gave up!\n");
	func_quit_game(game);
	return (0);
}

// all the game
void	func_game(char *file)
{
	t_map	map;
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.map = &map;
	func_read_map(&game, file);
	func_check_map(&game);
	func_init_game(&game);
	mlx_hook(game.screen.win, 2, 1L << 0, func_keypress, &game);
	mlx_hook(game.screen.win, 17, 0, func_quit_request, &game);
	mlx_loop(game.screen.mlx);
	func_quit_game(&game);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		func_check_file(argv[1]);
		func_game(argv[1]);
	}
	else
		printf("Usage: ./so_long [map.ber]\n");
	return (0);
}
