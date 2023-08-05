/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:47:18 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/06 04:36:58 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void paint_cf(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->height / 2)
		{
			data->image.buffer[i + j * data->width] = *data->ceil_color;
			data->image.buffer[i + (j + data->height / 2) * data->width] = *data->floor_color;

			j++;
		}
		i++;
	}
}

void calc(t_data *d)
{
	int x;
	t_var v;

	x = 0;
	while (x < d->width)
	{
		set_value(d, &v, x);
		set_value2(d, &v);

		dda(d, &v);

		get_wall_area(d, &v);
		print_wall(d, &v, x);

		x++;
	}
}

int main_loop(t_data *data)
{
	paint_cf(data);
	calc(data);

	return (0);
}

void open_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3D");

	data->image.img = mlx_new_image(data->mlx, data->width, data->height);
	data->image.buffer = (int *)mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel, &data->image.size_line, &data->image.endian);

	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);

	mlx_loop(data->mlx);
}
