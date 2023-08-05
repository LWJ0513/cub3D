/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:32:19 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/06 04:36:38 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void set_value(t_data *d, t_var *v, int x)
{
	v->camera_x = 2 * x / (double)d->width - 1;
	v->raydir_x = d->dir_x + d->plane_x * v->camera_x;
	v->raydir_y = d->dir_y + d->plane_y * v->camera_x;

	v->map_x = (int)d->pos_x;
	v->map_y = (int)d->pos_y;

	v->delta_x = fabs(1 / v->raydir_x);
	v->delta_y = fabs(1 / v->raydir_y);
}

void set_value2(t_data *d, t_var *v)
{
	if (v->raydir_x < 0)
	{
		v->step_x = -1;
		v->side_x = (d->pos_x - v->map_x) * v->delta_x;
	}
	else
	{
		v->step_x = 1;
		v->side_x = (v->map_x + 1.0 - d->pos_x) * v->delta_x;
	}
	if (v->raydir_y < 0)
	{
		v->step_y = -1;
		v->side_y = (d->pos_y - v->map_y) * v->delta_y;
	}
	else
	{
		v->step_y = 1;
		v->side_y = (v->map_y + 1.0 - d->pos_y) * v->delta_y;
	}
}

void dda(t_data *d, t_var *v)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (v->side_x < v->side_y)
		{
			v->side_x += v->delta_x;
			v->map_x += v->step_x;
			v->side = 0;
		}
		else
		{
			v->side_y += v->delta_y;
			v->map_y += v->step_y;
			v->side = 1;
		}
		if (d->map[v->map_y][v->map_x] > 0)
			hit = 1;
	}
	if (v->side == 0)
		v->euclidean = (v->side_x - v->delta_x);
	else
		v->euclidean = (v->side_y - v->delta_y);
}

void get_wall_area(t_data *d, t_var *v)
{
	int wall_height;

	wall_height = (int)(d->height / v->euclidean);
	v->draw_start = -wall_height / 2 + d->height / 2;
	if (v->draw_start < 0)
		v->draw_start = 0;
	v->draw_end = wall_height / 2 + d->height / 2;
	if (v->draw_end >= d->height)
		v->draw_end = d->height - 1;
}

void print_wall(t_data *data, t_var *v, int x)
{
	int y;

	int color = 0x0000FF; // 파

	// todo 벽 동서남북 구분해서 이미지를 출력해야 함
	if (v->side == 1)
		color = color / 2;

	y = v->draw_start;
	while (y <= v->draw_end)
	{
		data->image.buffer[x + y * data->width] = color;
		y++;
	}
}
