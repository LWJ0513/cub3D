/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:47:18 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/13 02:48:56 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void paint_cf(t_data *data)
{
	int i;
	int j;

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

void draw_wall(int direction, t_var v, t_image *img, t_data *d, int x)
{
	// 비율에 너비를 곱해서 실제 texture의 좌표를 구함
	int tex_x = (int)(v.wall_x * (double)img->width);

	// 플레이어 시선이 위쪽이면 만약 비율이 0.2일 경우 제대로 좌에서 우로 갈 수록 증가하는데
	// 위에서 아래를 보면 0.8인 부분을 0.2 라 생각하기 때문에 tex_x를 빼줘야 한다.
	if (direction == NO || direction == EA)
		tex_x = img->width - tex_x ;

	// 화면 픽셀당 텍스처 좌표를 얼마만큼 증가시킬지
	double step = 1.0 * img->height / v.wall_height;

	// todo y 시작 텍스처 좌표
	double tex_pos = (v.draw_start - HEI / 2 + v.wall_height / 2) * step;

	for (int y = v.draw_start; y < v.draw_end; y++)
	{
		// 텍스처 좌표를 정수로 변환하고 오버플로우의 경우 (texHeight - 1)로 마스크합니다.
		int tex_y = (int)tex_pos & (img->height - 1);
		tex_pos += step;

		int color = img->buffer[img->height * tex_y + tex_x];

		d->image.buffer[x + y * WID] = color;
		// d->re_buf = 1;
	}
}

void calc(t_data *d)
{
	int x;
	
	x = 0;

	while (x < WID)
	{
		double camera_x = 2 * x / (double)WID - 1;			  // 카메라 평면 범위 변경 (-1 ~ 1)
		double raydir_x = d->dir_x + d->plane_x * camera_x; // 광선의 방향 벡터
		double raydir_y = d->dir_y + d->plane_y * camera_x; // 광선의 방향 벡터

		int map_x = (int)d->pos_x; // 플레이어(광선)의 위치
		int map_y = (int)d->pos_y; // 플레이어(광선)의 위치

		double delta_dist_x = fabs(1 / raydir_x);
		double delta_dist_y = fabs(1 / raydir_y);

		double side_dist_x, side_dist_y;

		// x, y가 어느 방향으로 이동하는지(광선의 방향)
		// -1 또는 +1 의 값을 가진다.
		int step_x, step_y;

		if (raydir_x < 0)
		{
			step_x = -1;
			side_dist_x = (d->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - d->pos_x) * delta_dist_x;
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			side_dist_y = (d->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - d->pos_y) * delta_dist_y;
		}

		// 나중에 광선의 길이를 계산하는 데 사용되는 변수
		double perp_wall_dist;

		int hit = 0; // 현재 루프를 종료할지 여부를 결정하는 데 사용되는 변수
		int side;	 // 벽의 x면 또는 y면이 맞았는지를 나타내는 변수 (x = 0 , y = 1)

		
		while (hit == 0)
		{
		
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			
			if (d->map[map_y][map_x] == '1')
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		int wall_height = (int)(HEI / perp_wall_dist);

		
		int draw_start = -wall_height / 2 + HEI / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = wall_height / 2 + HEI / 2;
		if (draw_end >= HEI)
			draw_end = HEI - 1;

		
		double wall_x;

		if (side == 0)
			wall_x = d->pos_y + perp_wall_dist * raydir_y;
		else
			wall_x = d->pos_x + perp_wall_dist * raydir_x;
		wall_x -= floor(wall_x);


		t_var var;
		var.wall_x = wall_x;
		var.side = side;
		var.raydir_x = raydir_x;
		var.raydir_y = raydir_y;
		var.wall_height= wall_height;
		var.draw_start=draw_start;
		var.draw_end = draw_end;

		if (side == 0 && raydir_x > 0) // 서
			draw_wall(WE, var, &d->images[WE], d, x);
		else if (side == 1 && raydir_y < 0) // 남
			draw_wall(SO, var, &d->images[SO], d, x);
		else if (side == 0 && raydir_x <= 0) // 동
			draw_wall(EA, var, &d->images[EA], d, x);
		else // 북
			draw_wall(NO, var, &d->images[NO], d, x);
		x++;
	}
}

int main_loop(t_data *data)
{
	paint_cf(data);
	calc(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (0);
}

void open_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WID, HEI, "cub3D");
	data->image.img = mlx_new_image(data->mlx, WID, HEI);
	data->image.buffer = (int *)mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel, &data->image.size_line, &data->image.endian);
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);
	mlx_loop(data->mlx);
}
