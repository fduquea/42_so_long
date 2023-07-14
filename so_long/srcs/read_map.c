/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:30:09 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/14 17:00:32 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**func_get_map(t_map *map, char *file)
{
	char	*line;
	char	**tiles;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
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

static int	func_get_rows(char *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
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
void	func_read_map(t_game *game, char *file)
{
	int		rows;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		func_exit_error("File does not exist or cannot be read from.\n", game);
	rows = func_get_rows(file);
	game->map->rows = rows;
	if (rows < 3)
		func_exit_error("Map. Invalid number of rows.\n", game);
	game->map->map_tiles = func_get_map(game->map, file);
	if (!game->map->map_tiles)
		func_exit_error("Map. Malloc error.\n", game);
	game->map->lenght = ft_strlen(game->map->map_tiles[0]);
	if (game->map->lenght < 3)
		func_exit_error("Map. Invalid number of columns.\n", game);
	close(fd);
}
