/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:55:58 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/10 17:25:26 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft_curr/include/libft.h"

typedef struct s_map_file
{
	int		e;
	int		c;
	int		p;
	int		lenght;
	int		height;
	int		fd;
	char	**file;
	char	**file_check;
	int		p_x;
	int		p_y;
}	t_map_file;

// map_checks
int		func_square_check(t_map_file **map);
int		func_closed_check(t_map_file *map);
int		func_path_check(t_map_file **map);
int		func_minimum_check(t_map_file **map);
int		func_char_check(t_map_file *map);

// utils
void	find_p_pos(t_map_file **map);
int		flood_fill(t_map_file **map, int x, int y);

#endif
