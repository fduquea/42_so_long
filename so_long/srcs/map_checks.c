/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:47:57 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/10 17:30:47 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Check if there is a valid path to all collectables and the exit (C and E characters)
int	func_path_check(t_map_file **map)
{
	int	ff;

	find_p_pos(map);
	ff = flood_fill(map, (*map)->p_x, (*map)->p_y);
	if (ff == 0)
	{
		ft_printf("No valid path to all collectables and the exit\n");
		return (0);
	}
	return (1);
}

// Check if the map is closed by walls (1)
int	func_closed_check(t_map_file *map)
{
	int	i;
	int	j;
	int	h;
	
	i = 0;
	h = 0;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if ((i == 0 || i == map->height - 1) && map->file[i][j] != 1)
                h = 1;
            if ((j == 0 || j == map->lenght - 1) && map->file[i][j] != 1)
                h = 1;
            j++;
		}
		i++;	
	}
	if (h == 1)
	{
		ft_printf("The map is not closed by walls\n");
		return (0);
	}
	return (1);
}

// Check if there is at least 1 exit, 1 collectible and 1 starting position, and only 1 exit and starting position
int	func_minimum_check(t_map_file **map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)->file[i])
	{
		j = 0;
		while ((*map)->file[i][j])
		{
			if ((*map)->file[i][j] == 'C')
				(*map)->c++;
			if ((*map)->file[i][j] == 'E')
				(*map)->e++;
			if ((*map)->file[i][j] == 'P')
				(*map)->p++;
			j++;
		}
		i++;
	}
	if ((*map)->c < 1 || (*map)->e != 1 || (*map)->p != 1)
	{
		ft_printf("There is not at least 1 exit, 1 collectible and 1 starting position\n");
		return (0);
	}
	return (1);
}

// Check if only the 5 characters are present (0, 1, C, E, P)
int	func_char_check(t_map_file *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != 0 && map->file[i][j] != 1 && map->file[i][j] != 'C' && map->file[i][j] != 'E' && map->file[i][j] != 'P')
			{
				ft_printf("There is at least one invalid character in the map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Check if the map is a square
int	func_square_check(t_map_file **map)
{
	size_t	i;

	i = 1;
	(*map)->lenght = ft_strlen((*map)->file[0]);
	while ((*map)->file[i])
	{
		if (ft_strlen((*map)->file[i]) != ft_strlen((*map)->file[i - 1]))
		{
			ft_printf("Map is not a square\n");
			return (0);
		}
		i++;
	}
	(*map)->height = i;
	(*map)->c = 0;
	(*map)->e = 0;
	(*map)->p = 0;
	return (1);
}
