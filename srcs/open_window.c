/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:47:18 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/03 03:37:19 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			// todo 수정
			mlx_pixel_put(data->mlx, data->win, i, j, data->ceil_color);
			mlx_pixel_put(data->mlx, data->win, i, j + data->height / 2, data->floor_color);
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
		set_value2(d, &v, x);

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

	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);

	mlx_loop(data->mlx);
}
