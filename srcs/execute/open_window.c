/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:47:18 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/16 19:22:48 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	paint_cf(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WID)
	{
		j = 0;
		while (j < HEI / 2)
		{
			data->image.buffer[i + j * WID] = data->ceil_color;
			data->image.buffer[i + (j + HEI / 2) * WID] = data->floor_color;
			j++;
		}
		i++;
	}
}

void	calc(t_data *d)
{
	int		x;
	t_var	v;

	x = 0;
	while (x < WID)
	{
		set_value(d, &v, x);
		set_value2(d, &v);
		dda(d, &v);
		get_wall_area(&v);
		if (v.side == 0 && v.raydir_x > 0)
			draw_wall(WE, v, d, x);
		else if (v.side == 1 && v.raydir_y < 0)
			draw_wall(SO, v, d, x);
		else if (v.side == 0 && v.raydir_x <= 0)
			draw_wall(EA, v, d, x);
		else
			draw_wall(NO, v, d, x);
		x++;
	}
}

int	main_loop(t_data *data)
{
	paint_cf(data);
	calc(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (0);
}

void	open_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WID, HEI, "cub3D");
	data->image.img = mlx_new_image(data->mlx, WID, HEI);
	data->image.buffer = (int *)mlx_get_data_addr(data->image.img, \
												&data->image.bits_per_pixel, \
												&data->image.size_line, \
												&data->image.endian);
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);
	mlx_loop(data->mlx);
}
