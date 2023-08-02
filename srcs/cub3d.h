/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:16:45 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/03 03:50:36 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define X_EVENT_KEY_PRESS 2
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

typedef struct s_image
{
	int width;
	int heigth;
	int line_length;
	int bpp;
	int endian;
	int *addr;
	void *img;
} t_image;

typedef struct s_data
{
	void *mlx;
	void *win;
	t_image *images;
	int ceil_color;
	int floor_color;
	char direction;
	int width;
	int height;
	char **map;

	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double move_speed;
	double rot_speed;
} t_data;

typedef struct s_var
{
	double camera_x;	 // 카메라 평면
	double raydir_x; // 광선의 방향 벡터
	double raydir_y; // 광선의 방향 벡터
	int map_x;
	int map_y;
	double side_x;
	double side_y;
	double delta_x;
	double delta_y;
	int step_x;	// x, y가 어느 방향으로 이동하는지(광선의 방향) -1 또는 +1
	int step_y;

	int side;// 벽의 x면 또는 y면이 맞았는지를 나타내는 변수 (x = 0 , y = 1)
	double euclidean;
	int draw_start;
	int draw_end
} t_var;


// 구현부
void open_window(t_data *data);
int key_press(int keycode, t_data *data);

void set_value(t_data *d, t_var *v, int x);
void set_value2(t_data *d, t_var *v, int x);
void dda(t_data *d, t_var *v);
void get_wall_area(t_data *d, t_var *v);
void print_wall(t_data *d, t_var *v, int x);

#endif