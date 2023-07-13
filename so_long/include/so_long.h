/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:55:58 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/13 17:33:50 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft_curr/include/libft.h"

typedef struct s_map
{
	int		e;
	int		c;
	int		p;
	int		lenght;
	int		rows;
	char	*file;
	char	**map_tiles;
	int		p_x;
	int		p_y;
	int		i;
	int		j;
}	t_map;

// check file
int	func_check_file(t_map *map);
// read map
int	func_read_map(t_map *map);
// check map
int	func_check_map(t_map *map);
// uitls
int	flood_fill(t_map *map, int x, int y, char **path);

#endif
