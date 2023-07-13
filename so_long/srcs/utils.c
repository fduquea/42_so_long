/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:09:34 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/13 17:25:05 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to check if all collectables (C) are 
// accessible by the player and not surrounded by walls
int	flood_fill(t_map *map, int y, int x, char **path)
{
	static int	coins = 0;
	static int	exit = 0;

	if (path[y][x] == '1')
		return (0);
	else if (path[y][x] == 'C')
		coins++;
	else if (path[y][x] == 'E')
		exit = 1;
	path[y][x] = '1';
	flood_fill(map, y + 1, x, path);
	flood_fill(map, y - 1, x, path);
	flood_fill(map, y, x + 1, path);
	flood_fill(map, y, x - 1, path);
	if (coins == map->c && exit == 1)
		return (1);
	else
		return (0);
}
