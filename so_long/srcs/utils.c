/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:09:34 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/10 17:31:23 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_p_pos(t_map_file **map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)->file[i])
	{
		j = 0;
		while ((*map)->file[i][j])
		{
			if ((*map)->file[i][j] == 'P')
			{
				(*map)->p_x = i;
				(*map)->p_y = j;
				return ;
			}
		}
	}
	ft_printf("No starting position??\n");
}

// Function to check if all collectables are accessible by the player and not surrounded by walls
int	flood_fill(t_map_file **map, int x, int y)
{
	if ((*map)->file[x][y] == 'C')
	{
		if ((*map)->file_check[x][y] == 'C')
		{
			(*map)->file_check[x][y] = 'X';
			(*map)->c--;
		}
		return (1);
	}
	if ((*map)->file[x][y] == '1')
		return (0);
	if ((*map)->file[x][y] == 'E')
	{
		if ((*map)->file_check[x][y] == 'E')
		{
			(*map)->file_check[x][y] = 'X';
			(*map)->e--;
		}
		return (0);
	}
	if ((*map)->file[x][y] == '0' || (*map)->file[x][y] == 'C')
	{
		if (flood_fill(map, x + 1, y) == 1)
			return (1);
		if (flood_fill(map, x - 1, y) == 1)
			return (1);
		if (flood_fill(map, x, y + 1) == 1)
			return (1);
		if (flood_fill(map, x, y - 1) == 1)
			return (1);
	}
	if ((*map)->c == 0 && (*map)->e == 0)
	{
		return (0);
	}
	ft_printf("The player can't reach all collectables\n");
	exit(1);
}
