/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:38:52 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/13 17:29:19 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// all the game
void	func_game(char *file)
{
	t_map	map;

	map.file = ft_strdup(file);
	if (func_check_file(&map) == 1 || func_read_map(&map) == 1)
		return ;
	if (func_check_map(&map) == 1)
		return ;
	ft_printf("Map is valid\n");
	ft_split_free(map.map_tiles);
	free(map.file);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		func_game(argv[1]);
	else
		printf("Usage: ./so_long [map.ber]\n");
	return (0);
}
