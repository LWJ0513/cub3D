/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:35:42 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/06 04:25:03 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// todo 벽 뚫리는 버그 
void press_ws(int keycode, t_data *d, char **map)
{
	if (keycode == KEY_W)
	{
		if (!map[(int)(d->pos_x + d->dir_x * d->move_speed)][(int)(d->pos_y)])
			d->pos_x += d->dir_x * d->move_speed;
		if (!map[(int)(d->pos_x)][(int)(d->pos_y + d->dir_y * d->move_speed)])
			d->pos_y += d->dir_y * d->move_speed;
	}
	if (keycode == KEY_S)
	{
		if (!map[(int)(d->pos_x - d->dir_x * d->move_speed)][(int)(d->pos_y)])
			d->pos_x -= d->dir_x * d->move_speed;
		if (!map[(int)(d->pos_x)][(int)(d->pos_y - d->dir_y * d->move_speed)])
			d->pos_y -= d->dir_y * d->move_speed;
	}
}

void press_ad(int keycode, t_data *d)
{
	if (keycode == KEY_A)
	{
		double olddir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(-d->rot_speed) - d->dir_y * sin(-d->rot_speed);
		d->dir_y = olddir_x * sin(-d->rot_speed) + d->dir_y * cos(-d->rot_speed);
		double oldplane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(-d->rot_speed) - d->plane_y * sin(-d->rot_speed);
		d->plane_y = oldplane_x * sin(-d->rot_speed) + d->plane_y * cos(-d->rot_speed);
	}
	if (keycode == KEY_D)
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
	press_ad(keycode, data);

	// todo free 안 해도 될지?
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
