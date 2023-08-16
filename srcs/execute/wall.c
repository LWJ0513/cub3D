/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:43:57 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/16 18:24:43 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_wall_area(t_var *v)
{
	v->wall_height = (int)(HEI / v->perp_wall_dist);
	v->draw_start = -(v->wall_height) / 2 + HEI / 2;
	if (v->draw_start < 0)
		v->draw_start = 0;
	v->draw_end = v->wall_height / 2 + HEI / 2;
	if (v->draw_end >= HEI)
		v->draw_end = HEI - 1;
}

double get_wall_x(t_var v, t_data *d)
{
	double wall_x;

	if (v.side == 0)
		wall_x = d->pos_y + v.perp_wall_dist * v.raydir_y;
	else
		wall_x = d->pos_x + v.perp_wall_dist * v.raydir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int get_tex_x(int direction, double wall_x, t_image texture)
{
	int tex_x;

	tex_x = (int)(wall_x * (double)texture.width);
	if (direction == NO || direction == EA)
		tex_x = texture.width - tex_x ;
	return (tex_x);
}

void draw_wall(int direction, t_var v, t_data *d, int x)
{
	t_image texture;
	int tex_x;
	double step;
	double tex_pos;
	int y;
	int tex_y;
	int color;

	texture = d->images[direction];
	tex_x = (int)get_tex_x(direction, get_wall_x(v, d), texture);

	step = 1.0 * texture.height / v.wall_height;
	tex_pos = (v.draw_start - HEI / 2 + v.wall_height / 2) * step;

	y = v.draw_start;
	while (y < v.draw_end)
	{
		tex_y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		color = texture.buffer[texture.height * tex_y + tex_x];
		d->image.buffer[x + y * WID] = color;
		y++;
	}
}
