/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:30:29 by fduque-a          #+#    #+#             */
/*   Updated: 2023/08/10 00:45:11 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//error exits
void	func_exit_error(char *message, t_game *game)
{
	func_clear_game(game);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	func_simple_check(char *file)
{
	int		rows;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, file does not exist or cannot be read from.\n");
		exit(1);
	}
	rows = func_get_rows(file);
	if (rows < 3)
	{
		ft_printf("Error, map is too small.\n");
		exit(1);
	}
	close(fd);
}

// check that the file extension is .ber 
//and that the file exists and can be read from
// the map file is on map->file
// the map fd is saved on map->fd
void	func_check_file(char *file)
{
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i] == '.')
			j = i;
		i++;
	}
	if (ft_strncmp(file + j, ".ber", 4) != 0)
	{
		ft_printf("Error, file extension is not .ber.\n");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, file does not exist or cannot be read from.\n");
		exit(1);
	}
	close(fd);
	func_simple_check(file);
}
