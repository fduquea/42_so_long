/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:30:09 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/13 17:25:24 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**func_get_map(t_map *map)
{
	char	*line;
	char	**tiles;
	int		i;
	int		fd;

	fd = open(map->file, O_RDONLY);
	i = 0;
	tiles = malloc(sizeof(char *) * (map->rows + 1));
	if (!tiles)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		tiles[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	tiles[i] = NULL;
	close(fd);
	return (tiles);
}

static int	func_get_rows(t_map *map)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(map->file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

// read the map file and save it on map->map_tiles
int	func_read_map(t_map *map)
{
	int		rows;
	int		fd;

	fd = open(map->file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, file does not exist or cannot be read from.\n");
		return (1);
	}
	rows = func_get_rows(map);
	map->rows = rows;
	map->map_tiles = func_get_map(map);
	map->lenght = ft_strlen(map->map_tiles[0]);
	close(fd);
	return (0);
}
