/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:47:18 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/08 21:48:59 by wonlim           ###   ########.fr       */
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
	int texX = (int)(v.wallX * (double)img->width);

	// 플레이어 시선이 위쪽이면 만약 비율이 0.2일 경우 제대로 좌에서 우로 갈 수록 증가하는데
	// 위에서 아래를 보면 0.8인 부분을 0.2 라 생각하기 때문에 texX를 빼줘야 한다.
	if (direction == NO || direction == EA)
		texX = img->width - texX ;

	// 화면 픽셀당 텍스처 좌표를 얼마만큼 증가시킬지
	double step = 1.0 * img->height / v.lineHeight;

	// todo y 시작 텍스처 좌표
	double texPos = (v.drawStart - HEI / 2 + v.lineHeight / 2) * step;

	for (int y = v.drawStart; y < v.drawEnd; y++)
	{
		// 텍스처 좌표를 정수로 변환하고 오버플로우의 경우 (texHeight - 1)로 마스크합니다.
		int texY = (int)texPos & (img->height - 1);
		texPos += step;

		int color = img->buffer[img->height * texY + texX];

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
		double cameraX = 2 * x / (double)WID - 1;			  // 카메라 평면 범위 변경 (-1 ~ 1)
		double rayDirX = d->dir_x + d->plane_x * cameraX; // 광선의 방향 벡터
		double raydir_y = d->dir_y + d->plane_y * cameraX; // 광선의 방향 벡터

		int mapX = (int)d->pos_x; // 플레이어(광선)의 위치
		int mapY = (int)d->pos_y; // 플레이어(광선)의 위치

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / raydir_y);

		double sideDistX, sideDistY;

		// x, y가 어느 방향으로 이동하는지(광선의 방향)
		// -1 또는 +1 의 값을 가진다.
		int stepX, stepY;

		/*
		stepX, stepY
		광선의 방향이 음수 x 성분을 가지면, `stepX = -1`, 광선의 방향이 양수 x 성분을 가지면 `stepX = 1`.
		만약 x 성분이 0이면, stepX 값은 사용되지 않으므로 어떤 값이든 상관없다.
		y 도 동일하게 처리한다.
		*/

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (d->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - d->pos_x) * deltaDistX;
		}
		if (raydir_y < 0)
		{
			stepY = -1;
			sideDistY = (d->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - d->pos_y) * deltaDistY;
		}

		// 나중에 광선의 길이를 계산하는 데 사용되는 변수
		double perpWallDist;

		int hit = 0; // 현재 루프를 종료할지 여부를 결정하는 데 사용되는 변수
		int side;	 // 벽의 x면 또는 y면이 맞았는지를 나타내는 변수 (x = 0 , y = 1)

		/*
		광선이 벽에 도달하면 루프가 종료된다.

		sideDistX, sideDistY
		각 이동 방향마다 deltaDist만큼 증가한다.

		mapX, mapY
		각각 stepX와 stepY만큼 증가한다.

		그 시점에서 "side" 변수에는 벽의 x면 또는 y면이 맞았는지 여부가 저장되며, mapX와 mapY에는 어떤 벽이 맞았는지에 대한 정보가 저장된다.
		그러나 벽이 정확히 어디에서 맞았는지는 알 수 없지만, 현재는 텍스처된 벽을 사용하지 않기 때문에 이 정보는 필요하지 않습니다.
		*/
		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// Check if ray has hit a wall
			if (d->map[mapY][mapX] == '1')
				hit = 1;
		}

		// 카메라 방향에 투영된 거리를 계산. This is the shortest distance from the point where the wall is
		// hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		// This can be computed as (mapX - pos_x + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		// for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		// because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		// steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		// Calculate height of line to draw on screen
		int lineHeight = (int)(HEI / perpWallDist);

		// calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + HEI / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEI / 2;
		if (drawEnd >= HEI)
			drawEnd = HEI - 1;

		// ray가 부딫힌 벽 실제 좌표
		double wallX;

		if (side == 0)
			wallX = d->pos_y + perpWallDist * raydir_y;
		else
			wallX = d->pos_x + perpWallDist * rayDirX;
		wallX -= floor(wallX);


		t_var var;
		var.wallX = wallX;
		var.side = side;
		var.rayDirX = rayDirX;
		var.rayDirY = raydir_y;
		var.lineHeight= lineHeight;
		var.drawStart=drawStart;
		var.drawEnd = drawEnd;

		if (side == 0 && rayDirX > 0) // 서
			draw_wall(WE, var, &d->images[WE], d, x);
		else if (side == 1 && raydir_y < 0) // 남
			draw_wall(SO, var, &d->images[SO], d, x);
		else if (side == 0 && rayDirX <= 0) // 동
			draw_wall(EA, var, &d->images[EA], d, x);
		else // 북
			draw_wall(NO, var, &d->images[NO], d, x);
		x++;
	}
	/*
	int x;
	t_var v;

	x = 0;
	while (x < WID)
	{
		set_value(d, &v, x);
		set_value2(d, &v);
		dda(d, &v);
		get_wall_area(d, &v);
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
	*/
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
