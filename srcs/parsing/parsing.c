/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:30:40 by sooyang           #+#    #+#             */
/*   Updated: 2023/08/17 13:56:05 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	arg_n_init(int argc, char **argv, t_data *data, t_parsing *parse)
{
	if (argc != 2)
		ft_error("invalid argument");
	if (!check_file(argv[1], parse))
		ft_error("fail open");
	if (!init_parse(parse))
		ft_error("fail init");
	init_data(data);
	if (!alloc_data(data, parse))
		ft_error("fail init");
}

void	check_direction(t_data *data, char dir)
{
	if (dir == 'E')
	{
		data->dir_x = 1;
		data->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		data->dir_x = -1;
		data->plane_x = -0.66;
	}
	else if (dir == 'S')
	{
		data->dir_y = 1;
		data->plane_x = -0.66;
	}
	else if (dir == 'N')
	{
		data->dir_y = -1;
		data->plane_x = 0.66;
	}
}

void	convert_color(t_data *data)
{
	int	ceil_color;
	int	floor_color;

	ceil_color = data->rgb_ceil_color[0] << 16 | data->rgb_ceil_color[1] << 8 | \
	data->rgb_ceil_color[2];
	floor_color = data->rgb_floor_color[0] << 16 | \
	data->rgb_floor_color[1] << 8 | data->rgb_floor_color[2];
	data->ceil_color = ceil_color;
	data->floor_color = floor_color;
}

void	parsing(int argc, char **argv, t_data *data, t_parsing *parse)
{
	arg_n_init(argc, argv, data, parse);
	if (!check_identifier(data, parse))
		ft_error("invalid identified");
	data->mlx = mlx_init();
	if (!check_image(data, parse))
		ft_error("fail to load images");
	if (!validate_map(data, parse))
		ft_error("fail to load map");
	if (!set_map(data, parse))
		ft_error("fail to set map");
	convert_color(data);
	ft_free_parse(parse);
}
