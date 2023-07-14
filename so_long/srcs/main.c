/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:38:52 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/14 16:52:45 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// all the game
void	func_game(char *file)
{
	t_map	map;
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.map = &map;
	func_check_file(&game, file); 
	func_read_map(&game, file);
	func_check_map(&game);
	func_init_game(&game);
	sleep(2);
	func_quit_game(&game);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		func_game(argv[1]);
	else
		printf("Usage: ./so_long [map.ber]\n");
	return (0);
}
