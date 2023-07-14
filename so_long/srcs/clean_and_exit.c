/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:49:53 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/14 16:46:28 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	func_clean_tiles(char **tiles)
{
	size_t	i;

	i = 0;
	if (!tiles)
		return ;
	while (tiles[i])
		free (tiles[i++]);
	free (tiles);
}

static void	func_clean_map(t_map *map)
{
    if (!map)
        return ;
    if (map->map_tiles[0] != NULL)
        func_clean_tiles(map->map_tiles);
}

static void	func_clean_sprites(t_game *so_long)
{
	int	i;

	i = 0;
	while (i < 5) // 01EPC
	{
		mlx_destroy_image(so_long->screen.mlx, so_long->sprite[i].img);
		i++;
	}
	free (so_long->sprite);
}

void	func_clear_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
	{
		func_clean_map(so_long->map);
//		free(so_long->map);
	}
	if (so_long->sprite)
		func_clean_sprites(so_long);
	if (so_long->screen.win)
		mlx_destroy_window(so_long->screen.mlx, so_long->screen.win);
	if (so_long->screen.mlx)
		mlx_destroy_display(so_long->screen.mlx);
	free(so_long->screen.mlx);
}

void	func_quit_game(t_game *so_long)
{
	func_clear_game(so_long);
	exit(0);
}