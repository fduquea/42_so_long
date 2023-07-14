/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:30:29 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/14 17:00:05 by fduque-a         ###   ########.fr       */
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

// check that the file extension is .ber 
//and that the file exists and can be read from
// the map file is on map->file
// the map fd is saved on map->fd
void	func_check_file(t_game *game, char *file)
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
		func_exit_error("Error, file extension is not .ber.\n", game);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		func_exit_error("Error, file does not exist or cannot be read from.\n", game);
	close(fd);
}
