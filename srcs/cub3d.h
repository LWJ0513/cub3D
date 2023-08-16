/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonlim <wonlim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:16:45 by wonlim            #+#    #+#             */
/*   Updated: 2023/08/16 19:15:16 by wonlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WID 640
# define HEI 480
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

# define X_EVENT_KEY_PRESS 2
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define K_ARROW_LEFT 123
# define K_ARROW_RIGHT 124
# define KEY_ESC 53

typedef struct s_image
{
	int		width;
	int		height;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
	int		*buffer;
	void	*img;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_image	*images;
	int		*rgb_ceil_color;
	int		*rgb_floor_color;
	int		ceil_color;
	int		floor_color;
	char	direction;
	int		width;
	int		height;
	char	**map;

	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	t_image	image;
}	t_data;

typedef struct s_parsing
{
	char	*file_path;
	int		fd;
	int		identifier_count;
	int		*identifier_list;
	int		is_empty;
	char	*start_line;
	char	**image_path;
}	t_parsing;

typedef struct s_var
{
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;

	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;

	int		side;
	double	perp_wall_dist;
	int		wall_height;
	int		draw_start;
	int		draw_end;

	double	wall_x;
	double	step;
}	t_var;

// error
void	ft_error(char *msg);
void	ft_free(char **list);
int		is_two_word(char *line);
int		is_three_word(char *line);

// parsing
void	arg_n_init(int argc, char **argv, t_data *data, t_parsing *parse);
void	check_direction(t_data *data, char dir);
void	parsing(int argc, char **argv, t_data *data, t_parsing *parse);

// init_data
int		check_file(char *file, t_parsing *parse);
int		init_parse(t_parsing *parse);
void	init_data(t_data *data);
int		alloc_data(t_data *data, t_parsing *parse);

// check_identifier
int		check_image(t_data *data, t_parsing *parse);
int		check_identifier(t_data *data, t_parsing *parse);

// validate_map
int		validate_map(t_data *data, t_parsing *parsing);

// set_map
int		set_map(t_data *data, t_parsing *parse);

// execute
void	open_window(t_data *data);
int		key_press(int keycode, t_data *data);

void	set_value(t_data *d, t_var *v, int x);
void	set_value2(t_data *d, t_var *v);
void	dda(t_data *d, t_var *v);
void	get_wall_area(t_var *v);
void	print_wall(t_data *d, t_var *v, int x);
void	draw_wall(int direction, t_var v, t_data *d, int x);

#endif