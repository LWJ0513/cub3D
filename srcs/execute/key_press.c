/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:35:42 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/15 16:14:45 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void press_ws(int keycode, t_data *d, char **map)
{
	if (keycode == KEY_W)
	{
		if (map[(int)(d->pos_y)][(int)(d->pos_x + d->dir_x * d->move_speed)] != '1')
			d->pos_x += d->dir_x * d->move_speed;
		if (map[(int)(d->pos_y + d->dir_y * d->move_speed)][(int)(d->pos_x)] != '1')
			d->pos_y += d->dir_y * d->move_speed;
	}
	if (keycode == KEY_S)
	{
		if (map[(int)(d->pos_y)][(int)(d->pos_x - d->dir_x * d->move_speed)] != '1')
			d->pos_x -= d->dir_x * d->move_speed;
		if (map[(int)(d->pos_y - d->dir_y * d->move_speed)][(int)(d->pos_x)] != '1')
			d->pos_y -= d->dir_y * d->move_speed;
	}
}

void press_ad(int keycode, t_data *d, char **map)
{
	if (keycode == KEY_A)
	{
		if (map[(int)(d->pos_y)][(int)(d->pos_x - d->plane_x * d->move_speed)] != '1')
			d->pos_x -= d->plane_x * d->move_speed;
		if (map[(int)(d->pos_y - d->plane_y * d->move_speed)][(int)(d->pos_x)] != '1')
			d->pos_y -= d->plane_y * d->move_speed;
	}
	if (keycode == KEY_D)
	{
		if (map[(int)(d->pos_y)][(int)(d->pos_x + d->plane_x * d->move_speed)] != '1')
			d->pos_x += d->plane_x * d->move_speed;
		if (map[(int)(d->pos_y + d->plane_y * d->move_speed)][(int)(d->pos_x)] != '1')
			d->pos_y += d->plane_y * d->move_speed;
	}
}

void press_arrow(int keycode, t_data *d)
{
	if (keycode == K_AR_L)
	{
		double olddir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(-d->rot_speed) - d->dir_y * sin(-d->rot_speed);
		d->dir_y = olddir_x * sin(-d->rot_speed) + d->dir_y * cos(-d->rot_speed);
		double oldplane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(-d->rot_speed) - d->plane_y * sin(-d->rot_speed);
		d->plane_y = oldplane_x * sin(-d->rot_speed) + d->plane_y * cos(-d->rot_speed);
	}
	if (keycode == K_AR_R)
	{
		double olddir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(d->rot_speed) - d->dir_y * sin(d->rot_speed);
		d->dir_y = olddir_x * sin(d->rot_speed) + d->dir_y * cos(d->rot_speed);
		double oldplane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(d->rot_speed) - d->plane_y * sin(d->rot_speed);
		d->plane_y = oldplane_x * sin(d->rot_speed) + d->plane_y * cos(d->rot_speed);
	}
}

int key_press(int keycode, t_data *data)
{
	press_ws(keycode, data, data->map);
	press_ad(keycode, data, data->map);
	press_arrow(keycode, data);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
