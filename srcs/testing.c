/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:38:52 by fduque-a          #+#    #+#             */
/*   Updated: 2023/07/08 19:02:16 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int 	i = 0;
	int		j = 1;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 100;
	int z = 100;
	int color = 0x000000FF;
	while (z <= 800)
	{
		while (x <= 800)
		{
			while(i < 100)
			{
				j = 0;
				while (j < 100)
				{
					my_mlx_pixel_put(&img, x + i, z + j, color);
					j++;
				}
				i++;
			}
			i = 0;
			j = 0;
			x += 100;
			if (color == 0x000000FF)
				color = 0x00FF0000;
			else
				color = 0x000000FF;
		}
		if (color == 0x000000FF)
			color = 0x00FF0000;
		else
			color = 0x000000FF;
		z += 100;
		x = 100;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	free(mlx);
}
