/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:47:57 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/13 17:39:00 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Check if there is a valid path to
// all collectables and the exit (C and E characters)
static int	func_path_check(t_map *map)
{
	char	**tiles;

	map->i = 0;
	tiles = ft_calloc(map->rows + 1, sizeof(char *));
	while (map->i < map->rows)
	{
		tiles[map->i] = ft_strdup(map->map_tiles[map->i]);
		{
			if (!tiles[map->i])
			{
				ft_split_free(tiles);
				return (1);
			}
		}
		map->i++;
	}
	if (flood_fill(map, map->p_y, map->p_x, tiles) == 0)
	{
		ft_printf("No valid path to all collectables and the exit\n");
		ft_split_free(tiles);
		return (1);
	}
	ft_split_free(tiles);
	return (0);
}

// Check if the map is closed by walls (1)
static int	func_closed_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_tiles[i])
	{
		j = 0;
		while (map->map_tiles[i][j])
		{
			if ((i == 0 || i == map->rows - 1) && map->map_tiles[i][j] != '1')
				return (1);
			if ((j == 0 || j == map->lenght - 1) && map->map_tiles[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Check if there is at least 1 exit, 1 collectible
// and 1 starting position, and only 1 exit and starting position
static int	func_minimum_check(t_map *map)
{
	map->i = 0;
	while (map->map_tiles[map->i])
	{
		map->j = 0;
		while (map->map_tiles[map->i][map->j])
		{
			if (map->map_tiles[map->i][map->j] == 'C')
				map->c++;
			if (map->map_tiles[map->i][map->j] == 'E')
				map->e++;
			if (map->map_tiles[map->i][map->j] == 'P')
			{
				map->p_y = map->i;
				map->p_x = map->j;
				map->p++;
			}
			map->j++;
		}
		map->i++;
	}
	if (map->c < 1 || map->e != 1 || map->p != 1)
		return (1);
	return (0);
}

// Check if the map is a square
// Check if only the 5 characters are present (0, 1, C, E, P)
static int	func_square_char_check(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map->map_tiles[i])
	{
		j = 0;
		while (map->map_tiles[i][j])
		{
			if (map->map_tiles[i][j] != '0' && map->map_tiles[i][j] != '1' &&
				map->map_tiles[i][j] != 'C' && map->map_tiles[i][j] != 'E' &&
				map->map_tiles[i][j] != 'P')
				return (0);
			j++;
		}
		if (ft_strlen(map->map_tiles[i]) != ft_strlen(map->map_tiles[i - 1]))
			return (1);
		i++;
	}
	return (0);
}

// The map can be composed of only these 5 characters:
// 0 for an empty space,
// 1 for a wall,
// C for a collectable,
// E for a map exit,
// P for the player’s starting position

// The map must contain 1 exit, at least 1
//  collectible, and 1 starting position to
// be valid.
// The map must be rectangular.
// The map must be closed/surrounded by walls.
//  If it’s not, the program must return
// an error.
// You have to check if there’s a valid path
//  in the map to all collectables and the exit
// You must be able to parse any kind of map,
//  as long as it respects the above rules.
// • Another example of a minimal .ber map:
// 1111111111111111111111111111111111
// 1E0000000000000C00000C000000000001
// 1010010100100000101001000000010101
// 1010010010101010001001000000010101
// 1P0000000C00C0000000000000000000C1
// 1111111111111111111111111111111111.
int	func_check_map(t_map *map)
{
	map->c = 0;
	map->e = 0;
	map->p = 0;
	if (func_square_char_check(map) == 1)
		return (1);
	if (func_minimum_check(map) == 1)
		return (1);
	if (func_closed_check(map) == 1)
		return (1);
	if (func_path_check(map) == 1)
		return (1);
	return (0);
}
