/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:30:29 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/13 17:25:40 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// check that the file extension is .ber 
//and that the file exists and can be read from
// the map file is on map->file
// the map fd is saved on map->fd
int	func_check_file(t_map *map)
{
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	while (map->file[i])
	{
		if (map->file[i] == '.')
			j = i;
		i++;
	}
	if (ft_strncmp(map->file + j, ".ber", 4) != 0)
	{
		ft_printf("Error, file extension is not .ber.\n");
		return (1);
	}
	fd = open(map->file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, file does not exist or cannot be read from.\n");
		return (1);
	}
	close(fd);
	return (0);
}
