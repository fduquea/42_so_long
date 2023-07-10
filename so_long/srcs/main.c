/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:38:52 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/10 18:15:25 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position

The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.
The map must be rectangular.
The map must be closed/surrounded by walls. If it’s not, the program must return
an error.
You have to check if there’s a valid path in the map to all collectables and the exit
You must be able to parse any kind of map, as long as it respects the above rules.
• Another example of a minimal .ber map:
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111.
*/
void func_check_map(t_map_file **map)
{
	char 		*line;
	int			i;

	i = 1;
	line = get_next_line((*map)->fd);
	(*map)->file[0] = line;
	while (line)
	{
		free(line);
		line = get_next_line((*map)->fd);
		(*map)->file[i] = line;
		(*map)->file_check[i] = line;
		i++;
	}
	free(line);
	if (func_square_check(&map) == 0 || func_char_check(map) == 0 || func_minimum_check(&map) == 0 || func_closed_check(map) == 0 || func_path_check(&map) == 0)
	{
		printf("Error, map is not valid.\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_map_file	*map;

	if (argc == 2)
	{
		map = malloc(sizeof(t_map_file));
		if (ft_strnrcmp(argv[1], ".ber", 4) == 0)
		{
			map->fd = open(argv[1], O_RDONLY);
			if (map->fd == -1)
			{
				printf("Error, map doesn't exist\n");
				exit(0);
			}
			map->file = malloc(sizeof(char *) * 1000);
        	map->file_check = malloc(sizeof(char *) * 1000);
			if (!map->file || !map->file_check)
            	return (0);
			func_check_map(&map);
//			func_game(map);
			close(map->fd);
			ft_printf("Map %s: Good map.\n", argv[1]);
			int i = 0;
			while (map->file[i])
			{
				ft_printf("%s\n", map->file[i]);
				i++;
			}
			return (0);
		}
		else
			printf("Wrong map extension. Usage: ./so_long [map.ber]\n");
	}
	else
		printf("Usage: ./so_long [map.ber]\n");
	return (0);
}
